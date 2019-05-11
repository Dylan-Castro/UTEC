#include <iostream>
#include <fstream>
using namespace std;
int main(){
  int v;
  int t;
  while(scanf("%d %d", &v, &t)!=EOF){
    cout << v*t*2 << endl;
  }
}
