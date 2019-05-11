#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
vector<string> Stopwords;
vector<string>::iterator it;
multimap<string, int> terminos_frecuentes;
map<string, bool> validar_terminos;
/*
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

  cin >> objeto->apMaterno;
  cin >> objeto->carrera;
  o_aula->add(objeto);
}*/
int main() {
  fstream file("stopwords.txt");
  string data;
  while (!file.eof()) {
    file >> data;
    Stopwords.push_back(data);
  }
  /////////////////////////////////////////////////
  fstream libro1("libros/libro1.txt");
  while (!libro1.eof()) {
    libro1 >> data;
    if (it == Stopwords.end()) {
      if (validar_terminos.count(data) == 0) {
        validar_terminos[data] = 1;
        terminos_frecuentes.insert(std::pair<string, int>(data, 1));
      }
    }
  }
  libro1.close();
  validar_terminos.clear();
  /////////////////////////////////////////////////
  fstream libro2("libros/libro2.txt");
  while (!libro2.eof()) {
    libro2 >> data;
    it = find(Stopwords.begin(), Stopwords.end(), data);
    if (it == Stopwords.end()) {
      if (validar_terminos.count(data) == 0) {
        validar_terminos[data] = 1;
        terminos_frecuentes.insert(std::pair<string, int>(data, 2));
      }
    }
  }
  libro2.close();
  validar_terminos.clear();
  /////////////////////////////////////////////////
  fstream libro3("libros/libro3.txt");
  while (!libro3.eof()) {
    libro3 >> data;
    it = find(Stopwords.begin(), Stopwords.end(), data);
    if (it == Stopwords.end()) {
      if (validar_terminos.count(data) == 0) {
        validar_terminos[data] = 1;
        terminos_frecuentes.insert(std::pair<string, int>(data, 3));
      }
    }
  }
  libro3.close();
  validar_terminos.clear();
  /////////////////////////////////////////////////
  fstream libro4("libros/libro4.txt");
  while (!libro4.eof()) {
    libro4 >> data;
    it = find(Stopwords.begin(), Stopwords.end(), data);
    if (it == Stopwords.end()) {
      if (validar_terminos.count(data) == 0) {
        validar_terminos[data] = 1;
        terminos_frecuentes.insert(std::pair<string, int>(data, 4));
      }
    }
  }
  libro4.close();
  validar_terminos.clear();
  /////////////////////////////////////////////////
  fstream libro5("libros/libro5.txt");
  while (!libro5.eof()) {
    libro5 >> data;
    it = find(Stopwords.begin(), Stopwords.end(), data);
    if (it == Stopwords.end()) {
      if (validar_terminos.count(data) == 0) {
        validar_terminos[data] = 1;
        terminos_frecuentes.insert(std::pair<string, int>(data, 5));
      }
    }
  }
  libro5.close();
  validar_terminos.clear();
  /////////////////////////////////////////////////
  fstream libro6("libros/libro6.txt");
  while (!libro6.eof()) {
    libro6 >> data;
    it = find(Stopwords.begin(), Stopwords.end(), data);
    if (it == Stopwords.end()) {
      if (validar_terminos.count(data) == 0) {
        validar_terminos[data] = 1;
        terminos_frecuentes.insert(std::pair<string, int>(data, 6));
      }
    }
  }
  libro6.close();
  validar_terminos.clear();
  /////////////////////////////////////////////////
  string aux="";
  for (std::multimap<string, int>::iterator it = terminos_frecuentes.begin(); it != terminos_frecuentes.end(); ++it){
    if(aux==(*it).first){
      cout << " " << (*it).second;
    }
    else{
      cout << endl;
      cout << (*it).first << " => " << (*it).second;
    }
    aux=(*it).first;
  }
  cout << endl;
}
