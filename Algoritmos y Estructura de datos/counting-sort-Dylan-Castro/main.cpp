#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;
void print(int numbers[], int size);
void countingSort(int numbers[], int size);
int main(int argc, char *argv[]) {
    int numbers[] = {1, 4, 1, 2, 7, 5, 2};
    int size = sizeof(numbers) / sizeof(*numbers);

    print(numbers, size);
    countingSort(numbers, size);
    print(numbers, size);
    system("pause");
    return EXIT_SUCCESS;
}

void print(int numbers[], int size) {
    for (int i = 0; i < size; i++) {
        cout << numbers[i] << ' ';
    }
    cout << endl;
}

void countingSort(int numbers[], int size) {
    // TODO
    int mayor=numbers[0];
    int menor=numbers[0];
    int temp[size];
    //Se crea una matriz temporal con los datos de numbers, y se encuentran
    //el numero mayor y el menor
    for (int i = 0; i < size; i++) {
        temp[i]=numbers[i];
        if(numbers[i]>mayor){
            mayor=numbers[i];
        }
        if(numbers[i]<menor){
            menor=numbers[i];
        }
    }
    int index[mayor+1]={};
    //Cuenta cada elemento de la matriz numbers y guarda el nro de veces que aparece
    for (int i = 0; i < size; i++) {
        index[temp[i]]++;
    }
    //Se modifica el index sumando cada elemento con el elemento anterior(contador)
    int contador=0;
    for (int i = menor; i <= mayor; i++) {
        index[i]+=contador;
        contador=index[i];
    }
    //Regresa los datos ordenados a la matriz resultante
    for (int i = 0; i < size; i++) {
        numbers[index[temp[i]]-1]=temp[i];
        index[temp[i]]--;
    }
}
