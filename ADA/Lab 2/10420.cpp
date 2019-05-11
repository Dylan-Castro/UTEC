#include <iostream>
#include <string>
#include <map>
using namespace std;
int main(){
  int cases;
  map<string,int> rpta;
  string country,name1,name2;
  cin >> cases;
  for (int i = 0; i < cases; i++) {
    cin >> country;
    cin >> name1;
    cin >> name2;
    rpta[country]++;
  }
  for (std::map<string,int>::iterator it=rpta.begin(); it!=rpta.end(); ++it)
   std::cout << it->first << " " << it->second << '\n';
}
