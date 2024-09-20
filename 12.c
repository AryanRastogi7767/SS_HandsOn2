#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  pid_t pid = fork();
  if (pid < 1)
    perror("fork");
  if (pid == 0) {
    printf("Parent pid: %d\nChild pid: %d\n", getppid(), getpid());
    sleep(1);
    printf("SIGKILL to parent\n");
    kill(getppid(), SIGKILL);
    sleep(2);
    printf("Parent pid:%d\n", getppid());
  } else {
    printf("Parent pid: %d\n", getpid());
    sleep(5);
  }
}

// OUTPUT
// Parent pid: 11576
// fork: Success
// Parent pid: 11576
// Child pid: 11577
// SIGKILL to parent
// Killed
