#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int cnt = 10;

    for (int i = 0; i < cnt; i++)
    {
        int processid = fork();
        if (processid == 0)
        {
            printf("(i:%d) Child \n", i);
            wait(&processid);
        }
        else if (processid < 0)
        {
            printf("Fork failed\n");
            exit(1);
        }
    }
    exit(0);
}
