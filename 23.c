#include <stdio.h>
#include <sys/resource.h>
#include <unistd.h>

int main(void) {
  struct rlimit limits;
  int fd[2];
  if (pipe(fd) == -1) {
    perror("pipe");
    return 1;
  }

  printf("Max. no. of files that can be opened: %ld\n", sysconf(_SC_OPEN_MAX));
  printf("Size of a pipe (circular buffer): %ld bytes\n",
         fpathconf(fd[0], _PC_PIPE_BUF));
  return 0;
}

// OUTPUT
/*
Max. no. of files that can be opened: 1024
Size of a pipe (circular buffer): 4096 bytes*/
