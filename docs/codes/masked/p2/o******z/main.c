#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

void get_ppid(const pid_t processid, pid_t *pprocessid)
{
    char bfr[1024];
    sprintf(bfr, "/proc/%d/stat", processid);
    FILE *fp = fopen(bfr, "r");
    if (fp)
    {
        size_t size = fread(bfr, sizeof(char), sizeof(bfr), fp);
        if (size > 0)
        {
            strtok(bfr, " ");             
            strtok(NULL, " ");                
            strtok(NULL, " ");                
            char *s_pprocess_id = strtok(NULL, " ");
            *pprocessid = atoi(s_pprocess_id);
        }
        fclose(fp);
    }
}

char *get_name(const pid_t processid)
{
    char path[1024] = "";
    char processids[20];
    sprintf(processids, "%d", processid);

    strcat(path, "/proc/");
    strcat(path, processids);
    strcat(path, "/cmdline");

    FILE *fp = fopen(path, "r");
    if (fp == NULL)
    {
        printf("Cannot open the file!");
        exit(1);
    }

    char *processname = malloc(1024);
    fscanf(fp, "%s", processname);
    return processname;
}

void print_process_info(const pid_t processid, pid_t pprocessid, char *processname)
{
    printf("%-20d%-20d%-50s\n", processid, pprocessid, processname);
}

void print_header()
{
    printf("%-20s%-20s%-50s\n", "ID", "Parent ID", "Command");
}

int main(int argc, char *argv[])
{
    int processid;
    int pprocessid;

    print_header();
    processid = getpid();

    do
    {
        get_ppid(processid, &pprocessid);
        print_process_info(processid, pprocessid, get_name(processid));
        processid = pprocessid;

    } while (pprocessid != 0);
}
