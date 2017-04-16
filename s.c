#include <stdio.h>
extern int*x0;
int x2 = 0x99;
int*x0 =&x2;

int xx = 102;
void sayhi(){
  printf("HI S.C!\n");
}

void init(){
  printf("S C INIT\n");
}
int x1(int argc,char*argv[]){
  return printf("X1 %d %s\n", argc, argv[1]);
}
