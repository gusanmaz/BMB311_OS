#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


void print_process_id() {
    printf("Olusturulan cocuk process = id: %d\n", getpid());
}


int main() {
    int childProcessCount = 1023;
    int value;
    int proList[childProcessCount];

    printf("Ebeveyn process' id: %d\n", getpid());

    for (value = 0; value < childProcessCount; value++) {
        pid_t child_pid = fork();

        if (child_pid == 0) {  
            print_process_id();
            return 0;
        } else {
            proList[value] = child_pid;
        }
    }

    for (value = 0; value < childProcessCount; value++) {
        wait(&proList[value]);
    }


    return 0;
}
