// Name: Aryan Rastogi      RollNo. MT2024026
/*17. Write a program to execute ls -l | wc.
a. use dup
b. use dup2
c. use fcntl
 */

#include <stdio.h>
#include <unistd.h>

int main(void) {
  int fd[2];
  pipe(fd);

  if (!fork()) {
    close(1);
    close(fd[0]);
    dup(fd[1]);
    execlp("ls", "ls", "-l", NULL);
  } else {
    close(0);
    close(fd[1]);
    dup(fd[0]);
    execlp("wc", "wc", NULL);
  }
  return 0;
}

// OUTPUT
//  31     272    1515
