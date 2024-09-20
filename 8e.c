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
  struct itimerval timer;
  timer.it_value.tv_sec = 2;
  timer.it_value.tv_usec = 0;
  timer.it_interval.tv_sec = 0;
  timer.it_interval.tv_usec = 0;
  setitimer(ITIMER_REAL, &timer, NULL);
  pause();
}

// OUTPUT
// SIGALRM caught
