#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include<unistd.h>
#include <string.h>
#include <pthread.h>
#include <assert.h>


int pid;


const char* get_process_isim_pid(const int pid)
{
    char* name = (char*)calloc(1024,sizeof(char));
    if(name){
        sprintf(name, "/proc/%d/cmdline",pid);
        FILE* f = fopen(name,"r");
        if(f){
            size_t size;
            size = fread(name, sizeof(char), 1024, f);
            if(size>0){
                if('\n'==name[size-1])
                    name[size-1]='\0';
            }
            fclose(f);
        }
    }
    return name;
}
int main(int argc, char *argv[])
{
    if (argc>1)
    {
        long arg = strtol(argv[1], NULL, 10);
      pid=arg;

        if (strstr(get_process_isim_pid(pid), "cmdline") != NULL) {
    // contains
        printf("NULL \n");
}
        else{
      
        printf("KOMUT : %s ",get_process_isim_pid(pid));
      }
    }
    
       
       
       
       
}
