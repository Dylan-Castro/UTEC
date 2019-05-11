#include <iostream>
#include "binary.h"
using namespace std;

int main(int argc, char *argv[]) {
    cout << "===========================================================" << endl;
    cout << "Binary Array Practice" << endl;
    cout << "===========================================================" << endl << endl;
    boolean booleano(8);
    for(int x=0;x<8;x++){
        booleano.bitOn(x);
    }
    booleano.bitOff(6);
    for(int x=7;x>=0;x--){
        cout << booleano[x];
    }
    cout << endl;
    booleano.clear();
    booleano.~boolean();
    system("pause");
    return EXIT_SUCCESS;
}

