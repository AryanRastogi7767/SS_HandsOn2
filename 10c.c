// Name: Aryan Rastogi      RollNo. MT2024026
/*10. Write a separate program using sigaction system call to catch the
following signals. a. SIGSEGV b. SIGINT c. SIGFPE*/
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void sig(int sig, siginfo_t *info, void *args) {
  if (sig == SIGFPE) {
    printf("SIGFPE caught");
    exit(0);
  }
}

int main() {
  struct sigaction s;
  s.sa_flags = SA_SIGINFO;

  int a = 5;
  int b = 0;
  s.sa_sigaction = sig;
  sigaction(SIGFPE, &s, NULL);

  int z = a / b;
  printf("%d", z);
}

// OUTPUT
// SIGFPE caught
