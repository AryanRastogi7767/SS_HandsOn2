
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void sig(int sig, siginfo_t *info, void *args) {
  if (sig == SIGSEGV) {
    printf("SIGSEGV caught");
    exit(0);
  }
}

int main() {
  struct sigaction s;
  s.sa_flags = SA_SIGINFO;
  s.sa_sigaction = sig;
  sig(SIGSEGV, &s, NULL);

  int *ptr = NULL;
  *ptr = 1;
}
