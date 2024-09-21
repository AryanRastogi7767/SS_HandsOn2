
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
  if (s == SIGFPE) {
    printf("SIGFPE caught\n");
    exit(0);
  } else
    printf("unknown signal\n");
}

int main() {
  signal(SIGFPE, handler);
  int a = 1;
  int b = 0;
  int z = a / b;
  printf("%d", z);
  return 0;
}

// OUTPUT
// SIGFPE caught
