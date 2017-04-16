#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int(*loadlibrary)(char*name)=0;

static inline void*loadlib(char*libname){
  void*lib = 0, (*sym)() = 0; int f = RTLD_LAZY|RTLD_GLOBAL;
  if( (lib = dlopen(libname, f|RTLD_NOLOAD))) return lib;
  if(!(lib = dlopen(libname, f))){puts(dlerror());return 0;}
  if((sym = dlsym(lib, "init"))) sym();
  return lib;}
  
//extern void sayhi();
//void sayhi(){
//  printf("HI!\n");
//}
    
int main(int argc, char*argv[]){
  printf("<<%d>>||%s %s %s %s %s||\n", argc, argv[1], argv[2], argv[3], argv[4], argv[5]);
  char *lname = 0; void*lib = 0; void*(*sym)() = 0;
  for(int n=1; n<argc; n++)
    lib = loadlib(argv[n]);
  if((sym = dlsym(lib, "main"))) return(long)sym(argc,argv);
  else{printf("Not-Found %p:%s:main\n",lib,argv[argc-1]);return 1;}}
