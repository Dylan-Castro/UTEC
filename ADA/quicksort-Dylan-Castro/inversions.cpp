#include <iostream>
#include <fstream>
#include <vector>
#include<stdlib.h>
#include<stdio.h>
#include <sys/time.h>
struct timeval start;
struct timeval finish;
using namespace std;
long long int contador=0;
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
void flip(int *arr, int i)
{
    int temp, start = 0;
    while (start < i) {
        temp = arr[start];
        arr[start] = arr[i];
        arr[i] = temp;
        start++;
        i--;
    }
}

/* Returns index of the maximum element in arr[0..n-1] */
int findMax(int *arr, int n)
{
    int mi, i;
    for (mi = 0, i = 0; i < n; ++i)
        if (arr[i] > arr[mi])
            mi = i;
    return mi;
}

int flipSort(int *arr, int n)
{
    for (int curr_size = n; curr_size > 1; --curr_size) {
        int mi = findMax(arr, curr_size);
        if (mi != curr_size - 1) {
            flip(arr, mi);
            flip(arr, curr_size - 1);
        }
    }
}
int main(){
  ifstream myfile;
  myfile.open ("numbers.txt");
  int *a = new int[100000];
  int *b = new int[100000];
  int temp;
  for (int i = 0; i < 100000; i++) {
    myfile >> temp;
    a[i]=temp;
    b[i]=temp;
  }
  myfile.close();
  gettimeofday(&start, 0);
  insertion_sort(a,100000);
  gettimeofday(&finish, 0);
  delete []a;
  printf("Application time of Insertion sort: %f Secs\n",(double)(((finish.tv_sec - start.tv_sec) * 1000000)+(finish.tv_usec - start.tv_usec))/1000000.0);
  gettimeofday(&start, 0);
  flipSort(b,100000);
  delete []b;
  gettimeofday(&finish, 0);
  printf("Application time of Flip Sort: %f Secs\n",(double)(((finish.tv_sec - start.tv_sec) * 1000000)+(finish.tv_usec - start.tv_usec))/1000000.0);
  cout << "Number of Swaps: " << contador << endl;
}
