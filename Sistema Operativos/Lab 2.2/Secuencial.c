#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
int row = 1000,col=1000;
int** A;
int** B;
int** C;

int main(){
  struct timeval start;
  struct timeval finish;

  A = malloc(row*sizeof(int*));
      for(int i=0;i<row;i++)
        A[i]=malloc(col*sizeof(int));

  B = malloc(row*sizeof(int*));
      for(int i=0;i<row;i++)
        B[i]=malloc(col*sizeof(int));

  C =  malloc(row*sizeof(int*));
      for(int i=0;i<row;i++)
        C[i]=malloc(col*sizeof(int));
  
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

  gettimeofday(&start, 0);
  for(int i=0;i<row;i++){
   for(int j=0;j<col;j++){
    for(int k=0;k<row;k++){
      C[i][j] += A[i][k]*B[k][j];
    }
   }
  }
  gettimeofday(&finish, 0);
  printf("Application time: %f Secs\n",(double)(((finish.tv_sec - start.tv_sec) * 1000000)+(finish.tv_usec - start.tv_usec))/1000000.0);
  return 0;
}
