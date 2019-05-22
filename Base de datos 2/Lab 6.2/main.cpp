#include <iostream>
#include <stdio.h>
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
vector<string> comprobar_ubicacion_palabra(6, "0");
string data;

void calcular_concurrencia(string filename, int nro_libro) {
  fstream libro(filename);
  while (!libro.eof()) {
    libro >> data;
    transform(data.begin(), data.end(), data.begin(), ::toupper);
    if (data[data.length() - 1] == '.' || data[data.length() - 1] == ',' || data[data.length() - 1] == ')') {
      data = data.substr(0, data.length() - 1);
    }
    if (data[0] == '(') {
      data = data.substr(1);
    }
    it = find(Stopwords.begin(), Stopwords.end(), data);
    if (it == Stopwords.end()) {
      if (validar_terminos.count(data) == 0) {
        validar_terminos[data] = 1;
        terminos_frecuentes.insert(std::pair<string, int>(data, nro_libro));
      }
    }
  }
  libro.close();
  validar_terminos.clear();
}
void imprimir_concurrencia() {
  string aux = "";
  for (std::multimap<string, int>::iterator it = terminos_frecuentes.begin(); it != terminos_frecuentes.end(); ++it) {
    if (aux == (*it).first) {
      cout << " " << (*it).second;
    } else {
      cout << endl;
      cout << (*it).first << " => Aparece en los libros: " << (*it).second;
    }
    aux = (*it).first;
  }
  cout << endl;
}
void calcular_50_primeros() {
  vector<string> palabras;
  vector<int> concurrencia;
  string aux = "";
  for (std::multimap<string, int>::iterator it = terminos_frecuentes.begin(); it != terminos_frecuentes.end(); ++it) {
    if (aux != (*it).first) {
      palabras.push_back((*it).first);
      concurrencia.push_back(terminos_frecuentes.count((*it).first));
    }
    aux = (*it).first;
  }
  //Reverse Insertion Sort
  int temp1;
  string temp2;
  for (int x = 1; x < concurrencia.size(); x++) {
    for (int y = x; y > 0; y--) {
      if (concurrencia[y - 1] < concurrencia[y]) {
        temp1 = concurrencia[y];
        concurrencia[y] = concurrencia[y - 1];
        concurrencia[y - 1] = temp1;
        //////////////////////////
        temp2 = palabras[y];
        palabras[y] = palabras[y - 1];
        palabras[y - 1] = temp2;
      }
    }
  }
  //Imprimir los 50 primeros
  int nro_de_impresiones = 50;
  if (palabras.size() < 50) {
    nro_de_impresiones = palabras.size();
  }
  for (int i = 0; i < nro_de_impresiones; ++i) {
    cout << palabras[i] << ": " << concurrencia[i] << endl;
  }
}
string operacion(string recuperador1, string operador, string recuperador2) {
  string resultado = "";
  if (operador == "and") {
    for (int i = 0; i < 6; i++) {
      if (recuperador1[i] == '1' && recuperador2[i] == '1') {
        resultado += "1";
      } else if (recuperador1[i] == '0' || recuperador2[i] == '0') {
        resultado += "0";
      }
    }
  } else if (operador == "or") {
    for (int i = 0; i < 6; i++) {
      if (recuperador1[i] == '1' || recuperador2[i] == '1') {
        resultado += "1";
      } else if (recuperador1[i] == '0' && recuperador2[i] == '0') {
        resultado += "0";
      }
    }
  } else if (operador == "and_not") {

    for (int i = 0; i < 6; i++) {
      if (recuperador2[i] == '0') {
        recuperador2[i] = '1';
      } else {
        recuperador2[i] = '0';
      }
      if (recuperador1[i] == '1' && recuperador2[i] == '1') {
        resultado += "1";
      } else if (recuperador1[i] == '0' || recuperador2[i] == '0') {
        resultado += "0";
      }
    }
  } else if (operador == "or_not") {
    for (int i = 0; i < 6; i++) {
      if (recuperador2[i] == '0') {
        recuperador2[i] = '1';
      } else {
        recuperador2[i] = '0';
      }
      if (recuperador1[i] == '1' || recuperador2[i] == '1') {
        resultado += "1";
      } else if (recuperador1[i] == '0' && recuperador2[i] == '0') {
        resultado += "0";
      }
    }
  }
  return resultado;
}
string convertir_a_binario(string recuperador) {
  for (multimap<string, int>::iterator ate = terminos_frecuentes.find(recuperador); ate != terminos_frecuentes.end();
       ++ate) {
    if ((*ate).first == recuperador) {
      comprobar_ubicacion_palabra[(*ate).second - 1] = "1";
    } else {
      break;
    }
  }
  string resultado = "";
  for (int i = 0; i < 6; ++i) {
    resultado = resultado + comprobar_ubicacion_palabra[i];
    comprobar_ubicacion_palabra[i] = "0";
  }
  return resultado;
}
void respuesta_booleana(string resultado) {
  if (resultado[0] == '1') {
    cout << "Libro 1, ";
  }
  if (resultado[1] == '1') {
    cout << "Libro 2, ";
  }
  if (resultado[2] == '1') {
    cout << "Libro 3, ";
  }
  if (resultado[3] == '1') {
    cout << "Libro 4, ";
  }
  if (resultado[4] == '1') {
    cout << "Libro 5, ";
  }
  if (resultado[5] == '1') {
    cout << "Libro 6";
  }
}
void consulta_booleana() {
  //Escribir "0" para cerrar
  string recuperador1;
  string recuperador2;
  string operador;
  string resultado;
  while (true) {
    cin >> recuperador1;
    if (recuperador1 == "0")
      break;
    recuperador1 = convertir_a_binario(recuperador1);
    cout << recuperador1 << endl;
    cin >> operador;
    if (operador == "0")
      break;
    cin >> recuperador2;
    if (recuperador2 == "0")
      break;
    recuperador2 = convertir_a_binario(recuperador2);
    cout << recuperador2 << endl;
    resultado = operacion(recuperador1, operador, recuperador2);
    while (true) {
      cin >> operador;
      if (operador == "0")
        break;
      cin >> recuperador2;
      if (recuperador2 == "0")
        break;
      recuperador2 = convertir_a_binario(recuperador2);
      cout << recuperador2 << endl;
      resultado = operacion(resultado, operador, recuperador2);
    }
    cout << "Resultado: " << resultado << endl;
    respuesta_booleana(resultado);
    cout << endl << endl;
  }
}
void Guardar_Indice_Invertido() {
  ofstream fichero("Indice_Invertido.txt");
  string aux = "";
  for (std::multimap<string, int>::iterator it = terminos_frecuentes.begin(); it != terminos_frecuentes.end(); ++it) {
    if (aux == (*it).first) {
      fichero << " " << (*it).second;
    } else {
      if (aux != "") {
        fichero << endl;
      }
      fichero << (*it).first << " => Aparece en los libros: " << (*it).second;
    }
    aux = (*it).first;
  }
  fichero.close();
}
int main() {
  fstream file("stopwords.txt");
  while (!file.eof()) {
    file >> data;
    Stopwords.push_back(data);
  }
  /////////////////////////////////////////////////
  calcular_concurrencia("libros/libro1.txt", 1);
  calcular_concurrencia("libros/libro2.txt", 2);
  calcular_concurrencia("libros/libro3.txt", 3);
  calcular_concurrencia("libros/libro4.txt", 4);
  calcular_concurrencia("libros/libro5.txt", 5);
  calcular_concurrencia("libros/libro6.txt", 6);
  //Guardar_Indice_Invertido();
  /////////////////////////////////////////////////
  //Nota para el profesor: Descomentar para su uso
  //calcular_50_primeros();
  //imprimir_concurrencia();
  consulta_booleana(); // Compilador: output < querys.text
}
