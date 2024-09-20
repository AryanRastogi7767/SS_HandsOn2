#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

void sig_handler(int sig) {
  if (sig == SIGSEGV) {
    printf("SIGSEGV caught.\n");
    exit(0);
  } else
    printf("unknown signal\n");
}

int main() {
  signal(SIGSEGV, sig_handler);
  int *p = NULL;
  printf("%d", *p);
}

// OUTPUT:
// SIGSEV caught.
