#include "iostream"
#include "fstream"
using namespace std;
int main(){
  int i;
  int j;
  while(scanf("%d %d", &i, &j)!=EOF){
    int contador=1;
  int aux=0;
  int rpta=0;
    for (int x = i; x <= j; x++) {
    aux=x;
    if(contador>rpta){
      rpta=contador;
    }
    contador = 1;
    while(aux!=1){
      if(aux%2!=0){
        aux=3*aux+1;
      }
      else{
        aux=aux/2;
      }
      contador++;
    }
  }
    cout << i << " " << j << " " << rpta << endl;
  }
}
