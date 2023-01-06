#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

char* get_name(const pid_t pid){
  char path[1024] = "";
  char pids[20];
  sprintf(pids, "%d", pid);
  //printf("%s", pids);

  strcat(path, "/proc/");
  strcat(path, pids);
  strcat(path, "/comm");
  //printf("%s", path);

  FILE* fp = fopen(path, "r");
  if(fp == NULL){
    printf("NULL");
    return "";
  }

  char* pname = malloc(1024);
  fscanf(fp, "%s", pname);
  return pname;
}

int main(int argc, char *argv[]) {
  char* pname = get_name(argv[1]);
  printf("%s\n", pname);
}
