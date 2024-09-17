#include <stdio.h>
#include <unistd.h>
int main(void) {
  long PIPE_BUF, OPEN_MAX;
  PIPE_BUF = pathconf(".", _PC_PIPE_BUF);
  OPEN_MAX = sysconf(_SC_OPEN_MAX);
  printf("Pipe_buf = %ld\t OPEN MAX =OPEN_MAX %ld\n", PIPE_BUF, OPEN_MAX);
}
