#include <iostream>
#include <string>
#include <map>
using namespace std;
int main(){
  string texto;
  cin >> texto;
  map<char,int> mapa;
  for(int x=0;x<texto.size();x++){
    if(mapa.count(texto[x])!=0){
      mapa[texto[x]]=mapa[texto[x]]+1;
    }
    else{
      if(texto[x]=='a' || texto[x]=='e' || texto[x]=='i' || texto[x]=='o' || texto[x]=='u' ){
          mapa[texto[x]]=1;
      }
    }
  }
  for (std::map<char,int>::iterator it=mapa.begin(); it!=mapa.end(); ++it)
<<<<<<< HEAD
    std::cout << it->first << " => " << it->second << '\n';
=======
      std::cout << it->first << " => " << it->second << '\n';

>>>>>>> vocales
}
