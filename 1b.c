#include <signal.h>
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

void handler(int signal) { printf("ITIMER_VIRTUAL triggered\n"); }

int main() {
  struct itimerval t;
  signal(SIGVTALRM, handler);
  t.it_value.tv_sec = 10;
  t.it_value.tv_usec = 10;
  t.it_interval.tv_sec = 10;
  t.it_interval.tv_usec = 10;
  setitimer(ITIMER_VIRTUAL, &t, NULL);
  while (1) {
  }
  return 0;
}

// OUTPUT
// ITIMER_VIRTUAL triggered
