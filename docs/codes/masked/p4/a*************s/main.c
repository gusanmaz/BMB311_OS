#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
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
      printf("NULL");
      exit(1);
   }

   char* pname = malloc(1024);
   fscanf(fp, "%s", pname);
   return pname;
}

void print_process_info(char* pname){
    printf("%-50s\n", pname);
}    

int main(int argc, char *argv[])
{

    int pid;
    pid = getpid();
    scanf("%d", &pid);

    
    char* pname = get_name(pid);
    print_process_info(pname);
    free(pname);
    
}
