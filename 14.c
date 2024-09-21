// Name: Aryan Rastogi      RollNo. MT2024026
// 14. Write a simple program to create a pipe, write to the pipe, read from
// pipe and display on the monitor.

#include <stdio.h>
#include <unistd.h>

int main(void) {
  int fd[2];
  char buffer[10];
  pipe(fd);

  scanf("%[^\n]%*c", buffer);
  write(fd[1], buffer, sizeof(buffer));

  read(fd[0], buffer, sizeof(buffer));
  printf("%s", buffer);
  return 0;
}
