#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int maximum(int a,int b, int c){
    return max(max(a,b),c);
}
int max_sum_sub_ar(vector<int> ar,int inicio,int fin){
    int sum=0;
    for(int x=inicio;x<fin;x++){
        sum+=ar[x];
    }
    return sum;
}
int max_sum_ar(vector<int> ar,int inicio,int fin){
    if(ar.size()==0){
        return 0;
    }
    if(inicio==fin){
        cout << inicio << fin << endl;
        return ar[inicio];
    }
    int mitad= (inicio+fin)/2;
    return maximum(max_sum_ar(ar,inicio,mitad),max_sum_ar(ar,mitad+1,fin),max_sum_sub_ar(ar,inicio,fin));
}
int main(){
    vector<int> ar;
    ar.push_back(1);
    ar.push_back(2);
    ar.push_back(-3);
    ar.push_back(4);
    ar.push_back(-5);
    cout << max_sum_ar(ar,0,ar.size());
}
