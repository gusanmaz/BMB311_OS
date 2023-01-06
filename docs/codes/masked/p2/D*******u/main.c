#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>



void get_ppid(const pid_t pid, pid_t *ppid)
{   

    char bfr[1024]; 
    sprintf(bfr, "/proc/%d/stat", pid);
    FILE *fn = fopen(bfr, "r");
   
    if (fn)
    {
        size_t sz = fread(bfr, sizeof(char), sizeof(bfr), fn);
        if (sz > 0)
        {
            
            
            strtok(bfr, " ");              
            strtok(NULL, " ");                
            strtok(NULL, " ");                
            char *s_ppid = strtok(NULL, " "); 
            *ppid = atoi(s_ppid);
        }
        fclose(fn);
    }
}



char *get_name(const pid_t pid)
{
    char pt[1024] = "";
    char ps[20];
    sprintf(ps, "%d", pid);

    strcat(pt, "/proc/");
    strcat(pt, ps);
    strcat(pt, "/cmdline");

    FILE *fn = fopen(pt, "r");
    if (fn == NULL)
    {
        printf("Cannot open the file!");
        exit(1);
    }

    char *pnm = malloc(1024);
    fscanf(fn, "%s", pnm);
    return pnm;
}


void print_process_info(const pid_t pid, pid_t ppid, char *pnm)
{
    printf("%-20d%-20d%-50s\n", pid, ppid, pnm);
}


void print_header()
{
    printf("%-20s%-20s%-50s\n", "ID", "Parent ID", "Command");
}

int main(int argc, char *argv[])
{
    int pid;
    int ppid;

    
    print_header();
	
   
    pid = getpid();

    do
    {
		
        get_ppid(pid, &ppid);
        
     
        print_process_info(pid, ppid, get_name(pid));
        pid = ppid;

    } while (ppid != 0);
}
 
