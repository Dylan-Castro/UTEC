#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
int num_of_threads = 2;
int row = 1000,col=1000;
int** A;
int** B;
int** C;

void *multiplicaction(void* id_arg){
  int id=(int)id_arg;
  double rows_per_thr = col/num_of_threads;
  double start = id*rows_per_thr;
  double final = (id+1)*rows_per_thr;
  //printf("hola\n");
  for(int i=start;i<final;i++){
   for(int j=0;j<col;j++){
    for(int k=0;k<row;k++){
      C[i][j] += A[i][k]*B[k][j];
    }
   }
  }
}
void create_matriz(){
  for(int i = 0; i < row; i++){
      for(int j = 0; j < col; j++){
       A[i][j]=rand() % 6;
      }
   }

  for(int i = 0; i < row; i++){
      for(int j= 0; j < col; j++){
         B[i][j]=rand() % 6;
       }
   }
}



int main(){
  struct timeval start;
  struct timeval finish;
  pthread_t t[num_of_threads];

  A = malloc(row*sizeof(int*));
      for(int i=0;i<row;i++)
        A[i]=malloc(col*sizeof(int));

  B = malloc(row*sizeof(int*));
      for(int i=0;i<row;i++)
        B[i]=malloc(col*sizeof(int));

  C =  malloc(row*sizeof(int*));
      for(int i=0;i<row;i++)
        C[i]=malloc(col*sizeof(int));

  create_matriz();
  gettimeofday(&start, 0);
  for (int rank = 0; rank < num_of_threads; rank++)
     pthread_create(&t[rank], NULL,multiplicaction , (void*)rank);
  for (int rank = 0; rank < num_of_threads; rank++)
      pthread_join(t[rank], NULL);
  gettimeofday(&finish, 0);
  free(A);
  free(B);
  free(C);
  printf("Application time: %f Secs\n",(double)(((finish.tv_sec - start.tv_sec) * 1000000)+(finish.tv_usec - start.tv_usec))/1000000.0);
  pthread_exit(NULL); 
  return 0;
}
