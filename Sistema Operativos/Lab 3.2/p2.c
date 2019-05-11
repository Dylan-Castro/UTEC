#include <stdio.h>
#include <pthread.h>
#include "hrtimer_x86.c"
#define Number_of_threads 2

typedef struct {
  int counter;
  pthread_mutex_t lock;
  int flag;
} bar_type;

bar_type bar_name = {
    0,
    PTHREAD_MUTEX_INITIALIZER,
    0
};

double tiempo_inicial, tiempo_final;
pthread_t t[Number_of_threads];
pthread_barrier_t barrier;
int local_sense = 0;

////////////////////////////////////////////////////////////////////////

void *Function_barrier(void *id) {
  pthread_barrier_wait(&barrier);
  pthread_exit(NULL);
}

void Reverse_sense_barrier(bar_type *bar_name, int p) {
  local_sense = !(local_sense);
  pthread_mutex_lock(&bar_name->lock);
  int mycount = bar_name->counter++;
  if (bar_name->counter == p) {
    pthread_mutex_unlock(&bar_name->lock);
    bar_name->counter = 0;
    bar_name->flag = local_sense;
  } else {
    pthread_mutex_unlock(&bar_name->lock);
    while (bar_name->flag != local_sense) {};
  }
}

void *Function_Reverse_barrier(void *id) {
  Reverse_sense_barrier(&bar_name, Number_of_threads);
  pthread_exit(NULL);
}

void Central_barrier(bar_type *bar_name, int p) {
  pthread_mutex_lock(&bar_name->lock);
  if (bar_name->counter == 0)
    bar_name->flag = 0;
  bar_name->counter++;
  int mycount = bar_name->counter;
  pthread_mutex_unlock(&bar_name->lock);
  if (mycount == p) {
    bar_name->counter = 0;
    bar_name->flag = 1;
  } else {
    while (bar_name->flag == 0) {};
  }
}

void *Function_Central_barrier(void *id) {
  Central_barrier(&bar_name, Number_of_threads);
  pthread_exit(NULL);
}
void create_threads(void *(*start_routine)(void *), int n_loops) {
  for (int i = 0; i < n_loops; ++i) {
    for (int rank = 0; rank < Number_of_threads; rank++)
      pthread_create(&t[rank], NULL, start_routine, (void *) NULL);
    for (int rank = 0; rank < Number_of_threads; rank++)
      pthread_join(t[rank], NULL);
  }
}

int main() {
  pthread_barrier_init(&barrier, NULL, Number_of_threads);
  int loops[4] = {10, 100, 1000, 10000};
  for (int i = 0; i < 4; i++) {
    tiempo_inicial = gethrtime_x86();
    create_threads(Function_barrier, loops[i]);
    tiempo_final = gethrtime_x86();
    printf("Barrier %d loops (Time Sec): %f\n", loops[i], tiempo_final - tiempo_inicial);

    /////////////////////////////////////////////////////////////////////////////////////////////

    tiempo_inicial = gethrtime_x86();
    create_threads(Function_Reverse_barrier, loops[i]);
    tiempo_final = gethrtime_x86();
    printf("Reverse Sense Barrier %d loops (Time Sec): %f\n", loops[i], tiempo_final - tiempo_inicial);

    /////////////////////////////////////////////////////////////////////////////////////////////

    tiempo_inicial = gethrtime_x86();
    create_threads(Function_Central_barrier, loops[i]);
    tiempo_final = gethrtime_x86();
    printf("Central Barrier(Classic) %d loops (Time Sec): %f\n\n\n", loops[i], tiempo_final - tiempo_inicial);

  }
  return 0;

}
