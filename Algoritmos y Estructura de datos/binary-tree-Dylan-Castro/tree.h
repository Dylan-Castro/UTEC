#ifndef TREE_H
#define TREE_H
#include <cstdlib>
#include <iostream>
#include <string>
#include "iterator.h"
template <typename T>
class Tree
{
    private:
        Node<T>* root;
        int peso;
    public:
        Tree();
        ~Tree();
        void killtree(Node<T>* root);
        void Insert(Node<T> **&pointer, T data);
        void Delete(Node<T> **&pointer,T data);
        void PreOrder(Node<T>* root);
        void InOrder(Node<T>* root);
        void PostOrder(Node<T>* root);
        void Peso(Node<T>* root, T data,T ubicado);
        void Main();
        Iterator<T> begin();
        Iterator<T> end();
};
template<class T> Tree<T>::Tree(){
    root=nullptr;
    peso=0;
}
template<class T> Tree<T>::~Tree(){
    killtree(root);
}
template<class T> void Tree<T>::killtree(Node<T>* root){
    if(root==nullptr){
        return;
    }
    else{
        killtree(root->left);
        killtree(root->right);
        delete root;
    }
}
template<class T> void Tree<T>::Main(){
    string var;
    int opcion;
    int date;
    Node<T>** pointer;
    int aux=0;
    do{
        Iterator<T> ite;
        cout << "Bienvenido al arbol binario" << endl;
        cout << "1) Insertar dato" << endl;
        cout << "2) Eliminar dato" << endl;
        cout << "3) Imprimir en PreOrder" << endl;
        cout << "4) Imprimir en InOrder" << endl;
        cout << "5) Imprimir en PostOrder" << endl;
        cout << "6) Iterador en InOrder" << endl;
        cout << "7) Peso del nodo" <<endl;
        cout << "8) Destruir Arbol" <<endl;
        cout << "9) Salir" <<endl;
        cout << "Eliga el numero respectivo a lo que desea hacer:";
        cin >> var;
        try{
            opcion=stoi(var);
        }
        catch(...){
            opcion=0;
        }

        switch(opcion){
        case 1:
            cout << "Ingrese un numero: ";
            cin >> date;
            pointer=&root;
            Insert(pointer,date);
            pointer=nullptr;
            system("cls");
            cout << "InOrder:" <<endl;
            InOrder(root);
            cout << endl;
            break;
        case 2:
            cout << "Ingrese el numero que desea eliminar: ";
            cin >> date;
            pointer=&root;
            Delete(pointer,date);
            pointer=nullptr;
            system("cls");
            cout << "InOrder:" <<endl;
            InOrder(root);
            cout << endl;
            break;
        case 3:
            system("cls");
            cout << "PreOrder:" <<endl;
            PreOrder(root);
            cout << endl;
            break;
        case 4:
            system("cls");
            cout << "InOrder:" <<endl;
            InOrder(root);
            cout << endl;
            break;
        case 5:
            system("cls");
            cout << "PostOrder:" <<endl;
            PostOrder(root);
            cout << endl;
            break;
        case 6:
            system("cls");
            cout << "Iterator-InOrder:" <<endl;
            if(root!=nullptr){
                for (ite = begin(); ite!=end(); ++ite) {
                if(*ite!=0){
                    cout << *ite << " - ";
                }
                }
                cout << *ite;
                cout << endl;
            }
            else{
                cout << "El arbol esta vacio, no se puede iterar" << endl;
            }
            break;
        case 7:
            system("cls");
            cout << "InOrder:" <<endl;
            InOrder(root);
            cout << endl;
            cout << "Ingrese el numero del nodo que desea saber su peso: " << endl;
            cin >> date;
            cout << "El peso del nodo seleccionado es: ";
            Peso(root,date,false);
            cout << peso << endl;
            peso=0;
            break;
        case 8  :
            system("cls");
            killtree(root);
            root=nullptr;
            cout << "Arbol eliminado con exito" << endl;
            break;
        default:
            system("cls");
            break;
        }
    }
    while(opcion!=9);
}
template<class T> void Tree<T>::Insert(Node<T> **&pointer,T data){
    if(*pointer==nullptr){
        *pointer = new Node<T>(data);

    }
    else if(data < (*pointer)->data){
        pointer=&(*pointer)->left;
        Insert(pointer,data);
    }
    else if(data > (*pointer)->data){
        pointer=&(*pointer)->right;
        Insert(pointer,data);
    }
}
template<class T> void Tree<T>::Delete(Node<T> **&pointer,T data){
    if(*pointer==nullptr){
        return;
    }
    else if((*pointer)->data==data){
        Node<T>** temp=pointer;
        if((*pointer)->left!=nullptr && (*pointer)->right!=nullptr){
                temp=&(*temp)->right;
            while((*temp)->left!=nullptr){
                temp=&(*temp)->left;
            }
            Node<T>** aux=&(*temp)->right;
            (*pointer)->data=(*temp)->data;
            delete *temp;
            *temp=*aux;
        }
        else if((*pointer)->left!=nullptr || (*pointer)->right!=nullptr){
            if((*pointer)->left!=nullptr){
                temp=&(*pointer)->left;
                delete *pointer;
                *pointer=*temp;
            }
            else{
                temp=&(*pointer)->right;
                delete *pointer;
                *pointer=*temp;
            }
        }
        else if((*pointer)->left==nullptr && (*pointer)->right==nullptr){
           delete *pointer;
           *pointer=nullptr;
        }
    }
    else if(data < (*pointer)->data){
        pointer=&(*pointer)->left;
        Delete(pointer,data);
    }
    else if(data > (*pointer)->data){
        pointer=&(*pointer)->right;
        Delete(pointer,data);
    }
}
template<class T> void Tree<T>::PreOrder(Node<T>* root){
    if(root==nullptr){
        return;
    }
    else{
        cout << root->data << " - ";
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

template<class T> void Tree<T>::InOrder(Node<T>* root){
    if(root==nullptr){
        return;
    }
    else{
        InOrder(root->left);
        cout << root->data << " - ";
        InOrder(root->right);
    }
}

template<class T> void Tree<T>::PostOrder(Node<T>* root){
    if(root==nullptr){
        return;
    }
    else{
        PostOrder(root->left);
        PostOrder(root->right);
        cout << root->data << " - ";
    }
}

template<class T> void Tree<T>::Peso(Node<T>* root,T data,T ubicado){
    if(root==nullptr){
        return;
    }
    else if(root->data==data || ubicado==true){
        peso++;
        ubicado=true;
        Peso(root->left,data,ubicado);
        Peso(root->right,data,ubicado);
    }
    else if(data < root->data){
        Peso(root->left,data,ubicado);
    }
    else if(data > root->data){
        Peso(root->right,data,ubicado);
    }
}
template<typename T> Iterator<T> Tree<T>::begin()
{
    Iterator<T> ite(root);
    return ite;
}
template<typename T> Iterator<T> Tree<T>::end()
{
    Node<T>* temp=root;
    while(temp->right!=nullptr){
        temp=temp->right;
    }
    Iterator<T> ite(temp);
    return ite;
}

#endif // TREE_H
