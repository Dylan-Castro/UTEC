#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <list>
#include <iostream>
#include <thread>
#include "node.h"
#include "edge.h"
#include <limits.h>
//////////////////////////////////////
#include <queue>
#include <stack>
#include <map>
#include <math.h>
using namespace std;

class Traits {
	public:
		typedef char N;
		typedef int E;
};

template <typename Tr>
class Graph {
    public:
        typedef Graph<Tr> self;
        typedef Node<self> node;
        typedef Edge<self> edge;
        typedef vector<node*> NodeSeq;
        typedef list<edge*> EdgeSeq;
        typedef typename Tr::N N;
        typedef typename Tr::E E;
        typedef typename NodeSeq::iterator NodeIte;
        typedef typename EdgeSeq::iterator EdgeIte;
        Graph(bool option){
            dir=option;
            fuertemente_conexo=false;
        };
        ~Graph(){
            for (ni=nodes.begin();ni!=nodes.end();++ni){
                (*ni)->edges.clear();
            }
            nodes.clear();
        }
        void Inicio(){
            string var;
            int opcion=0;
            int vertice_inicial=0;
            int vertice_final=0;
            int peso=0;
            int vertice=0;
            double p_x,p_y;
            char o='0';
            double cota=0;
            do{
                cout << "Bienvenido al grafo" << endl;
                cout << "1) Insertar Nodo" << endl;
                cout << "2) Insertar Arista" << endl;
                cout << "3) Eliminar Nodo" << endl;
                cout << "4) Eliminar Arista" << endl;
                cout << "5) BFS(Busqueda en amplitud)" << endl;
                cout << "6) DFS(Busqueda en profundidad)" << endl;
                cout << "7) Grado de un vertice" <<endl;
                cout << "8) Densidad del grafo" <<endl;
                cout << "9) �Grafo Conexo?" <<endl;
                cout << "10) �Grafo Fuertemenente Conexo?" <<endl;
                cout << "11) Prim" <<endl;
                cout << "12) Kruskal" <<endl;
                cout << "13) Bipartito" <<endl;
                cout << "14) Imprimir Grafo" <<endl;
                cout << "15) Salir" <<endl;
                cout << "Eliga el numero respectivo a lo que desea hacer:";
                cin >> var;
								printf("\033c");
                try{
                    opcion=stoi(var);
                }
                catch(...){
                    opcion=0;
                }
                switch(opcion){
                case 1:
                    cout << "Escriba el vertice que desea ingresar(Numero): ";
                    cin >> vertice;
                    cout << "Escriba la posicion X: ";
                    cin >> p_x;
                    cout << "Escriba la posicion y: ";
                    cin >> p_y;
                    Insertar_Vertices(p_x,p_y,vertice);
                    cout << "" << endl;
                    break;
                case 2:
                    cout << "Escriba el vertice inicial(Numero): ";
                    cin  >> vertice_inicial;
                    cout << "Escriba el vertice final(Numero): ";
                    cin  >> vertice_final;
                    cout << "Escriba el peso de la arista(Numero): ";
                    cin  >> peso;
                    Insertar_Aristas(vertice_inicial,vertice_final,peso);
										cout << "" << endl;
                    break;
                case 3:
                    cout << "Escriba el vertice que desea eliminar(Numero): ";
                    cin  >> vertice;
                    Eliminar_Nodos(vertice);
										cout << "" << endl;
                    break;
                case 4:
                    cout << "Escriba el vertice inicial(Numero): ";
                    cin  >> vertice_inicial;
                    cout << "Escriba el vertice final(Numero): ";
                    cin  >> vertice_final;
                    Eliminar_Aristas(vertice_inicial,vertice_final);
										cout << "" << endl;
                    break;
                case 5:
                    cout << "Escriba el vertice inicial(Numero): ";
                    cin  >> vertice_inicial;
                    BFS(vertice_inicial);
										cout << "" << endl;
                    break;
                case 6:
                    cout << "Escriba el vertice inicial(Numero): ";
                    cin  >> vertice_inicial;
                    DFS(vertice_inicial);
										cout << "" << endl;
                    break;
                case 7:
                    cout << "Escriba el vertice que desea saber su grado(Numero): ";
                    cin  >> vertice;
                    grado(vertice);
										cout << "" << endl;
                    break;
                case 8:
                    cout << "Escriba la cota(Numero): ";
                    cin  >> cota;
                    if(cota>=0 && cota<=1){
                        densidad(cota);
                    }
                    else{
                        cout << "La cota ingresada no es valida" << endl;
                    }
										cout << "" << endl;
                    break;
                case 9:
                    if(!dir){
                        cout << "Desea saberlo por medio de BFS O DFS:" << endl;
                        cout << "1) BFS" << endl;
                        cout << "2) DFS" << endl;
                        cout << "Eliga el numero respectivo a lo que desea hacer:";
                        cin  >> o;
                        if(o=='1'){
                            cout << "Escriba el vertice inicial: ";
                            cin  >> vertice_inicial;
                            conexo(true);
                        }
                        else if(o=='2'){
                            cout << "Escriba el vertice inicial: ";
                            cin  >> vertice_inicial;
                            conexo(false);
                        }
                        else{
                            cout << "Eligio una opcion incorrecta:" << endl;
                        }
                    }
                    else{
                        cout << "El grafo es dirigido, eliga la opcion �fuertemente conexo?" << endl;
                    }
										cout << "" << endl;
                    break;
                case 10:
                    if(dir){
                        Fuertemente_conexo();
                    }
                    else{
                        cout << "El grafo no es dirigido, eliga la opcion �conexo?" << endl;
                    }
										cout << "" << endl;
                    break;
                case 11:
                    if(!dir){
                        cout << "Escriba el vertice inicial(Numero): ";
                        cin  >> vertice_inicial;
                        prim(vertice_inicial);
                    }
                    else{
                        cout << "Prim no se aplica para grafos dirigidos" << endl;
                    }
										cout << "" << endl;
                    break;
                case 12:
                    if(!dir){
                        kruskal();
                    }
                    else{
                        cout << "Kruskal no se aplica para grafos dirigidos" << endl;
                    }
										cout << "" << endl;
                    break;
                case 13:
                    cout << "Escriba el vertice inicial(Numero): ";
                    cin  >> vertice_inicial;
                    Bipartito(vertice_inicial);
										cout << "" << endl;
                    break;
                case 14:
                    print();
										cout << "" << endl;
                    break;
                default:
                    printf("\033c");
                    break;
                }
            }
            while(opcion!=15);
        }
        node* buscar_nodo(E nodo){
            if(fuertemente_conexo){
                for (ni=nodes_temp.begin();ni!=nodes_temp.end();++ni){
                    if((*ni)->get()==nodo){
                        return *ni;
                    }
                }
            }
            for (ni=nodes.begin();ni!=nodes.end();++ni){
                if((*ni)->get()==nodo){
                    return *ni;
                }
            }
            return nullptr;
        };
        edge* buscar_arista(E first_node, E second_node){
            for (ni=nodes.begin();ni!=nodes.end();++ni){
                for(ei=(*ni)->edges.begin();ei!=(*ni)->edges.end();++ei){
                    if((*ei)->nodes[0]->get()==first_node && (*ei)->nodes[1]->get()==second_node){
                        return *ei;
                    }
                    if(!dir){
                        if((*ei)->nodes[1]->get()==first_node && (*ei)->nodes[0]->get()==second_node){
                        return *ei;
                        }
                    }
                }
            }
            return nullptr;
        };
        void Insertar_Vertices(double ejex,double ejey,E data){
            if(fuertemente_conexo){
                node* nuevo_nodo= new node(ejex,ejey,data);
                nodes_temp.push_back(nuevo_nodo);
                return;
            }
            for (ni=nodes.begin();ni!=nodes.end();++ni){
                if((*ni)->get()==data){
                    cout << "El nodo ya existe :(" << endl;
                    return;
                }
            }
            node* nuevo_nodo= new node(ejex,ejey,data);
            nodes.push_back(nuevo_nodo);
        };
        ///////////////////////////////////////////////////////////////////////////////
        void Insertar_Aristas(int first_node,int second_node,int weight){
            if(buscar_nodo(first_node)==nullptr || buscar_nodo(second_node)==nullptr){
                    cout << "Uno de los nodos ingresados no existe :(" << endl;
                    return;
            }
            if(first_node==second_node){
                cout << "El grafo no acepta bucles" << endl;
                return;
            }
            node* nodo=buscar_nodo(first_node);
            if(dir == true){
                if(fuertemente_conexo){
                    edge* nueva_arista_1= new edge(nodo,buscar_nodo(second_node),weight);
                    nodo->edges.push_back(nueva_arista_1);
                    return;
                }
                for(ei=nodo->edges.begin();ei!=nodo->edges.end();++ei){
                    if((*ei)->nodes[1]->get()==second_node){
                        return;
                    }
                }
                edge* nueva_arista_1= new edge(nodo,buscar_nodo(second_node),weight);
                nodo->edges.push_back(nueva_arista_1);
            }else{
                for(ei=nodo->edges.begin();ei!=nodo->edges.end();++ei){
                    if((*ei)->nodes[1]->get()==second_node && (*ei)->nodes[0]->get()==first_node){
                        cout << "La arista ya existe :(" << endl;
                        return;
                    }
                    else if((*ei)->nodes[1]->get()==first_node && (*ei)->nodes[0]->get()==second_node){
                        cout << "La arista ya existe :(" << endl;
                        return;
                    }
                }
                edge* nueva_arista_1= new edge(nodo,buscar_nodo(second_node),weight);
                nodo->edges.push_back(nueva_arista_1);
                //edge* nueva_arista_2= new edge(nodes[second_node],nodes[first_node],weight);
                nodo=buscar_nodo(second_node);
                nodo->edges.push_back(nueva_arista_1);
            }
        };
        ///////////////////////////////////////////////////////////////////////////////
        void Eliminar_Aristas(N first_node,N second_node){
            edge* temp;
            node* nodo=buscar_nodo(first_node);
            if(buscar_arista(first_node,second_node)==nullptr){
                    cout << "Uno de los nodos ingresados o la arista, no existe :(" << endl;
                    return;
            }
            if(dir==false){
                for(ei=nodo->edges.begin();ei!=nodo->edges.end();++ei){
                    if((*ei)->nodes[1]->get()==second_node && (*ei)->nodes[0]->get()==first_node){
                        temp= (*ei);
                        ei = nodo->edges.erase(ei);
                        ei2=ei;
                        break;
                    }
                    else if((*ei)->nodes[1]->get()==first_node && (*ei)->nodes[0]->get()==second_node){
                        temp= (*ei);
                        ei = nodo->edges.erase(ei);
                        ei2=ei;
                        break;
                    }
                }
                nodo=buscar_nodo(second_node);
                for(ei=nodo->edges.begin();ei!=nodo->edges.end();++ei){
                    if((*ei)->nodes[1]->get()==second_node && (*ei)->nodes[0]->get()==first_node){
                        ei = nodo->edges.erase(ei);
                        break;
                    }
                    else if((*ei)->nodes[1]->get()==first_node && (*ei)->nodes[0]->get()==second_node){
                        ei = nodo->edges.erase(ei);
                        break;
                    }
                }
            }
            else{
                for(ei=nodo->edges.begin();ei!=nodo->edges.end();++ei){
                    if((*ei)->nodes[1]->get()==second_node){
                        temp= (*ei);
                        ei = nodo->edges.erase(ei);
                        ei2=ei;
                        break;
                    }
                }
            }
            delete temp;
        };
        ///////////////////////////////////////////////////////////////////////////////
        void Eliminar_Nodos(E first_node){
            node* nodo=buscar_nodo(first_node);
            if(nodo==nullptr){
                    cout << "El nodo ingresado no existe :(" << endl;
                    return;
            }
            for (ni=nodes.begin();ni!=nodes.end();++ni){
                for(ei2=(*ni)->edges.begin();ei2!=(*ni)->edges.end();++ei2){
                    if((*ni)->get()==first_node){
                        break;
                    }
                    if((*ei2)->nodes[1]->get()==first_node){
                        Eliminar_Aristas((*ni)->get(),first_node);
                    }
                    else if((*ei2)->nodes[0]->get()==first_node){
                        Eliminar_Aristas((*ni)->get(),first_node);
                    }
                }
            }
            for(ei2=nodo->edges.begin();ei2!=nodo->edges.end();++ei2){
                Eliminar_Aristas(first_node,(*ei2)->nodes[1]->get());
            }
            for (ni=nodes.begin();ni!=nodes.end();++ni){
                if((*ni)->get()==first_node){
                    delete (*ni);
                    nodes.erase(ni);
                    break;
                }
            }
        };
        ///////////////////////////////////////////////////////////////////////////////
        bool BFS(E vertice){
            node* nodo=buscar_nodo(vertice);
            if(nodo==nullptr){
                cout << "El nodo ingresado no existe :(" << endl;
                return false;
            }
            cout << "El recorrido de los nodos es: " << endl;
            queue<node*> cola;
            cola.push(nodo);
            map<E,bool> visitado;
            for (ni=nodes.begin();ni!=nodes.end();++ni){
                visitado[(*ni)->get()]=false;
            }
            visitado[nodo->get()]=true;
            if(dir==false){
                do{
                    for(ei=nodo->edges.begin();ei!=nodo->edges.end();++ei){
                        if(visitado.find((*ei)->nodes[1]->get())->second==false){
                            visitado[(*ei)->nodes[1]->get()]=true;
                            cola.push((*ei)->nodes[1]);
                        }
                        else if(visitado.find((*ei)->nodes[0]->get())->second==false){
                            visitado[(*ei)->nodes[0]->get()]=true;
                            cola.push((*ei)->nodes[0]);
                        }
                    }
                    cout << nodo->get() << " ";
                    cola.pop();
                    if(!cola.empty()){
                    nodo= cola.front();
                    }
                }
                while(!cola.empty());
            }
            else{
                do{
                    for(ei=nodo->edges.begin();ei!=nodo->edges.end();++ei){
                        if(visitado.find((*ei)->nodes[1]->get())->second==false){
                            visitado[(*ei)->nodes[1]->get()]=true;
                            cola.push((*ei)->nodes[1]);
                        }
                    }
                    cout << nodo->get() << " ";
                    cola.pop();
                    if(!cola.empty()){
                        nodo= cola.front();
                    }
                }
                while(!cola.empty());
            }
            cout << endl;
            for (ni=nodes.begin();ni!=nodes.end();++ni){
                if(visitado.find((*ni)->get())->second==false){
                    return false;
                }
            }
            return true;
        }
        ///////////////////////////////////////////////////////////////////////////////
        bool DFS(E vertice){
            node* nodo;
            nodo = buscar_nodo(vertice);
            if(nodo==nullptr){
                cout << "El nodo ingresado no existe :(" << endl;
                return false;
            }
            cout << "El recorrido de los nodos es: " << endl;
            stack<node*> cola;
            cola.push(nodo);
            map<E,bool> visitado;
            for (ni=nodes.begin();ni!=nodes.end();++ni){
                visitado[(*ni)->get()]=false;
            }
            visitado[nodo->get()]=true;
            cout << nodo->get() << " ";
            do{
                for(ei=nodo->edges.begin();ei!=nodo->edges.end();++ei){
                    if(visitado.find((*ei)->nodes[1]->get())->second==false){
                        visitado[(*ei)->nodes[1]->get()]=true;
                        cola.push((*ei)->nodes[1]);
                        nodo = cola.top();
                        cout << nodo->get() << " ";
                        break;
                    }
                    else if(visitado.find((*ei)->nodes[0]->get())->second==false){
                        visitado[(*ei)->nodes[0]->get()]=true;
                        cola.push((*ei)->nodes[0]);
                        nodo = cola.top();
                        cout << nodo->get() << " ";
                        break;
                    }
                }
                if(ei==nodo->edges.end()){
                    cola.pop();
                    if(!cola.empty()){
                        nodo= cola.top();
                    }
                }
            }
            while(!cola.empty());
            cout << endl;
            for (ni=nodes.begin();ni!=nodes.end();++ni){
                if(visitado.find((*ni)->get())->second==false){
                    return false;
                }
            }
            return true;
        }
        ///////////////////////////////////////////////////////////////////////////////
        void conexo(bool option){
            if(nodes.size()==0){
                cout << "No hay nodos en el grafo :(" << endl;
                return;
            }
            node* nodo= buscar_nodo(nodes[0]->get());
            cout << "Los nodos son: ";
            for (ni=nodes.begin();ni!=nodes.end();++ni){
                cout << (*ni)->get() << " ";
            }
            cout << endl;
            if(option == 0){
                if(DFS(nodo->get())){
                    cout << "Es conexo" << endl;
                }
                else{
                    cout << "No es conexo" << endl;
                }
            }else{
                if(BFS(nodo->get())){
                    cout << "Es conexo" << endl;
                }
                else{
                    cout << "No es conexo" << endl;
                }
            }
        }
        ///////////////////////////////////////////////////////////////////////////////
        void grado(E vertice){
            node* nodo=buscar_nodo(vertice);
            if(nodo==nullptr){
                cout << "El nodo ingresado no existe :(" << endl;
                return;
            }
            cout << "El grado del nodo ingresado es: " << nodo->edges.size() << endl;
            if(dir==1){
                bool fuente=true;
                for (ni=nodes.begin();ni!=nodes.end();++ni){
                    for(ei=(*ni)->edges.begin();ei!=(*ni)->edges.end();++ei){
                        if((*ei)->nodes[1]->get()==nodo->get()){
                            fuente=false;
                            break;
                        }
                    }
                }
                if(fuente){
                    cout << "El nodo es fuente" << endl;
                }
                else{
                    cout << "El nodo no es fuente" << endl;
                }
                if(nodo->edges.size()==0){
                    cout << "El nodo es hundido" << endl;
                }
                else{
                    cout << "El nodo no es hundido" << endl;
                }
            }
        }
        ///////////////////////////////////////////////////////////////////////////////
        void densidad(double cota){
        map<edge*,bool> aristas;
        double n_vertices=0,n_aristas=0;
        double operacion=0;
        for (ni=nodes.begin();ni!=nodes.end();++ni){
            for(ei=(*ni)->edges.begin();ei!=(*ni)->edges.end();++ei){
                    aristas.insert(pair<edge*,bool>(*ei,0));
            }
            n_vertices++;
        }
        n_aristas=aristas.size();
        cout << "El nro de nodos es: " << n_aristas << endl;
        cout << "El nro de aristas son: " << n_vertices << endl;
        if(dir==1){
            operacion= n_aristas/(n_vertices*(n_vertices-1));
            cout << "El resultado de la operacion es: " << operacion << endl;
            if(operacion>cota){
                cout << "Es denso" << endl;
            }
            else{
                cout << "Es disperso" << endl;
            }
        }
        else{
            operacion=2*n_aristas/(n_vertices*(n_vertices-1));
            cout << operacion << endl;
            if(operacion>cota){
                cout << "Es denso" << endl;
            }
            else{
                cout << "Es disperso" << endl;
            }
        }
        }
        ///////////////////////////////////////////////////////////////////////////////
        void Fuertemente_conexo(){
            node* nodo= buscar_nodo(nodes[0]->get());
            if(nodo==nullptr){
                cout << "No hay nodos en el grafo :(" << endl;
                return;
            }
            cout << "Los nodos son: ";
            for (ni=nodes.begin();ni!=nodes.end();++ni){
                cout << (*ni)->get() << " ";
            }
            cout << endl;
            fuertemente_conexo=true;
            for (ni=nodes.begin();ni!=nodes.end();++ni){
                Insertar_Vertices(0,0,(*ni)->get());
            }
            for (ni2=nodes.begin();ni2!=nodes.end();++ni2){
                for(ei=(*ni2)->edges.begin();ei!=(*ni2)->edges.end();++ei){
                    Insertar_Aristas((*ei)->nodes[1]->get(),(*ei)->nodes[0]->get(),0);
                }
            }
            fuertemente_conexo=false;
            if(DFS(nodo->get())){
                fuertemente_conexo=true;
                if(DFS(nodo->get())){
                    cout << "Es fuertemente conexo" << endl;
                }
                else{
                    cout << "No es fuertemente conexo" << endl;
                }
            }
            else{
                cout << "No es fuertemente conexo" << endl;
            }
            for (ni=nodes_temp.begin();ni!=nodes_temp.end();++ni){
                (*ni)->edges.clear();
            }
            nodes_temp.clear();
            fuertemente_conexo=false;
        }
        ///////////////////////////////////////////////////////////////////////////////
        void prim(E vertice){
            node* nodo=buscar_nodo(vertice);
            if(nodo==nullptr){
                    cout << "El nodo ingresado no existe :(" << endl;
                    return;
            }
            cout << "Las aristas del arbol de minima expansion segun Prim son: " << endl;
            map<E,bool> visitado;
            int contador=0;
            multimap<E,edge*> aristas;
            for (ni=nodes.begin();ni!=nodes.end();++ni){
                visitado[(*ni)->get()]=false;
            }
            do{
                visitado[nodo->get()]=true;
                for(ei=nodo->edges.begin();ei!=nodo->edges.end();++ei){
                    if(visitado.find((*ei)->nodes[1]->get())->second!=true){
                        aristas.insert(pair<E,edge*>((*ei)->get(),*ei));
                    }
                    else if(visitado.find((*ei)->nodes[0]->get())->second!=true){
                        aristas.insert(pair<E,edge*>((*ei)->get(),*ei));
                    }
                }
                if(visitado.find((aristas.begin()->second)->nodes[1]->get())->second!=true){
                    nodo=(aristas.begin()->second)->nodes[1];
                    cout << (aristas.begin()->second)->nodes[0]->get() << (aristas.begin()->second)->nodes[1]->get() << endl;
                    contador++;
                }
                else if(visitado.find((aristas.begin()->second)->nodes[0]->get())->second!=true){
                    nodo=(aristas.begin()->second)->nodes[0];
                    cout << (aristas.begin()->second)->nodes[0]->get() << (aristas.begin()->second)->nodes[1]->get() << endl;
                    contador++;
                }
                aristas.erase(aristas.begin());
            }
            while(contador!=visitado.size()-1);
        }
        ///////////////////////////////////////////////////////////////////////////////
        node* Find(int x){
            if(nodes_temp[x]->get()==x){
                return nodes_temp[x];
            }
            return Find(nodes_temp[x]->get());
        }
        void Union(int x,int y){
            node* fx= Find(x);
            node* fy= Find(y);
            nodes_temp[fx->get()]=fy;
        }
        void kruskal(){
            if(nodes.size()==0){
                cout << "No hay nodos en el grafo :(" << endl;
                return;
            }
            cout << "Las aristas del arbol de minima expansion segun Kruskal son: " << endl;
            map<edge*,bool> visitado;
            multimap<E,edge*> aristas;
            for (ni=nodes.begin();ni!=nodes.end();++ni){
                nodes_temp.push_back(*ni);
                for(ei=(*ni)->edges.begin();ei!=(*ni)->edges.end();++ei){
                    if(visitado.find((*ei))->second!=true){
                        visitado[(*ei)]=true;
                        aristas.insert(pair<E,edge*>((*ei)->get(),*ei));
                    }
                }
            }
            visitado.clear();
            int contador=0;
            for(typename multimap<E,edge*>::iterator it=aristas.begin();it!=aristas.end();++it){
                if(contador==nodes.size()-1){
                    break;
                }
                if(Find((*it).second->nodes[0]->get()) != Find((*it).second->nodes[1]->get())){
                    Union((*it).second->nodes[0]->get(),(*it).second->nodes[1]->get());
                    contador++;
                    cout << (*it).second->nodes[0]->get() << (*it).second->nodes[1]->get() << endl;
                }
            }
            nodes_temp.clear();
        }
        void Bipartito(E vertice){
            bool bipartito=true;
            node* nodo=buscar_nodo(vertice);
            if(nodo==nullptr){
                cout << "El nodo ingresado no existe :(" << endl;
                return;
            }
            map<node*,bool> visitado;
            visitado[nodo]=0;
            for(ei=nodo->edges.begin();ei!=nodo->edges.end();++ei){
                if(dir){
                    visitado[(*ei)->nodes[1]]=1;
                }else{
                    if((*ei)->nodes[0]!=nodo){
                    visitado[(*ei)->nodes[0]]=1;
                    }
                    else if((*ei)->nodes[1]!=nodo){
                        visitado[(*ei)->nodes[1]]=1;
                    }
                }
            }
            for (ni=nodes.begin();ni!=nodes.end();++ni){
                for(ei=(*ni)->edges.begin();ei!=(*ni)->edges.end();++ei){
                    if(dir){
                        if(visitado.find((*ei)->nodes[1])->first!=(*ei)->nodes[1]){
                            if(visitado.find((*ei)->nodes[0])->second==0){
                                visitado[(*ei)->nodes[1]]=1;
                            }
                            else{
                                visitado[(*ei)->nodes[1]]=0;
                            }
                        }
                    }
                    else{
                        if(visitado.find((*ei)->nodes[0])->first!=(*ei)->nodes[0]){
                            if(visitado.find((*ei)->nodes[1])->second==0){
                                visitado[(*ei)->nodes[0]]=1;
                            }
                            else{
                                visitado[(*ei)->nodes[0]]=0;
                            }
                        }
                        else if(visitado.find((*ei)->nodes[1])->first!=(*ei)->nodes[1]){
                            if(visitado.find((*ei)->nodes[0])->second==0){
                                visitado[(*ei)->nodes[1]]=1;
                            }
                            else{
                                visitado[(*ei)->nodes[1]]=0;
                            }
                        }
                    }
                }
            }
            for(typename map<node*,bool>::iterator it=visitado.begin();it!=visitado.end();++it){
                cout << (*it).first->get() << (*it).second << endl;
            }
            for (ni=nodes.begin();ni!=nodes.end();++ni){
                for(ei=(*ni)->edges.begin();ei!=(*ni)->edges.end();++ei){
                    if(visitado.find((*ei)->nodes[0])->second==1 && visitado.find((*ei)->nodes[1])->second==1){
                        bipartito=false;
                        break;
                    }
                    else if(visitado.find((*ei)->nodes[0])->second==0 && visitado.find((*ei)->nodes[1])->second==0){
                        bipartito=false;
                        break;
                    }
                }
                if(!bipartito){
                    break;
                }
            }
            if(bipartito){
                cout << "El grafo es bipartito" << endl;
            }
            else{
                cout << "El grafo no es bipartito" << endl;
            }
        }
        ///////////////////////////////////////////////////////////////////////////////
        void print(){
            for (ni=nodes.begin();ni!=nodes.end();++ni){
                cout << "Nodo: " <<(*ni)->get()<<endl;
                for(ei=(*ni)->edges.begin();ei!=(*ni)->edges.end();++ei){
                    cout <<"Arista :" << (*ei)->nodes[0]->get() << (*ei)->nodes[1]->get();
                    cout <<" Peso : " << (*ei)->get();
                    cout <<"   ";
                }
                cout <<endl;
            }
        }
				///////////////////////////////////////////////////////////////////////////////
				void Greedy_BFS(E vertice_inicial, E vertice_final){
					node* nodo=buscar_nodo(vertice_inicial);
					if(nodo==nullptr){
									cout << "El nodo ingresado no existe :(" << endl;
									return;
					}
					cout << "Las aristas del arbol de minima expansion segun Greedy_BFS desde " << vertice_inicial
					<< " hasta " << vertice_final << " son: " << endl;
					map<E,bool> visitado;
					int contador=0;
					multimap<E,edge*> aristas;
					for (ni=nodes.begin();ni!=nodes.end();++ni){
							visitado[(*ni)->get()]=false;
					}
					do{
							visitado[nodo->get()]=true;
							for(ei=nodo->edges.begin();ei!=nodo->edges.end();++ei){
									if(visitado.find((*ei)->nodes[1]->get())->second!=true){
											aristas.insert(pair<E,edge*>((*ei)->get(),*ei));
									}
									else if(visitado.find((*ei)->nodes[0]->get())->second!=true){
											aristas.insert(pair<E,edge*>((*ei)->get(),*ei));
									}
							}
							if(visitado.find((aristas.begin()->second)->nodes[1]->get())->second!=true){
									nodo=(aristas.begin()->second)->nodes[1];
									cout << (aristas.begin()->second)->nodes[0]->get() << (aristas.begin()->second)->nodes[1]->get() << endl;
									if((aristas.begin()->second)->nodes[1]->get()==vertice_final){
										return;
									}
									contador++;
							}
							else if(visitado.find((aristas.begin()->second)->nodes[0]->get())->second!=true){
									nodo=(aristas.begin()->second)->nodes[0];
									cout << (aristas.begin()->second)->nodes[0]->get() << (aristas.begin()->second)->nodes[1]->get() << endl;
									if((aristas.begin()->second)->nodes[0]->get()==vertice_final){
										return;
									}
									contador++;
							}
							aristas.erase(aristas.begin());
					}
					while(contador!=visitado.size()-1);
					cout << "No se encontro el camino :( " << endl;
				};
				void Floyd_Warshall(){
						 int matrix[nodes.size()][nodes.size()]={0};
						 int matrix2[nodes.size()][nodes.size()]={0};
						 for(int i=0;i<nodes.size();i++){
							 for(int j=0;j<nodes.size();j++){
								 if(i!=j){
									 	matrix[i][j]=INT_MAX;
									 	matrix2[i][j]=j;
								 }
								 else{
                                    matrix2[i][j]=INT_MAX;
								 }
                            }
						 }
						 for (ni=nodes.begin();ni!=nodes.end();++ni){
                            for(ei=(*ni)->edges.begin();ei!=(*ni)->edges.end();++ei){
                                if((*ei)->nodes[0]->get()!=(*ni)->get()){
                                    matrix[(*ni)->get()][(*ei)->nodes[0]->get()]=(*ei)->get();
                                }
                                else if((*ei)->nodes[1]->get()!=(*ni)->get()){
                                    matrix[(*ni)->get()][(*ei)->nodes[1]->get()]=(*ei)->get();
                                }
                            }
                        }
                        int dt=0;
                        for(int k = 0; k < nodes.size(); k++){
                            for(int i = 0; i < nodes.size(); i++){
                                for(int j = 0; j < nodes.size(); j++){
                                    if( matrix[k][j]!=INT_MAX && matrix[i][k]!=INT_MAX){
                                        dt = matrix[i][k] + matrix[k][j];
                                    }
                                    else{
                                        dt = INT_MAX;
                                    }
                                    if(matrix[i][j] > dt){
                                        matrix[i][j] = dt;
                                        if(dt==INT_MAX){
                                            matrix2[i][j] =INT_MAX;
                                        }
                                        else{
                                            matrix2[i][j] = k;
                                        }

                                    }
                                }
                            }
                        }
                        for(int i=0;i<nodes.size();i++){
							 for(int j=0;j<nodes.size();j++){
								 if(matrix[i][j]==INT_MAX){
									cout << "- ";
								 }
								 else{
                                    cout << matrix[i][j] << " ";
								 }
                            }
                            cout << endl;
                        }
                        cout << endl;
                        cout << endl;
                        for(int i=0;i<nodes.size();i++){
							 for(int j=0;j<nodes.size();j++){
								 if(matrix2[i][j]==INT_MAX){
									cout << "- ";
								 }
								 else{
                                    cout << matrix2[i][j] << " ";
								 }
                            }
                            cout << endl;
                        }
				};


								E menor(map<E,bool> visitados, map<E,double> tabla)
				{
					typename map<E,double>::iterator menorIT = tabla.begin();
					E min = INT_MAX;
					E index=nodes.size()+1;
					for(menorIT = tabla.begin();menorIT != tabla.end();++menorIT)
					{
						if(min>=(*menorIT).second && visitados[(*menorIT).first]==0){
							min=(*menorIT).second;
							index=(*menorIT).first;
						}
					}
					return index;
				}
				map<E,double> dijkstra(int Original)
				{
					map<E,bool> visitados;
					map<E,double> tabla;
					vector<E> listanodos;
					E min;
					for(ni=nodes.begin();ni!=nodes.end();++ni)
					{
						tabla.insert(pair<E,double>((*ni)->get(),INT_MAX));
						visitados.insert(pair<E,bool>((*ni)->get(),0));
						listanodos.push_back((*ni)->get());
					}
					tabla[Original]=0;
					visitados[Original]=1;
					auto node = buscar_nodo(Original);
					while(!listanodos.empty())
					{
						for(ei=node->edges.begin();ei!=node->edges.end();++ei)
						{
							if((*ei)->nodes[1]!=node && tabla[node->get()]!=INT_MAX && (*ei)->get()+tabla[node->get()]<tabla[(*ei)->nodes[1]->get()])
							{
									tabla[(*ei)->nodes[1]->get()]=(*ei)->get()+tabla[node->get()];
							}
							else if((*ei)->nodes[0]!=node && tabla[node->get()]!=INT_MAX && (*ei)->get()+tabla[node->get()]<tabla[(*ei)->nodes[0]->get()])
							{
								tabla[(*ei)->nodes[0]->get()]=(*ei)->get()+tabla[node->get()];
							}

						}
						min = menor(visitados,tabla);
						if(min>nodes.size()){
							break;
						}
						node = buscar_nodo(min);
						visitados[node->get()] = 1;
						listanodos.pop_back();
				  }

					for(typename map<E,double>::iterator iterador=tabla.begin();iterador!=tabla.end();++iterador)
					{
						if((*iterador).second==INT_MAX)
						{
								cout<<(*iterador).first<<": "<<"INF"<<endl;
						}
						else
						{
						cout<<(*iterador).first<<": "<<(*iterador).second<<endl;
					  }
					}
					return tabla;
				}
				map<E,E> Bellman(int nodo)
				{
					map<E,E> distancia;
					map<E,E> visitados;
					distancia[nodo]=0;
					auto node = buscar_nodo(nodo);
					for(ni=nodes.begin();ni!=nodes.end();++ni)
					{
						distancia.insert(pair<E,E>((*ni)->get(),INT_MAX));
					}
					for(ni=nodes.begin();ni!=nodes.end();++ni)
					{
						for(ei=(*ni)->edges.begin();ei!=(*ni)->edges.end();++ei)
						{
							if(distancia[(*ei)->nodes[0]->get()] + (*ei)->get() < distancia[(*ei)->nodes[1]->get()] and distancia[(*ei)->nodes[0]->get()] != INT_MAX)
							{
								distancia[(*ei)->nodes[1]->get()] = distancia[(*ei)->nodes[0]->get()] + (*ei)->get();
							}
						}
					}
					for(ni=nodes.begin();ni!=nodes.end();++ni)
					{
						for(ei=(*ni)->edges.begin();ei!=(*ni)->edges.end();++ei)
						{
							if(distancia[(*ei)->nodes[0]->get()] + (*ei)->get() < distancia[(*ei)->nodes[1]->get()])
							{cout<<"Error";}

						}
					}
					for(typename map<E,E>::iterator iterador=distancia.begin();iterador!=distancia.end();++iterador)
					{
						if((*iterador).second==INT_MAX)
						{
								cout<<(*iterador).first<<": "<<"INF"<<endl;
						}
						else
						{
						cout<<(*iterador).first<<": "<<(*iterador).second<<endl;
					  }
					}
				}

		void A_star(E Original, E vertice_final){
			node* nodo2=buscar_nodo(vertice_final);
			double heuristica[nodes.size()]={0};
			for(int x=0;x<nodes.size();x++){
					heuristica[x]= sqrt(pow(nodes[x]->getx()-nodo2->getx(),2)+pow(nodes[x]->gety()-nodo2->gety(),2));
			}
			map<E,bool> visitados;
			map<E,double> tabla;
			int aux[nodes.size()]={0};
			vector<E> listanodos;
			E min;
			for(ni=nodes.begin();ni!=nodes.end();++ni)
			{
				tabla.insert(pair<E,E>((*ni)->get(),INT_MAX));
				visitados.insert(pair<E,bool>((*ni)->get(),0));
				listanodos.push_back((*ni)->get());
			}
			tabla[Original]=0;
			visitados[Original]=1;
			auto node = buscar_nodo(Original);
			while(!listanodos.empty())
			{
				for(ei=node->edges.begin();ei!=node->edges.end();++ei)
				{
					if((*ei)->nodes[1]!=node && tabla[node->get()]!=INT_MAX && (*ei)->get()+tabla[node->get()]<tabla[(*ei)->nodes[1]->get()])
					{
							tabla[(*ei)->nodes[1]->get()]=(*ei)->get()+tabla[node->get()]+heuristica[(*ei)->nodes[0]->get()];
							aux[(*ei)->nodes[1]->get()]=(*ei)->nodes[0]->get();
							if((*ei)->nodes[1]->get()==vertice_final){
								break;
							}
					}
					else if((*ei)->nodes[0]!=node && tabla[node->get()]!=INT_MAX && (*ei)->get()+tabla[node->get()]<tabla[(*ei)->nodes[0]->get()])
					{
						tabla[(*ei)->nodes[0]->get()]=(*ei)->get()+tabla[node->get()]+heuristica[(*ei)->nodes[1]->get()];
						aux[(*ei)->nodes[0]->get()]=(*ei)->nodes[1]->get();
						if((*ei)->nodes[0]->get()==vertice_final){
							break;
						}
					}
				}
				min = menor(visitados,tabla);
				if(min>nodes.size()){
					break;
				}
				node = buscar_nodo(min);
				visitados[node->get()] = 1;
				listanodos.pop_back();
			}
			int bika=tabla.rbegin()->first;
			for(int x=0; x<nodes.size();++x)
			{
				cout <<aux[bika] << bika << endl;
				bika=aux[bika];
				if(bika==Original){
					break;
				}
			}
		};
		void hilos2(int nodo_inicial,int nodo_final){
					A_star(nodo_inicial,nodo_final);
					cout << endl;
		};
		void hilos(){
				thread threads[3];
				for(int x=0;x<3;++x){
						cout << "thread" << x <<": " << endl;
						threads[x]=thread(&Graph::hilos2,this,0,8);
						threads[x].join();
				}
		};
    private:
        NodeSeq nodes;
        NodeSeq nodes_temp;
        NodeIte ni;
        NodeIte ni2;
        EdgeIte ei;
        EdgeIte ei2;
        bool dir;
        bool fuertemente_conexo;
};
typedef Graph<Traits> graph;

#endif
