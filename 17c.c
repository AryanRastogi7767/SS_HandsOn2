// Name: Aryan Rastogi      RollNo. MT2024026
/*17. Write a program to execute ls -l | wc.
a. use dup
b. use dup2
c. use fcntl
 */
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
int main(void) {
  int fd[2];
  pipe(fd);

  if (!fork()) {
    close(1);
    close(fd[0]);
    fcntl(fd[1], F_DUPFD);
    execlp("ls", "ls", "-l", NULL);
  } else {
    close(0);
    close(fd[1]);
    fcntl(fd[0], F_DUPFD);
    execlp("wc", "wc", NULL);
  }
  return 0;
}

// OUTPUT
//  33     290    1615
