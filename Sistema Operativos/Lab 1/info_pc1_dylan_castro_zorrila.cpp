#include <fstream>
#include <iostream>
#include <string>
using namespace std;
int main(int argc, char** argv)
{
  /*printf("Ejercicio 1.1:  \n");
	FILE *fp;
  char caracteres[100];
	fp = popen ("grep 'model name' /proc/cpuinfo","r");
  fgets(caracteres,100,fp);
  printf("cpu ");
  printf("%s",caracteres);
  fclose (fp);
  ///////////////////////////////////////////////////
  printf("Ejercicio 1.2:  \n");
  fp = popen ("grep 'MemTotal' /proc/meminfo","r");
  fgets(caracteres,100,fp);
  printf("%s",caracteres);
  fclose (fp);
  ///////////////////////////////////////////////////
  printf("Ejercicio 1.3:  \n");
  fp = popen ("uname -r","r");
  fgets(caracteres,100,fp);
  printf("Kernel Version: ");
  printf("%s",caracteres);
  fclose (fp);
  //////////////////////////////////////////////////
  printf("Ejercicio 1.4:  \n");
  fp = popen ("uptime","r");
  fgets(caracteres,100,fp);
  //printf("Kernel Version: ");
  printf("Last time machine turn on: ");
  printf("%s",caracteres);
  fclose (fp);*/
  ///////////////////////////////////////////////
  cout << "Ejercicio 1.1" << endl;
  fstream archivo;
  string str = "";
  string sub_str = "";
  size_t pos;
  archivo.open("/proc/cpuinfo",ios::in);
  while(!archivo.eof())
  {
    getline(archivo,str);
    try{
      pos=str.find("model name");
      sub_str=str.substr(pos);
      cout << sub_str << endl;
      break;
    }
    catch(...){
    }
  }
  archivo.close();
  /////////////////////////////////////////////////
  cout << "Ejercicio 1.2" << endl;
  str = "";
  sub_str = "";
  archivo.open("/proc/meminfo",ios::in);
  while(!archivo.eof())
  {
    getline(archivo,str);
    try{
      pos=str.find("MemTotal");
      sub_str=str.substr(pos);
      cout << sub_str << endl;
      break;
    }
    catch(...){
    }
  }
  archivo.close();
  /////////////////////////////////////////////////
  cout << "Ejercicio 1.3" << endl;
  str = "";
  sub_str = "";
  archivo.open("/proc/version",ios::in);
  while(!archivo.eof())
  {
    getline(archivo,str);
    cout << str << endl;
  }
  archivo.close();
  /////////////////////////////////////////////////
  cout << "Ejercicio 1.4" << endl;
  str = "";
  int segundos;
  int horas;
  int minutos;
  archivo.open("/proc/uptime",ios::in);
  archivo >> str;
  segundos= stoi(str)%60;
  minutos=stoi(str)/60;
  horas=minutos/60;
  minutos=minutos%60;
  cout << "Tiempo de encedido del equipo: " << "Horas: " << horas << " - Minutos: " << minutos << " - Segundos: " << segundos << endl;
  archivo.close();
	return 0;
}
