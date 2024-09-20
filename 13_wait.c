#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void sig(int sig) {
  if (sig == SIGCONT) {
    printf("Caught SIGCONT, continuing\n");
  } else if (sig == SIGINT) {
    printf("Caught SIGINT\n");
  }
}
int main() {
  signal(SIGINT, sig);
  signal(SIGCONT, sig);
  printf("Process waiting for signals: %d\n", getpid());
  while (1) {
    sleep(1);
  }
}

// OUTPUT
// Process waiting for signals: 11991

//[17]+  Stopped                 ./a.out
// Caught SIGCONT, continuing
