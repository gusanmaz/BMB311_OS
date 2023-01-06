#include <stdio.h>
#include <stdlib.h>

char* getProcessNameByPid(int p_id)
{
    char* name = (char*)calloc(1024,sizeof(char));
    if(name){
        sprintf(name, "/proc/%d/cmdline",p_id);
        FILE* file = fopen(name,"r");
        if(file){
            size_t size;
            size = fread(name, sizeof(char), 1024, file);
            if(size>0){
                if('\n'==name[size-1])
                    name[size-1]='\0';
            }
            fclose(file);
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

    char* processName = getProcessNameByPid(atoi(argv[1]));
    printf("process name: %s \n", processName);
    
    free(processName);
}
