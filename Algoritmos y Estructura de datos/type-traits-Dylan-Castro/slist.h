#ifndef SLIST_H
#define SLIST_H

#include "iterator.h"
using namespace std;
template <class T>
class SListIterator : public Iterator<T> {
    public:
        SListIterator() : Iterator<T>() {};
        SListIterator(Node<T> *current) : Iterator<T>(current) {};
        SListIterator<T> operator++()
        {
            this->current=this->current->next;
            return *this;
        };
};

template <typename Tr>
class SList {
    public:
        typedef typename Tr::T T;
        typedef typename Tr::Operation Operation;
        typedef SListIterator<T> iterator;

    private:
        Node<T>* head;
        Operation cmp;

    public:
        SList() {
            head = nullptr;
        };

        bool find(T search, Node<T> **&pointer) {
            pointer=&head;
            if(*pointer == nullptr){
                return false;
            }
            else{
                do{
                    if(cmp((*pointer)->data,search)){
                        if((*pointer)->data==search){
                            return true;
                        }
                        if((*pointer)->next==nullptr){
                            return false;
                        }
                        pointer=&(*pointer)->next;
                    }
                    else{
                        return true;
                    }
                }while(0<1);
            }

            // TODO
        }

        bool insert(T data) {
            // TODO
            Node<T>** pointer;
            if(find(data, pointer)){
                Node<T>* aux= *pointer;
                *pointer=new Node<T>(data);
                (*pointer)->next=aux;
                aux=nullptr;
            }else{;
                if(*pointer==nullptr){
                    head=new Node<T>(data);
                }else{
                    (*pointer)->next=new Node<T>(data);
                }
            }
        }

        bool remove(T item) {
            Node<T>** pointer;
            if(find(item,pointer)){
                Node<T>* aux=(*pointer)->next;
                delete *pointer;
                *pointer=aux;
                aux=nullptr;
            }

            // TODO
        }

        iterator begin() {
            // TODO
            SListIterator<T> ite(head);
            return ite;
        }

        iterator end() {
            Node<T>* aux = head;
            do{
                aux=aux->next;
            }while(aux->next!=nullptr);
            SListIterator<T> ite(aux->next);
            return ite;
        }

        ~SList() {
            if (head) {
                head->killSelf();
            }
        }
};

#endif
