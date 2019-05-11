#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<string.h>
using namespace std;

class Alumno{
        public:
        string nombre;
        string apellido;
        int ciclo;
        float mensualidad;

        void imprimir_alumnos(){
                cout << nombre << " ";
                cout << apellido << " ";
                cout << ciclo << " ";
                cout << mensualidad << endl;

        }
        void write(Alumno* temp,fstream& file){

            //fstream file;
            //file.open("data.dat",ios::out | ios::ate | ios::binary);
            if(file.is_open()){
                int tam= sizeof(int)+sizeof(float)+temp->nombre.size()+temp->apellido.size();
                file.write(reinterpret_cast<const char *>(&tam),sizeof(tam));
                file.write((char *)&temp,tam);
            }
        }
        void read(Alumno** temp,fstream& file){
            //ifstream file;
            //file.open("data.dat",ios::in  | ios::binary);

            if(file.is_open()){
                int tam=0;
                file.read((char *)&tam,sizeof(tam));
                //file.seekg(sizeof(int),ios::beg);
                file.read((char *)&*temp,tam);
                file.close();

            }
        }

};




int main(){
    fstream file;
    file.open("data.dat",ios::out | ios::ate | ios::binary);


    Alumno* alu=new Alumno;
    Alumno* read_alu=new Alumno;
    cout<<"Ingrese el nombre: "<<endl;
    cin >>alu->nombre;
    cout<<"Ingrese el apellido: "<<endl;
    cin >>alu->apellido;
    cout<<"Ingrese el ciclo: "<<endl;
    cin >>alu->ciclo;
    cout<<"Ingrese la mensualidad : "<<endl;
    cin >>alu->mensualidad;

    alu->write(alu,file);

    file.close();


    file.open("data.dat",ios::in  | ios::binary);

    read_alu->read(&read_alu,file);
    cout <<read_alu->nombre<<endl;
    cout <<read_alu->apellido<<endl;
    cout <<read_alu->ciclo<<endl;
    cout <<read_alu->mensualidad<<endl;

    delete alu;
    delete read_alu;




}
