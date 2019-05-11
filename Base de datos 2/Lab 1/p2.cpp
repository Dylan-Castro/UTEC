#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <string.h>
using namespace std;
class Alumno
{
  public:
    int codigo_alumno;
    char nombre[12];
    char apPaterno[12];
    char apMaterno[12];
    char carrera[12];
    int ciclo;
    float mensualidad;
};
class Aula
{
  private:
      char filename[100];
      vector <Alumno*> alumnos;
      int tamanio_fichero=0;
      int tamanio_actual=0;
  public:
    void load(){
      alumnos.clear();
      ifstream file;
      file.open("data2.dat",ios::in |ios::out | ios::binary);
      file.seekg(0,ios::end);
      tamanio_fichero=file.tellg();
      file.seekg(0,ios::beg);
      while(tamanio_actual!=tamanio_fichero){
        if(file.is_open()){
          Alumno* alu=new Alumno;
          int tam=0;
          file.read((char *)&tam,sizeof(tam));
          file.read((char *)alu,tam);
          tamanio_actual+=sizeof(int)+tam;
          alumnos.push_back(alu);
        }
      }
      file.close();
      imprimir_alumnos();
      /*cout <<alu->nombre<<endl;
      cout <<alu->apPaterno<<endl;
      cout <<alu->apMaterno<<endl;
      cout <<alu->carrera<<endl;
      cout <<alu->ciclo<<endl;
      cout <<alu->mensualidad<<endl;*/
    };
    void add(){
      Alumno* alu=new Alumno;
      cout << "Ingrese el codigo alumno" << endl;
      cin >>alu->codigo_alumno;
      cout<<"Ingrese el nombre: "<<endl;
      cin >>alu->nombre;
      cout<<"Ingrese el apellido paterno: "<<endl;
      cin >>alu->apPaterno;
      cout<<"Ingrese el apellido apMaterno: "<<endl;
      cin >>alu->apMaterno;
      cout<<"Ingrese la carrera: "<<endl;
      cin >>alu->carrera;
      cout<<"Ingrese el ciclo: "<<endl;
      cin >>alu->ciclo;
      cout<<"Ingrese la mensualidad : "<<endl;
      cin >>alu->mensualidad;
      alumnos.push_back(alu);
        fstream file;
        file.open("data2.dat",ios::out | ios::app | ios::binary);
        if(file.is_open()){
            int tam= sizeof(int)*2+sizeof(float)+12*4;
            file.write(reinterpret_cast<const char *>(&tam),sizeof(tam));
            file.write((char *)alu,tam);
            file.close();
        }
    }
    /*void erase(int codigo){
      int tam= sizeof(int)*2+sizeof(float)+12*4;
      int contador=0;
      for (vector<Alumno*>::iterator it = alumnos.begin() ; it != alumnos.end(); ++it){
        contador++;
        if((*it)->codigo_alumno==codigo){
            alumnos.erase(it);
        }
        break;
      }


      fstream file;
      file.open("data2.dat",ios::in |ios::out | ios::binary);
      file.seekg(0,ios::end);
      tamanio_fichero=file.tellg();
      file.seekg(0,ios::beg);
      if(file.is_open()){
          int tam= sizeof(int)+sizeof(float)+12*4;
          file.write(reinterpret_cast<const char *>(&tam),sizeof(tam));
          //file.write((char *)alu,tam);
          file.close();
      }
    };*/




    void imprimir_alumnos(){
      for(int x=0;x<alumnos.size();x++){
          cout << alumnos[x]->codigo_alumno << " ";
          cout << alumnos[x]->nombre << " ";
          cout << alumnos[x]->apPaterno << " ";
          cout << alumnos[x]->apMaterno << " ";
          cout << alumnos[x]->carrera << " ";
          cout << alumnos[x]->ciclo << " ";
          cout << alumnos[x]->mensualidad << endl;
      }
    };
};

int main(){
  Aula aula;
  //aula.add();
  //aula.add();
  aula.load();
}
