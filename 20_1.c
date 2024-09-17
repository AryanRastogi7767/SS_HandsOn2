#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

int main(void) {
  int fd = open("special_fifo", O_RDWR);
  char buff[80];
  scanf("%[^\n]", buff);
  write(fd, buff, sizeof(buff));
  return 0;
}
