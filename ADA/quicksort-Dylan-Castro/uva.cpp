#include <iostream>
#include <fstream>
#include <vector>
#include<stdlib.h>
#include<stdio.h>
#include <sys/time.h>
struct timeval start;
struct timeval finish;
using namespace std;
int contador=0;
void insertion_sort(int *arr,int size){
    int temp;
  for(int x=1;x<size;x++){
  for(int y=x;y>0;y--){
    if(arr[y-1]>arr[y]){
      temp=arr[y];
      arr[y]=arr[y-1];
      arr[y-1]=temp;
      contador++;
    }
  }
  }
}
int main(){
  int n,numbers;
  while(scanf("%d",&n))
    {
      if(n==0){
        break;
      }
      int *a = new int[n];
      for(int i=0; i<n; i++){
          scanf("%d",&numbers);
          a[i]=numbers;
      }
      //insertion_sort(a,a.size());
      insertion_sort(a,n);
      printf("%d\n",contador);
      contador=0;
      delete []a;
    }
  return 0;
}
