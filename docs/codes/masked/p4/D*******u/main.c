#include <stdio.h>
#include <stdlib.h>




char* GetProcessName(int pid)
{
    char* rc = (char*)calloc(1024,sizeof(char));

    if(rc){
      
        sprintf(rc, "/proc/%d/cmdline",pid);
      
        FILE* fp = fopen(rc,"r");
        if(fp){
            size_t size;
            size = fread(rc, sizeof(char), 1024, fp);
            if(size>0){
                if('\n'==rc[size-1])
                    rc[size-1]='\0';
            }
            fclose(fp);
        }
    }
    return rc;
}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("Usage: %s <pid> \n", argv[0]);
        return 1;
    }

    char* processname = GetProcessName(atoi(argv[1]));
    printf("process name: %s \n", processname);
    
    
    free(processname);
}


//./main 1681 //mysql
//./main 1515 //NULL
//./main 13228 //nginx
