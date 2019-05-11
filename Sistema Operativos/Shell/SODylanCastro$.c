//Llamada a librerías
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <string.h>
void list_dir(){
 struct dirent *dt;
 DIR *directorio;
 directorio = opendir(".");
 while((dt=readdir(directorio))!=NULL){
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
void remove_dir(char *nombre){
  syscall(SYS_rmdir,nombre);
}
void remove_file(char *nombre){
  syscall(SYS_unlink,nombre);
}
main(int argc, char **argv)
{
 //list_dir();
 //current_path();
 //change_dir("a");
 //create_dir("a");
 //remove_dir("a");
 //remove_file("a");
}
