#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
int main() {
  int fd1[2];
  int fd2[2];

  pid_t pid1, pid2, pid3;
  if (pipe(fd1) < 0) {
    perror("pipe");
    exit(0);
  }
  pid1 = fork();
  if (pid1 < 0) {
    perror("fork");
  }

  if (pid1 == 0) {
    dup2(fd1[1], STDOUT_FILENO); // redirect stdout to pipes write end
    close(fd1[0]);
    close(fd1[1]);
    execlp("ls", "ls", "-l", (char *)NULL);
    perror("execlp");
    exit(0);
  }
  if (pipe(fd2) < 0) {
    perror("pipe");
    exit(0);
  }
  pid2 = fork();
  if (pid2 < 0)
    perror("fork");
  if (pid2 == 0) {
    dup2(fd1[1], STDIN_FILENO);  // redirect stdout to pipes write end
    dup2(fd2[1], STDOUT_FILENO); // redirect stdout to pipes write end
    close(fd1[1]);
    close(fd1[0]);
    close(fd2[0]);
    close(fd2[1]);
    execlp("grep", "grep", "^d", (char *)NULL);
    perror("execlp");
    exit(0);
  }
  close(fd1[0]);
  close(fd1[1]);

  pid3 = fork();
  if (pid3 < 0)
    perror("fork");
  if (pid3 == 0) {
    dup2(fd2[0], STDIN_FILENO); // redirect stdin to pipes read end
    close(fd2[1]);
    close(fd2[0]);
    execlp("wc", "wc", "-l", (char *)NULL);
    perror("execlp");
    exit(0);
  }
  close(fd2[0]);
  close(fd2[1]);
  wait(NULL);
  wait(NULL);
  wait(NULL);
}
