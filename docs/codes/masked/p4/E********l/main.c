#include <stdio.h>
#include <stdlib.h>

char* get_process_name_by_pid(int pid)
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
    if (argc < 2) {
        printf("Usage: %s <pid> \n", argv[0]);
        return 1;
    }

    char* process_name = get_process_name_by_pid(atoi(argv[1]));
    printf("process name: %s \n", process_name);
    
    free(process_name);
}
