#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
int main(void) {

  if (mknod("special_file", S_IFIFO | 0666, 0) == -1) {
    perror("FIFO error");
  }
  return 0;
}
