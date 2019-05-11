#ifndef READ_H
#define READ_H
#include <fstream>
#include "graph.h"
#include <string>


/**
 * Clase de ayuda para leer el grafo desde un archivo,
 * no es necesario que la utilicen, podrían implementar su lector
 * desde su grafo o algún otro lado
 **/
template <typename G>
class Read {
	typedef typename G::N N;
	typedef typename G::E E;
	public:

		Read() {
            // TODO
            int v_inicial,v_final,peso;
            double p_x,p_y;
            int n_nodos;
            ////////////////
            string data;
            ifstream archivo("graph.txt");
            archivo >> data;
            graph grafo(stoi(data));
            archivo >> data;
            n_nodos=stoi(data);
            for(int x=0;x<n_nodos;x++){
                for(int y=0;y<2;y++){
                    archivo >> data;
                    switch(y){
                    case 0:
                        p_x=stod(data);
                        break;
                    case 1:
                        p_y=stod(data);
                        break;
                    }
                }
                grafo.Insertar_Vertices(p_x,p_y,x);
            }
            while (!archivo.eof()) {
                for(int x=0;x<3;x++){
                    archivo >> data;
                    switch(x){
                    case 0:
                        v_inicial=stoi(data);
                        break;
                    case 1:
                        v_final=stoi(data);
                        break;
                    case 2:
                        peso=stoi(data);
                        break;
                    }
                }
                grafo.Insertar_Aristas(v_inicial,v_final,peso);
            }
            archivo.close();
            grafo.hilos();
            //grafo.print();
						grafo.Floyd_Warshall();
						//grafo.Greedy_BFS(0,8);
            //grafo.A_star(0,8);
            //grafo.Inicio();
        };

		graph& getGraph() {
            // TODO
        };
};
typedef Read<Traits> read;
#endif
