#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

  for (int i = 1; i <= 1023; i++) {
    pid_t pid = fork();

    if (pid == 0) {
      printf("%d-%d\n", getppid(), getpid());
      exit(0);
    } else {
      wait(NULL);
    }
  }

  return EXIT_SUCCESS;
}
