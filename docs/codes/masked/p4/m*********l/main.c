#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <assert.h>

int pid_degeri;

const char* get_process_name_pid(const int pid_degeri)
{
    char* name = (char*)calloc(1024,sizeof(char));
    if(name)
    {
        sprintf(name, "/proc/%d/cmdline",pid_degeri);
        FILE* fl = fopen(name,"r");
        if(fl)
        {
            size_t size;
            size = fread(name, sizeof(char), 1024, fl);
            if(size>0)
            {
                if('\n'==name[size-1])
                    name[size-1]='\0';
            }
            fclose(fl);
        }
    }
    return name;
}
int main(int argc, char *argv[])
{
    if (argc>1)
    {
        long arg = strtol(argv[1], NULL, 10);
      pid_degeri=arg;

        if (strstr(get_process_name_pid(pid_degeri), "cmdline") != NULL) 
        {
            printf("NULL \n");
        }
        else
        {
            printf("%s \n",get_process_name_pid(pid_degeri));
        }
    }
}
