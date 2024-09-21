// Name: Aryan Rastogi      RollNo. MT2024026
/*9. Write a program to ignore a SIGINT signal then reset the default action of
the SIGINT signal - Use signal system call.
 */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void handler(int s) {
  if (s == SIGINT) {
    printf("SIGINT caught but doing nothing\n");
  } else
    printf("unknown signal\n");
}

int main() {
  signal(SIGINT, handler);
  printf("SIGINT is being ignored\n");
  sleep(5);
  signal(SIGINT, SIG_DFL);
  printf("SIGINT back to default behaviour\n");
  sleep(5);
}

// OUTPUT
// SIGINT is being ignored
// SIGINT back to default behaviour
