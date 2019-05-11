//#include <GL/glut.h>
#include <iostream>
#include <thread>
#include "read.h"
#include "graph.h"

using namespace std;

int main(int argc, char *argv[]) {
    cout<<"***************************************\n";
    cout<<"******************GRAFO_1**************\n";
    cout<<"***************************************\n\n";
    graph g1;
    rd gg;
    gg.getGraph(&g1);
    g1.print();
    cout <<endl;
    thread threads[10];
    for (int i = 0; i < 10; ++i) {
        threads[i] = thread(g1.A_Star,'A','C');
    }

    for (int i = 0; i < 10; ++i) {
        threads[i].join();
    }
    //g1.floyd_warshall();

    /*char a,b;
    bool d=0;
    while(!d){
        cout<<"Inicio: ";
        cin >>a;
        cout<<"final: ";
        cin >> b;
        g1.A_Star(a,b);
        cout<<endl;
    }
    */


    /*g1.conexo();
    cout <<endl;
    g1.prim();
    cout <<endl;
    g1.kruskal();
    cout <<endl;
    cout<<g1.BFS()<<endl;
    cout <<endl;
    g1.bipartito();
    cout <<endl;
    cout<<"La densidad es: "<<g1.densidad()<<endl;
    cout <<endl;
    g1.info_nodo();
    */
    system("PAUSE");
    return EXIT_SUCCESS;
}



//git checkout -b feature/prim
//git push origin feature/prim
