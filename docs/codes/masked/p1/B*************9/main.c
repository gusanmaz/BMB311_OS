#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
pid_t pids[1023];
int i;
int n = 1023;

/* Start children. */
for (i = 0; i < n; ++i) {
  if ((pids[i] = fork()) < 0) {
    perror("fork");
    abort();
  } else if (pids[i] == 0) {
    exit(0);
  }
}

/* Wait for children to exit. */
int status;
pid_t pid;
while (n > 0) {
  pid = wait(&status);
  printf("Child with PID %ld exited with status 0x%x.\n", (long)pid, status);
  --n;  // TODO(pts): Remove pid from the pids array.
}
}
