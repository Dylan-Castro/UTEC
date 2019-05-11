#include <fstream>
#include <iostream>
#include <string>
#include <unistd.h>
using namespace std;
void Ejercicio_2_1(){
    fstream archivo;
    string str = "";
    string MemTotal = "";
    string MemAvailable = "";
    archivo.open("/proc/meminfo",ios::in);
    while(!archivo.eof())
    {
      getline(archivo,str);
      if(str.find("MemTotal")!=string::npos){
        for(int x=0;x<str.size();x++){
          if(char(str[x])>=48 && char(str[x])<=57){
            MemTotal=MemTotal+str[x];
          }
        }
      }
      if(str.find("MemAvailable")!=string::npos){
        for(int x=0;x<str.size();x++){
          if(char(str[x])>=48 && char(str[x])<=57){
            MemAvailable=MemAvailable+str[x];
          }
        }
      }
    }
    archivo.close();
    cout << "Mem Available(%): " << stof(MemAvailable)*100/stof(MemTotal) <<"%"<< endl;
}
void Ejercicio_2_2(){
  fstream archivo;
  string str = "";
  int total_cpu_time=0;
  int user_mode_time=0;
  int system_mode_time=0;
  int idle_time=0;
  archivo.open("/proc/stat",ios::in);
  archivo >> str;
  for (int i = 1; i <= 10; i++) {
    archivo >> str;
    if(i==1){
      user_mode_time+=stoi(str);
    }
    else if(i==3){
      system_mode_time+=stoi(str);
    }
    else if(i==4){
      idle_time+=stoi(str);
    }
    total_cpu_time+=stoi(str);
  }
  cout << "Time in user mode(%): " << user_mode_time*100/total_cpu_time <<"%"<< endl;
  cout << "Time in system mode(%): " << system_mode_time*100/total_cpu_time <<"%"<< endl;
  cout << "Time in idle(%): " << idle_time*100/total_cpu_time <<"%"<< endl;
}
void Ejercicio_2_3(){
  fstream archivo;
    archivo.open("/proc/stat",ios::in);
    string str = "";
    string context_switches="";
  while(!archivo.eof())
  {
    getline(archivo,str);
    if(str.find("ctxt")!=string::npos){
      for(int x=0;x<str.size();x++){
        if(char(str[x])>=48 && char(str[x])<=57){
          context_switches=context_switches+str[x];
        }
      }
      break;
    }
  }
  archivo.close();
  cout << "La tasa de cambios de contexto en el kernel es :" << context_switches << endl;

}
void Ejercicio_2_4(){
  fstream archivo;

    archivo.open("/proc/stat",ios::in);
    string str = "";
    string procceses_created="";
  while(!archivo.eof())
  {
    getline(archivo,str);
    if(str.find("processes")!=string::npos){
      for(int x=0;x<str.size();x++){
        if(char(str[x])>=48 && char(str[x])<=57){
          procceses_created=procceses_created+str[x];
        }
      }
      break;
    }
  }
  archivo.close();
  cout << "La tasa de procesos en el sistema es :" << procceses_created << endl;

}
int main(int argc, char** argv)
{
  while(true){
    system("clear");
    cout << "Ejercicio 2.1" << endl;
    Ejercicio_2_1();
    cout << "Ejercicio 2.2" << endl;
    Ejercicio_2_2();
    cout << "Ejercicio 2.3" << endl;
    Ejercicio_2_3();
    cout << "Ejercicio 2.4" << endl;
    Ejercicio_2_4();
    usleep(1000000);
  }
	return 0;
}
