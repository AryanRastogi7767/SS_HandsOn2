// Name: Aryan Rastogi      RollNo. MT2024026
// 11. Write a program to ignore a SIGINT signal then reset the default action
// of the SIGINT signal - use sigaction system call.

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void sig(int sig, siginfo_t *info, void *args) {
  if (sig == SIGINT) {
    printf("SIGINT ignored \n");
  }
}

int main() {
  struct sigaction s;
  s.sa_flags = SA_SIGINFO;
  s.sa_sigaction = sig;
  sigaction(SIGINT, &s, NULL);
  printf("waiting for ctrl + c \n");
  pause();
  s.sa_sigaction = SIG_DFL;
  printf("Restored default action of SIGINT\n");
  sigaction(SIGINT, &s, NULL);
  pause();
}
