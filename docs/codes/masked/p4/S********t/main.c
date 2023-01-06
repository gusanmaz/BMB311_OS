#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

char* get_path(const pid_t pid){
    char path[1024] = "";
    char pids[20];
    sprintf(pids, "%d", pid);

    strcat(path, "/proc/");
    strcat(path, pids);
    strcat(path, "/cmdline");

    FILE* fp = fopen(path, "r");
    if(fp == NULL){
      //printf("Cannot open the file!");
      //exit(1);
      char* pname = malloc(1);
      *pname = '\0';
      return pname;
    }

    char* pname = malloc(1024);
    fscanf(fp, "%s", pname);
    return pname;
}

int main(int argc, char *argv[])
{
    if(argc != 2) {
        printf("./main process_adi\n");
        exit(1);
    }
    int pid = atoi(argv[1]);
    char* path = get_path(pid);
    char* next_char = path;
    int i = 0;
    int start = 0;
    while('\0' != *next_char) {
        if('/' == *next_char) {
            start = i+1;
        }
        i++;
        next_char++;
    }
    if(0 == start) {
        printf("NULL\n");
    } else {
        printf("%s\n", (path+start));
    }
    free(path);
}
