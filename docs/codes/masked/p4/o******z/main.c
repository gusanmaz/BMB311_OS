#include <stdio.h>
#include <stdlib.h>

char* get_process_by_pid(int pid)
{
    char* isim = (char*)calloc(1024,sizeof(char));
    if(isim){
        sprintf(isim, "/proc/%d/cmdline",pid);
        FILE* f = fopen(isim,"r");
        if(f){
            size_t size;
            size = fread(isim, sizeof(char), 1024, f);
            if(size>0){
                if('\n'==isim[size-1])
                    isim[size-1]='\0';
            }
            fclose(f);
        }
    }
    return isim;
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("Usage: %s <pid> \n", argv[0]);
        return 1;
    }

    char* processName = get_process_by_pid(atoi(argv[1]));
    printf("process name: %s \n", processName);
    
    free(processName);
}
