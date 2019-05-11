//Llamada a librerías
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <string.h>
//Declaramos los prototipos de funciones
//Función principal
//Función que permite listar un directorio de manera recursiva
void list_dir(char *nombre){

//Declaramos variables, estructuras
 struct dirent *dt;
 DIR *directorio;
 directorio = opendir(nombre);
 //Recorrer directorio
 while((dt=readdir(directorio))!=NULL){
 //strcmp permite comparar, si la comparación es verdadera devuelve un 0
 //Aquí se pregunta si el arhivo o directorio es distinto de . y ..
 //Para así asegurar que se muestre de forma recursiva los directorios y ficheros del directorio actual
 if((strcmp(dt->d_name,".")!=0)&&(strcmp(dt->d_name,"..")!=0)){
 //Si es un directorio, llamar a la misma función para mostrar archivos
 printf("%s\n",dt->d_name);
 }
 }
 closedir(directorio);
}
void current_path(){
  char cwd[PATH_MAX];
  syscall(SYS_getcwd,cwd, sizeof(cwd));
  printf("current_path: %s\n", cwd);
}
void create_dir(char *nombre){
  syscall(SYS_mkdir,nombre,0777);
}
void change_dir(char *nombre){
  if(nombre=="cd.."){
    syscall(SYS_chdir,"..");
    current_path();
  }else{
    syscall(SYS_chdir,nombre);
    current_path();
  }
}
main(int argc, char **argv)
{
 //Limpiamos la pantalla

 //lista_directorio(argv[1]);

 //Llamamos a la función
 //list_dir(".");
 current_path();
 change_dir("..");
}
