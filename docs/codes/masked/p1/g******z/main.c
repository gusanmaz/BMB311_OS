#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
    int pids[10];

    for(int i=0; i < 10; i++) // 1023 + 1 = 1024 = 2^10
        pids[i] = fork();

    for(int i=0; i < 10; i++)
        wait(&(pids[i]));

    exit(0);
}