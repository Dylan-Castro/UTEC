#include<iostream>
using namespace std;
int cont=0;
void print_a(int* ar,int n){
    for(int i=0;i<n;i++){
        cout<<ar[i]<< " ";
    }
    cout<<endl;
}
void flip(int* ar,int i){
    int t=ar[i];
    ar[i]=ar[i+1];
    ar[i+1]=t;
    cont++;
}
void merge_flip(int* ar,int l,int m,int r){
    for(int i=m+1;i<=r;i++){
        int j=i-1,key=ar[i];
        while(ar[j]>key && j>=l){
            flip(ar,j);

            j--;
        }
    }
}
void flip_sort(int* ar,int l,int r){
    if(r>l){
        int m=(r+l)/2;
        flip_sort(ar,l,m);
        flip_sort(ar,m+1,r);
        merge_flip(ar,l,m,r);

    }
}
int main(){
    int N;
    int* arr;
    while(cin>>N){
        arr=new int[N];
        for(int i=0;i<N;i++){
            cin>>arr[i];
        }
        flip_sort(arr,0,N-1);
        cout<<cont<<endl;
        cont=0;
        delete [] arr;
    }
}
