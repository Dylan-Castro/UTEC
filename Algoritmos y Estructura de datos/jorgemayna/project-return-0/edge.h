#ifndef EDGE_H
#define EDGE_H

#include "node.h"

template <typename G>
class Edge {
    public:
        typedef typename G::E E;
        typedef typename G::N N;
        typedef typename G::node node;
        Edge(E data_):data(data_){};
        E get(){
            return data;
        }
        node* nodes[2];
        node* goes_to(N v1){
            if (nodes[0]->get()==v1){
                return nodes[1];
            }else{
                return nodes[0];
            }
        }
        ~Edge(){}
    private:
        E data;
};

#endif
