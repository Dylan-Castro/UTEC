#ifndef EDGE_H
#define EDGE_H
#include <iostream>
using namespace std;
#include "node.h"

template <typename G>
class Edge {
    public:
        typedef typename G::E E;
        typedef typename G::node node;
        node* nodes[2];
        Edge(node* first_node, node* second_node,E data){
            nodes[0]=first_node;
            nodes[1]=second_node;
            this->data=data;
        };
        ~Edge(){
        };
        E get(){
            return data;
        }
    private:
        E data;
};

#endif
