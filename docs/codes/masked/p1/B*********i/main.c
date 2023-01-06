#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int count = 10;

    for (int i = 0; i < count; i++)
    {
        int p_id = fork();
        if (p_id == 0)
        {
            printf("(i:%d) Child \n", i);
            wait(&p_id);
        }
        else if (p_id < 0)
        {
            printf("Fork failed\n");
            exit(1);
        }
    }

    exit(0);
}
