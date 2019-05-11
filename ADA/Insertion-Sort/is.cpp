#include<stdio.h>
#include<iostream>
using namespace std; 
int main() 
{ 
int arr[] = {10, 7, 8, 9, 1, 5}; 
int n = sizeof(arr)/sizeof(arr[0]);
int temp;
for(int x=1;x<n;x++){
	for(int y=x;y>0;y--){
		if(arr[y-1]>arr[y]){
			temp=arr[y];
			arr[y]=arr[y-1];
			arr[y-1]=temp;
		}
	}	   
} 
return 0; 
}
