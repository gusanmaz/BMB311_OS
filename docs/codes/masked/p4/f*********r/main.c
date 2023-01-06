#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char* get_name(const pid_t pid){
    char path[1024] = "";
    char pids[20];
    sprintf(pids, "%d", pid);

    strcat(path, "/proc/");
    strcat(path, pids);
    strcat(path, "/cmdline");

    FILE* fp = fopen(path, "r");
    if(fp == NULL){
      printf("NULL\n");
      exit(1);
   }

   char* pname = malloc(1024);
   fscanf(fp, "%s", pname);
   return pname;
}

int main(int argc, char *argv[])
{
   int pid = atoi(argv[1]);

   char* pname = get_name(pid);

   printf("%s\n", pname);
}
