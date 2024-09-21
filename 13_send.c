// Name: Aryan Rastogi      RollNo. MT2024026
/*13. Write two programs: first program is waiting to catch SIGSTOP signal, the
second program will send the signal (using kill system call). Find out whether
the first program is able to catch the signal or not.
 */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  pid_t pid;
  printf("Enter pid of process to send signals to:");
  scanf("%d", &pid);
  printf("\nSending SIGSTOP\n");
  kill(pid, SIGSTOP);
  sleep(3);
  printf("Sending SIGCONT\n");
  kill(pid, SIGCONT);
}
// OUTPUT
// Enter pid of process to send signals to:11991

// Sending SIGSTOP
// Sending SIGCONT
