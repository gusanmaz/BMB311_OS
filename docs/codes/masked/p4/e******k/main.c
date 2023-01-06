#include <stdio.h>
#include <stdlib.h>

int read(char *path){
 char pname[50];
 FILE *fp = fopen(path,"r");
 if (fp == NULL){
  printf("%s","NULL\n");
  return -1;
 }
 if (fgets (pname, 50, fp) == NULL){
  printf("%s","NULL\n");
  return -1;
 }
 printf("%s",pname);
 fclose(fp);
}
int main(int argc, char** argv) {
 if (argc != 2) {
  printf("parameters failed.");
  return 1;
 }
 char proc_path[50];
 sprintf(proc_path, "/proc/%s/comm", argv[1]);
 read(proc_path);
}
