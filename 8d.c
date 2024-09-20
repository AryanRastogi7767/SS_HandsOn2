#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

void handler(int s) {
  if (s == SIGALRM) {
    printf("SIGALRM caught\n");
  } else
    printf("unknown signal\n");
}

int main() {
  signal(SIGALRM, handler);
  alarm(2);
  pause();
}

// OUTPUT
// SIGALRM caught
