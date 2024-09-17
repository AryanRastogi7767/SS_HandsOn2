#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

int main(void) {
  int fd = open("special_fifo", O_RDONLY);
  char *buff;
  read(fd, buff, sizeof(buff));
  printf("Message by prcess1: %s\n", buff);
  return 0;
}
