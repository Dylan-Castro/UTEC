#ifndef NODE_H
#define NODE_H

template <typename T>
struct Node {
    T data;
    Node<T>* left;
    Node<T>* right;
    Node(T data) : data(data) {
        left = right = nullptr;
    };
};

#endif
