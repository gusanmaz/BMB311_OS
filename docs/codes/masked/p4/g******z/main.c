#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

char *get_name(const pid_t pid)
{
    char path[1024] = "";
    char pids[20];
    sprintf(pids, "%d", pid);

    strcat(path, "/proc/");
    strcat(path, pids);
    strcat(path, "/cmdline");

    FILE *fp = fopen(path, "r");
    if (fp == NULL)
    {
        printf("NULL\n");
        exit(1);
    }
    else
    {
        char *pname = malloc(1024);
        fscanf(fp, "%s", pname);
        return pname;
    }
}

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        pid_t pid = (pid_t)atoi(argv[1]);
        char *name = malloc(1024);
        sprintf(name, "%s", get_name(pid));
        char *token = strtok(name, "/");

        while (token != NULL)
        {
            name = token;
            token = strtok(NULL, "/");
        }
        printf("%s\n", name);
    }
    else
    {
        printf("NULL\n");
    }
    exit(0);
}

