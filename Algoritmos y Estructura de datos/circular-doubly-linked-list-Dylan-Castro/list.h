#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "node.h"
#include "iterator.h"

using namespace std;

template <typename T>
class List {
    private:
        Node<T>* start;
        int nodes;

    public:
        List();

        T front();
        T back();
        void push_front(T value);
        void push_back(T value);
        void pop_front();
        void pop_back();
        T get(int position);
        void concat(List<T> &other);
        bool empty();
        int size();
        void clear();
        Iterator<T> begin();
        Iterator<T> end();



        ~List();
};

template<class T> List<T>::List()
{

    start=NULL;
    nodes=0;

}
template<class T> List<T>::~List()
{
    clear();
}


template<typename T> void List<T>::push_front(T value)
{
    //Arreglar
    Node<T>* aux = new Node<T>;
    aux->data=value;

    if (start==NULL)
    {

        start=aux;
        start->next=start;
        start->prev=start;

    }
    aux->prev=start->prev;
    aux->next=start;
    start->prev=aux;
    start=aux;
    nodes++;
    aux=NULL;
}
template<typename T> Iterator<T> List<T>::begin()
{
    Iterator<T> aux(start);
    return aux;

}
template<typename T> Iterator<T> List<T>::end()
{
    Iterator<T> aux(start->prev);


    return aux;

}
template<typename T> void List<T>::push_back(T value)
{
    //Arreglar
    Node<T>* aux = new Node<T>;
    aux->data=value;
    aux->next=start;

    nodes++;
    if (start==NULL)
    {

        start=aux;
        aux->prev=start;
    }else{
        start->prev->next=aux;
        aux->prev=start->prev;
        start->prev=aux;
    }
    aux=NULL;
}
template<typename T> void List<T>::pop_front()
{
    if(nodes!=1)
    {
        Node<T>* aux=start->next;
        aux->prev=start->prev;
        start->prev->next=aux;
        delete start;
        start=aux;
        aux=NULL;
        nodes--;
    }else{
        delete start;
        start=NULL;
        nodes--;
    }
}

template<typename T> T List<T>::get(int position)
{
    Node<T>* aux=start;
    T rpta;
    for(int x=0;x!=position;x++)
    {

        rpta=aux->data;
        aux=aux->next;
    }
    aux= NULL;
    return rpta;
}

template<typename T> void List<T>::pop_back()
{

    if(nodes!=1)
    {
        Node<T>* aux=start->prev->prev;

        aux->next=start;
        delete start->prev;
        start->prev=aux;
        aux=NULL;
        nodes--;


    }else{
        delete start;
        start=NULL;
        nodes--;
    }
}

template<typename T> void List<T>::concat(List<T> &other)
{

    if(!empty())
    {
        Node<T>* aux=start->prev;
        start->prev->next=other.start;
        other.start->prev->next=start;
        start->prev=other.start->prev;
        other.start->prev=aux;
        aux=NULL;
    }
    else{
        start=other.start;
        start->prev=other.start->prev;
    }
    nodes=nodes+other.nodes;

}

template<typename T> int List<T>::size()
{
    return nodes;
}




template<typename T> void List<T>::clear()
{
    if(!empty())
    {
        while(start!=start->prev)
        {
            pop_front();

        }
        nodes=0;
        delete start;
        start=NULL;
    }
}

template<typename T> T List<T>::front()
{

    return(start->data);

}

template<typename T> T List<T>::back()
{

    return(start->prev->data);

}
template<typename T> bool List<T>::empty()
{
    //Arreglar
    bool a=true;
    if(start==NULL)
    {
        return a;
    }else{
        return !a;
    }

}

#endif
