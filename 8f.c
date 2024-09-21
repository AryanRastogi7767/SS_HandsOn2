// Name: Aryan Rastogi      RollNo. MT2024026
/*8. Write a separate program using signal system call to catch the following
signals. a. SIGSEGV b. SIGINT c. SIGFPE d. SIGALRM (use alarm system call) e.
SIGALRM (use setitimer system call) f. SIGVTALRM (use setitimer system call) g.
SIGPROF (use setitimer system call)
 */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

void handler(int s) {
  if (s == SIGVTALRM) {
    printf("SIGVTALRM caught\n");
  } else
    printf("unknown signal\n");
}

int main() {
  signal(SIGVTALRM, handler);
  struct itimerval timer;
  timer.it_value.tv_sec = 2;
  timer.it_value.tv_usec = 0;
  timer.it_interval.tv_sec = 0;
  timer.it_interval.tv_usec = 0;
  setitimer(ITIMER_VIRTUAL, &timer, NULL);
  pause();
}

// OUTPUT
// SIGALRM caught
