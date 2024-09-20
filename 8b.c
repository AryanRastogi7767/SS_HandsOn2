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
