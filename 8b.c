
// Name: Aryan Rastogi      RollNo. MT2024026
/*8. Write a separate program using signal system call to catch the following
signals. a. SIGSEGV b. SIGINT c. SIGFPE d. SIGALRM (use alarm system call) e.
SIGALRM (use setitimer system call) f. SIGVTALRM (use setitimer system call) g.
SIGPROF (use setitimer system call)
 */
#include <signal.h>
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

void handler(int s) {
  if (s == SIGINT) {
    printf("SIGINT caught\n");
  } else
    printf("unknown signal\n");
}

int main() {
  signal(SIGINT, handler);
  pause();
}

// OUTPUT
//^CSIGINT caught
