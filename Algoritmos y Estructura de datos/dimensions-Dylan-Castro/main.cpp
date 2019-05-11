#include <cstdlib>
#include <iostream>

#include "vector.h"

using namespace std;

template <typename T>
struct Dimensions {
    int operator()(int* coordinates, int* sizes, int dimensions) {
        // TODO
        int aux=0,aux2=0;
        for(int x=0;x<dimensions;x++){
            aux=sizes[x];
            for(int y=x+1;y<dimensions;y++){
            aux*=coordinates[y];
            }
            aux2+=aux;
        }
        return aux2;
    }
};

struct Integer {
       typedef int T;
       typedef Dimensions<T> Operation;
};

int main(int argc, char *argv[]) {
    //Se establece el Nro de dimensiones
    //Se establece un vector que contiene el nro de dimensiones
    //Se establece un vector con las dimensiones de la coordenada
    int dimensions=2, *dimensionSizes=new int[2], *coordinates=new int[2];
    //Se establece en el vector la longitud de cada dimension
    dimensionSizes[0]=2;
    dimensionSizes[1]=2;
    Vector<Integer> vectors(dimensions,dimensionSizes);
    int aux=1;
    for(int x=0;x<dimensionSizes[0];x++){
        for(int y=0;y<dimensionSizes[1];y++){
            coordinates[0]=x;
            coordinates[1]=y;
            vectors.set(aux,coordinates);
            aux++;
            cout << vectors.get(coordinates) << endl;
        }
    }
    system("pause");
    return EXIT_SUCCESS;
}
