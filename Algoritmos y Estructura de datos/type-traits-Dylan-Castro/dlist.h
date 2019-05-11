#ifndef DLIST_H
#define DLIST_H

#include "iterator.h"

template <typename T>
class DListIterator : public Iterator<T> {
    public:
        DListIterator() : Iterator<T>() {};
        DListIterator(Node<T> *current) : Iterator<T>(current) {};
        DListIterator<T> operator++(){
            this->current=this->current->next;
            return *this;
        };
        DListIterator<T> operator--(){
            this->current=this->current->prev;
            return *this;
        };
};

template <typename Tr>
class DList {
    public:
        typedef typename Tr::T T;
        typedef DListIterator<T> iterator;

    private:
        Node<T>* head;
        Node<T>* tail;

    public:
        DList() {
            head = tail = nullptr;
        };

        void push_front(T data) {
            // TODO
            Node<T>* aux=new Node<T>(data);
            if (head==nullptr && tail==nullptr)
            {
                tail=aux;
                head=tail;
            }
            else{
                aux->prev=tail;
                aux->next=head;
                head->prev=aux;
                head=aux;
                aux=nullptr;
            }
        }

        void push_back(T data) {
            // TODO
            Node<T>* aux=new Node<T>(data);
            aux->next=nullptr;
            if (head==nullptr && tail==nullptr)
            {
                head=aux;
                tail=head;
            }
            else{
                tail->next=aux;
                aux->prev=tail;
                tail=aux;
            }
        }

        void pop_front() {
            // TODO
            if (head!=nullptr && tail!=nullptr)
            {
                Node<T>* aux=head->next;
                delete head;
                aux->prev=tail;
                head=aux;
            }
            else{
                delete head;
                delete tail;
            }
        }

        void pop_back() {
            // TODO
            if (head!=nullptr && tail!=nullptr)
            {
                Node<T>* aux=tail->prev;
                delete tail;
                aux->next=nullptr;
                tail=aux;
            }
            else{
                delete head;
                delete tail;
            }
        }

        iterator begin() {
            // TODO
            DListIterator<T> aux(head);
            return aux;
        }

        iterator end() {
            // TODO
            DListIterator<T> aux(tail);
            return aux;
        }

        ~DList() {
            if (head) {
                head->killSelf();
            }
        }
};

#endif
