#ifndef ITERATOR_H
#define ITERATOR_H

#include "node.h"

template <typename T>
class Iterator {
    private:
        Node<T>* current;

    public:
        Iterator();
        Iterator(Node<T>* node);

        Iterator<T> operator=(Iterator<T> node);
        bool operator!=(Iterator<T> cmp);
        Iterator<T> operator++();
        Iterator<T> operator--();
        T operator*();
};

template<class T> Iterator<T>::Iterator()
{

    current=NULL;

}
template<typename T> T Iterator<T>::operator*()
{
    return current->data;

}
//Test
template<class T> Iterator<T>::Iterator(Node<T>* node)
{
    current=node;

}
//Test
template<typename T> bool Iterator<T>::operator!=(Iterator<T> node)
{
    if (current==node.current)
    {
        return false;

    }
    else{
        return true;
    }

}
template<typename T> Iterator<T> Iterator<T>::operator++()
{
    current=current->next;
    return *this;

}
template<typename T> Iterator<T> Iterator<T>::operator--()
{
    current=current->prev;
    return *this;

}
template<typename T> Iterator<T> Iterator<T>::operator=(Iterator<T> node)
{
    Iterator<T> temp;
    temp.current=node.current;

    return temp;
}


#endif
