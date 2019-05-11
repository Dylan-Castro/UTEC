#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
void *printHola(void *num_hilo){
	long t;
	t=(long)num_hilo;
	printf("Hola Mundo desde el hilo %ld \n",t);
	pthread_exit(NULL);
}
int main(){
int i,j,k,rc;
long long int t;
static int n_hilos=39447;
pthread_t hilos[n_hilos];
printf("Bienvenidos a hola \n");
for (t = 0; t < n_hilos; t++) {
  rc=pthread_create(&hilos[t],NULL,printHola,(void*)t);
  if(rc){
  printf("Error, codigo %d \n",rc);
  exit(-1);
  }
}
pthread_exit(NULL);
return 0;
}
