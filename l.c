#include <stdio.h>
#include <strings.h>

#include <stdlib.h>
  
void __attribute__ ((constructor)) my_init1(){
  printf("L C X22222\n");
}
void __attribute__ ((destructor)) my_init2(){
  printf("L C X22222D\n");
}

//extern void sayhi();

void x2(){
  printf("L C X2\n");
}
int loadlibrary(char*name){
  printf("L C LOAD LIBRARY [%s]\n",name);
  char*ndx = index(name,':');
  return 0;
}
int init(){
  extern void sayhi();
  sayhi();
  extern int xx;
  return printf("L C INIT <<%d>>\n", xx);
}
int main(int argc, char*argv[]){
  printf("L C MAIN <%d>\n", argc);
  printf("<<%d>>||%s %s %s %s %s||\n", argc, argv[1], argv[2], argv[3], argv[4], argv[5]);
  return 0;
}
