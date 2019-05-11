#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Alumno
{
  public:
    string nombre;
    string apellidos;
    string carrera;
    string mensualidad;
    string data;
    void load(){
      fstream archivo("datos.txt");
      archivo >> data;
      getline(archivo,nombre,'|');
      getline(archivo,apellidos,'|');
      getline(archivo,carrera,'|');
      getline(archivo,mensualidad);
      imprimir_alumnos();
    };
    void imprimir_alumnos(){
          cout << this->nombre << " ";
          cout << this->apellidos << " ";
          cout << this->carrera << " ";
          cout << this->mensualidad << endl;
    };
};
int main(){
Alumno objeto;
objeto.load();
}
