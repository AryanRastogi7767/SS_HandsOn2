#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void sig(int sig, siginfo_t *info, void *args) {
  if (sig == SIGINT) {
    printf("SIGINT caught");
  }
}

int main() {
  struct sigaction s;
  s.sa_flags = SA_SIGINFO;
  s.sa_sigaction = sig;
  sigaction(SIGINT, &s, NULL);

  printf("waiting for ctrl + c\n");
  sleep(10);
}
// OUTPUT
// waiting for ctrl + c
//^CSIGINT caught
