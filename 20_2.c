#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

int main(void) {
  int fd = open("special_fifo", O_RDONLY);
  char buff[80];
  read(fd, buff, sizeof(buff));
  printf("Message by prcess1: %s\n", buff);
  return 0;
}

// OUTPUT
// Message by prcess1: This is p1 one way comm
