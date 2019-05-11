#ifndef MATRIX_H
#define MATRIX_H
#include "node.h"
using namespace std;
template <typename T>
class Matrix {
    private:
        Node<T>* hRows;
        Node<T>* hColumns;
    public:
        int columns;
        int rows;
        Matrix(){
            hRows=nullptr;
            hColumns=nullptr;
            columns=0;
            rows=0;
        };
        Matrix(int sizeX, int sizeY){
            hRows=new Node<T>;
            hColumns= new Node<T>;
            Node<T>** tempx= &hRows;
            Node<T>** tempy= &hColumns;
            columns=sizeY;
            rows=sizeX;
            for(int x=1;x<rows;x++){
                tempx=&(*tempx)->down;
                *tempx=new Node<T>;
            }
            for(int y=1;y<columns;y++){
                tempy=&(*tempy)->next;
                *tempy=new Node<T>;
            }
        };
        void set(int x, int y, T data){
            Node<T>** fila= &hRows;
            Node<T>** columna= &hColumns;
            Node<T>** nodo_x_anterior;
            Node<T>** nodo_y_anterior;
            for(int i=0;i<x;i++){
                fila=&(*fila)->down;
            }
            columna=fila;
            do{
                nodo_y_anterior=columna;
                if((*columna)->next==nullptr){
                    break;
                }
                columna=&(*columna)->next;
            }
            while((*columna)->y < y);

            columna= &hColumns;
            for(int i=0;i<y;i++){
                columna=&(*columna)->next;
            }
            fila=columna;
            do{
                nodo_x_anterior=fila;
                if((*fila)->down==nullptr){
                    break;
                }
                fila=&(*fila)->down;
            }
            while((*fila)->x < x);

            if(data==0){
                if(this->operator()(x,y)==0){
                    return;
                }
                Node<T>* temp= (*nodo_x_anterior)->down;
                (*nodo_x_anterior)->down= (*nodo_x_anterior)->down->down;
                (*nodo_y_anterior)->next= (*nodo_y_anterior)->next->next;
                delete temp;
                return;
            }
            Node<T>* nodo=new Node<T>;
            nodo->set(x,y,data);
            nodo->next=(*nodo_y_anterior)->next;
            nodo->down=(*nodo_x_anterior)->down;
            (*nodo_y_anterior)->next=nodo;
            (*nodo_x_anterior)->down=nodo;
        };

        void print(){
            for(int x=0;x<rows;x++){
                for(int y=0;y<columns;y++){
                    cout << this->operator()(x,y) << " ";
                }
                cout << endl;
            }

        }
        T operator()(int x, int y){
            if(x > rows-1 || y > columns-1){
                cout << "Las dimensiones ingresadas no coinciden con la matrix :(" << endl;
                system("PAUSE");
                exit(true);
            }
            Node<T>** fila= &hRows;
            Node<T>** columna= &hColumns;
            for(int i=0;i<x;i++){
                fila=&(*fila)->down;
            }
            columna=fila;
            do{
                if((*columna)->next==nullptr){
                    break;
                }
                columna=&(*columna)->next;
            }
            while((*columna)->y < y);

            if((*columna)->y==y){
                return (*columna)->get();
            }
            else{
                return false;
            }
        };
        Matrix<T> operator*(Matrix<T> other){
            Matrix<int> c(rows,other.columns);
            int suma=0;
            for(int x=0;x<rows;x++){
                for(int y=0;y<other.columns;y++){
                    suma=0;
                    for(int z=0;z<columns;z++){
                        suma+=this->operator()(x,z)*other.operator()(z,y);
                    }
                    c.set(x,y,suma);

                }
            }
            return c;
        };
        Matrix<T> operator*(T scalar){
            Matrix<int> c(rows,columns);
            for(int x=0;x<rows;x++){
                for(int y=0;y<columns;y++){
                    if(this->operator()(x,y)!=0){
                        c.set(x,y,this->operator()(x,y)*scalar);
                    }
                }
            }
            return c;
        };
        Matrix<T> operator+(Matrix<T> other){
            if(this->rows != other.rows || this->columns != other.columns){
                cout << "Las dimensiones de las matrices son diferentes :(" << endl;
                system("PAUSE");
                exit(true);
            }
            Matrix<int> c(rows,columns);
            int suma=0;
            for(int x=0;x<rows;x++){
                for(int y=0;y<columns;y++){
                    if(this->operator()(x,y)!=0 || other.operator()(x,y)!=0){
                        c.set(x,y,this->operator()(x,y)+ other.operator()(x,y));
                    }
                }
            }
            return c;
        };
        Matrix<T> operator-(Matrix<T> other){
            if(this->rows != other.rows || this->columns != other.columns){
                cout << "Las dimensiones de las matrices son diferentes :(" << endl;
                system("PAUSE");
                exit(true);
            }
            Matrix<int> c(rows,columns);
            int resta=0;
            for(int x=0;x<rows;x++){
                for(int y=0;y<columns;y++){
                    if(this->operator()(x,y)!=0 || other.operator()(x,y)!=0){
                        c.set(x,y,this->operator()(x,y) - other.operator()(x,y));
                    }
                }
            }
            return c;
        };
        Matrix<T> transposed(){
            Matrix<T> c(rows,columns);
            for(int x=0;x<rows;x++){
                for(int y=0;y<columns;y++){
                    if(this->operator()(x,y)!=0){
                        c.set(y,x,this->operator()(x,y));
                    }
                }
            }
            return c;
        };
        void Resize_matrix(int x,int y){
            Node<T>* pointer= hColumns;
            Node<T>* temp;
            for(int j=0;j<y;j++){
                pointer=pointer->next;
                if(pointer->next==nullptr){
                    break;
                }
            }
            if(columns>y){
                for(int j=y;j<columns;j++){
                    pointer=pointer->next;
                    temp=pointer;
                    delete temp;
                }
            }
            else{
                for(int j=columns;j<y;j++){
                    pointer->next = new Node<T>;
                    pointer=pointer->next;
                }
            }
            pointer= hRows;
            temp=nullptr;
            for(int i=0;i<x;i++){
                pointer=pointer->down;
                if(pointer->down==nullptr){
                    break;
                }
            }
            if(rows>x){
                for(int i=x;i<rows;i++){
                    pointer=pointer->down;
                    temp=pointer;
                    delete temp;
                }
            }
            else{
                for(int i=rows;i<x;i++){
                    pointer->down = new Node<T>;
                    pointer = pointer->down;
                }
            }
        };
        Matrix<T> operator=(Matrix<T> other){
            for(int x=0;x<rows;x++){
                for(int y=0;y<columns;y++){
                    set(x,y,0);
                }
            }
            if(this->rows != other.rows || this->columns != other.columns){
                Resize_matrix(other.rows,other.columns);
                rows=other.rows;
                columns=other.columns;
            }
            for(int x=0;x<rows;x++){
                for(int y=0;y<columns;y++){
                    if(other.operator()(x,y)!=0){
                        set(x,y,other.operator()(x,y));
                    }
                }
            }
            return *this;
        };
        ~Matrix(){
            //Resize_matrix(0,0);
        };
};
#endif
