#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
using namespace std;
class Alumno
{
  public:
    char codigo_alumno[12];
    char nombre[12];
    char apPaterno[12];
    char apMaterno[12];
    char carrera[12];
};
class Aula
{
  private:
      char filename[100];
  public:
    vector <Alumno*> alumnos;
    void load(){
      fstream archivo("datos.txt");
      Alumno* objeto = new Alumno;
      archivo >> objeto->nombre >> objeto->apPaterno >> objeto->apMaterno >> objeto->carrera;
      while (!archivo.eof()) {
        alumnos.push_back(objeto);
        objeto = new Alumno;
        archivo >> objeto->nombre >> objeto->apPaterno >> objeto->apMaterno >> objeto->carrera;
        }
        archivo.close();
        imprimir_alumnos();
    };
    void add(Alumno* objeto){
        alumnos.push_back(objeto);
        fstream archivo("datos.txt",fstream::out | fstream::app);
        if (archivo.is_open())
          {
          archivo <<  objeto->nombre << "     " << objeto->apPaterno << "     " << objeto->apMaterno << "     " << objeto->carrera;
          archivo.close();
          }
    }
    void imprimir_alumnos(){
      for(int x=0;x<alumnos.size();x++){
          cout << alumnos[x]->nombre << " ";
          cout << alumnos[x]->apPaterno << " ";
          cout << alumnos[x]->apMaterno << " ";
          cout << alumnos[x]->carrera << endl;
      }
    }
};
void Solicitar_Datos(Aula* o_aula){
  Alumno* objeto = new Alumno;
  cin >> objeto->nombre;
  cin >> objeto->apPaterno;
  cin >> objeto->apMaterno;
  cin >> objeto->carrera;
  o_aula->add(objeto);
}
int main(){
Aula objeto;
objeto.load();
Solicitar_Datos(&objeto);
objeto.imprimir_alumnos();
}
