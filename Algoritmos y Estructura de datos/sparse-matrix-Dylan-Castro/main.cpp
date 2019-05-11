//#include <GL/glut.h>
#include <iostream>

#include "matrix.h"

using namespace std;

int main(int argc, char *argv[]) {
    Matrix<int> a(5, 5);
    Matrix<int> b(8, 8);
    b.set(2,2,5);
    b.set(1,2,20);
    a.set(0,0,5);
    a.set(1,0,10);
    a.set(2,0,7);
    a.set(3,0,11);
    a.set(4,0,15);
    a.set(0,4,8);
    //a=b;
    //a=a*7;
    //a=a*a;
    //a=a+b;
    //a=a-b;
    //a=a.transposed();
    a.print();
    system("PAUSE");
    return EXIT_SUCCESS;
}
