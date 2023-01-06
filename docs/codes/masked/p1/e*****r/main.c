#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>


void print_process_id() {
    printf("Child process' id: %d\n", getpid());
}


int main() {
    int childProcessCount = 1023;
    int i;
    int processList[childProcessCount];

    printf("Main process' id: %d\n", getpid());

    for (i = 0; i < childProcessCount; i++) {
        pid_t child_pid = fork();

        if (child_pid == 0) {  
            print_process_id();
            return 0;
        } else {
            processList[i] = child_pid;
        }
    }

    for (i = 0; i < childProcessCount; i++) {
        wait(&processList[i]);
    }


    return 0;
}
