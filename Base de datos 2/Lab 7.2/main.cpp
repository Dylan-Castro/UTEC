#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
vector<string> Stopwords;
vector<string>::iterator it;
multimap<string, int> terminos_frecuentes;
map<string, bool> validar_terminos;
vector<string> comprobar_ubicacion_palabra(6, "0");
string data;

void calcular_concurrencia(string filename, int nro_libro)
{
  fstream libro(filename);
  while (!libro.eof())
  {
    libro >> data;
    transform(data.begin(), data.end(), data.begin(), ::toupper);
    if (data[data.length() - 1] == '.' || data[data.length() - 1] == ',' ||
        data[data.length() - 1] == ')')
    {
      data = data.substr(0, data.length() - 1);
    }
    if (data[0] == '(')
    {
      data = data.substr(1);
    }
    it = find(Stopwords.begin(), Stopwords.end(), data);
    if (it == Stopwords.end())
    {
      if (validar_terminos.count(data) == 0)
      {
        validar_terminos[data] = 1;
        terminos_frecuentes.insert(std::pair<string, int>(data, nro_libro));
      }
    }
  }
  libro.close();
  validar_terminos.clear();
}

void imprimir_concurrencia()
{
  string aux = "";
  for (std::multimap<string, int>::iterator it = terminos_frecuentes.begin();
       it != terminos_frecuentes.end(); ++it)
  {
    if (aux == (*it).first)
    {
      cout << " " << (*it).second;
    }
    else
    {
      cout << endl;
      cout << (*it).first << " => Aparece en los libros: " << (*it).second;
    }
    aux = (*it).first;
  }
  cout << endl;
}

void Guardar_Indice_Invertido()
{
  ofstream fichero("Indice_Invertido.txt");
  string aux = "";
  for (std::multimap<string, int>::iterator it = terminos_frecuentes.begin();
       it != terminos_frecuentes.end(); ++it)
  {
    if (aux == (*it).first)
    {
      fichero << " " << (*it).second;
    }
    else
    {
      if (aux != "")
      {
        fichero << endl;
      }
      fichero << (*it).first << " => Aparece en los libros: " << (*it).second;
    }
    aux = (*it).first;
  }
  fichero.close();
}

void Similitud_de_coseno(vector<string> query)
{
  map<string, int> tweets_utiles;
  map<string, int> temp;
  for (size_t i = 0; i < query.size(); i++)
  {
    if (mymap.count(query[i]) == 0)
    {
      return;
    }
    for (std::map<string, map<string, int>>::iterator it2 =
             mymap[query[i]].begin();
         it2 != mymap[query[i]].end(); ++it2)
    {
      if (i == 0)
      {
        tweets_utiles.insert(std::pair<string, int>(it->first, it->second));
      }
      else
      {
        if (tweets_utiles.count(it->first) > 0)
        {
          temp.insert(std::pair<string, int>(it->first, it->second));
        }
      }
    }
    tweets_utiles.clear();
    tweets_utiles = temp;
    temp.clear();
  }
}
int main()
{
  fstream file("tweets_2018-09-30.json");
  while (!file.eof())
  {
    file >> data;
    Stopwords.push_back(data);
    cout << data << endl;
  }

  /////////////////////////////////////////////////
  /*calcular_concurrencia("libros/libro1.txt", 1);
  calcular_concurrencia("libros/libro2.txt", 2);
  calcular_concurrencia("libros/libro3.txt", 3);
  calcular_concurrencia("libros/libro4.txt", 4);
  calcular_concurrencia("libros/libro5.txt", 5);
  calcular_concurrencia("libros/libro6.txt", 6);*/
  // Guardar_Indice_Invertido();
  /////////////////////////////////////////////////
  // Nota para el profesor: Descomentar para su uso
  // calcular_50_primeros();
  // imprimir_concurrencia();
  // consulta_booleana(); // Compilador: output < querys.text
}
