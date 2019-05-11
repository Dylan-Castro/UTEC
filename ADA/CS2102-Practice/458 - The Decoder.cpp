#include <iostream>
#include "fstream"
using namespace std;
int main() {
   char caracter;
	while(scanf("%c",&caracter) != EOF){
		if(caracter!='\n'){
            cout << char(caracter-7);
		}
		else{
            cout << endl;
		}
	}
}
