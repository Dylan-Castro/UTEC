#include <stdio.h>
#include <pthread.h>
#include "atomic_ops.h"
#include "hrtimer_x86.c"
#define Number_of_threads 2

double tiempo_inicial,tiempo_final;
pthread_t t[Number_of_threads];
int cuenta = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
volatile unsigned long lock_tas = 0;
volatile unsigned long tatas_lock = 0;
tatas_lock_t tatas_backoff_lock = 0;
ticket_lock_t ticket_lock;


void *t1(void *id) {
  for (int i = 0; i < 50000; i++) {
    cuenta++;
  }
}

void *t2(void *id) {
  for (int i = 0; i < 50000; i++) {
    pthread_mutex_lock(&lock);
      cuenta++;
    pthread_mutex_unlock(&lock);
  }
}

void *t3(void *id) {
  for (int i = 0; i < 50000; i++) {
    while (tas(&lock_tas) == 1);
    cuenta++;
    lock_tas = 0;
  }
}

void tatas_acquireLock(volatile unsigned long *lock) {
  do {
    while (*lock);
  } while (tas(lock));
}
void tatas_releaseLock(volatile unsigned long *lock) {
  *lock = false;
}
void *t4(void *id) {
  for (int i = 0; i < 50000; i++) {
    tatas_acquireLock(&tatas_lock);
    cuenta++;
    tatas_releaseLock(&tatas_lock);
  }
}

void *t5(void *id) {
  for (int i = 0; i < 50000; i++) {
    tatas_acquire(&tatas_backoff_lock);
    cuenta++;
    tatas_release(&tatas_backoff_lock);
  }
}

void *t6(void *id) {
  for (int i = 0; i < 50000; i++) {
    ticket_acquire(&ticket_lock);
    cuenta++;
    ticket_release(&ticket_lock);
  }
}

void create_threads(void *(*start_routine)(void *)) {
  for (int rank = 0; rank < Number_of_threads; rank++)
    pthread_create(&t[rank], NULL, start_routine, (void *) NULL);
  for (int rank = 0; rank < Number_of_threads; rank++)
    pthread_join(t[rank], NULL);
}

void Sin_ningun_tipo_de_sincronismo() {
  create_threads(t1);
}
void Con_pthreads_lock() {
  create_threads(t2);
}
void TAS() {
  create_threads(t3);
}
void TATAS() {
  create_threads(t4);
}
void TATAS_WITH_BACKOFF() {
  create_threads(t5);
}
void Ticket() {
  create_threads(t6);
}

int main() {
  tiempo_inicial=gethrtime_x86();
  Sin_ningun_tipo_de_sincronismo();
  tiempo_final=gethrtime_x86();
  printf("Sin_ningun_tipo_de_sincronismo(Time Sec): %f\n",tiempo_final-tiempo_inicial);
  printf("Cuenta: %d\n",cuenta);
  cuenta = 0;

  tiempo_inicial=gethrtime_x86();
  Con_pthreads_lock();
  tiempo_final=gethrtime_x86();
  printf("Con_pthreads_lock(Time Sec): %f\n",tiempo_final-tiempo_inicial);
  printf("Cuenta: %d\n",cuenta);
  cuenta = 0;

  tiempo_inicial=gethrtime_x86();
  TAS();
  tiempo_final=gethrtime_x86();
  printf("TAS(Time Sec): %f\n",tiempo_final-tiempo_inicial);
  printf("Cuenta: %d\n",cuenta);
  cuenta = 0;

  tiempo_inicial=gethrtime_x86();
  TATAS();
  tiempo_final=gethrtime_x86();
  printf("TATAS(Time Sec): %f\n",tiempo_final-tiempo_inicial);
  printf("Cuenta: %d\n",cuenta);
  cuenta = 0;

  tiempo_inicial=gethrtime_x86();
  TATAS_WITH_BACKOFF();
  tiempo_final=gethrtime_x86();
  printf("TATAS_WITH_BACKOFF(Time Sec): %f\n",tiempo_final-tiempo_inicial);
  printf("Cuenta: %d\n",cuenta);
  cuenta = 0;

  tiempo_inicial=gethrtime_x86();
  Ticket();
  tiempo_final=gethrtime_x86();
  printf("Ticket(Time Sec): %f\n",tiempo_final-tiempo_inicial);
  printf("Cuenta: %d\n",cuenta);
  cuenta = 0;

  return 0;

}
