#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>


void print_process_id() {
    printf("Child process' id: %d\n", getpid());
}


int main() {
    int childProcess = 1023;
    int s;
    int List[childProcess];

    printf("Main process' id: %d\n", getpid());

    for (s = 0; s < childProcess; s++) {
        pid_t child_pid = fork();

        if (child_pid == 0) {  
            print_process_id();
            return 0;
        } else {
            List[s] = child_pid;
        }
    }

    for (s = 0; s < childProcess; s++) {
        wait(&List[s]);
    }


    return 0;
}
