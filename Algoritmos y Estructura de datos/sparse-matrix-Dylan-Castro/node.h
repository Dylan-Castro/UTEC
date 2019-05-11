#ifndef NODE_H
#define NODE_H

using namespace std;

template <class T>
class Node {
    T data;
    public:
    int x, y;
    Node* next;
    Node* down;
    Node(){
        next=nullptr;
        down=nullptr;
        x=0;
        y=0;
        data=0;
    }
    void set(int x,int y, T data){
        this->x=x;
        this->y=y;
        this->data=data;
    };
    T get(){
        return data;
    };
};

#endif
