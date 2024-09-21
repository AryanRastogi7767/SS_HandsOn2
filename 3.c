// Name: Aryan Rastogi      RollNo. MT2024026
/*3. Write a program to set (any one) system resource limit. Use setrlimit
 * system call.
 */
#include <stdio.h>
#include <sys/resource.h>

int main(void) {
  struct rlimit limits;
  limits.rlim_cur = 5;
  if (setrlimit(RLIMIT_CORE, &limits) == -1) {
    perror("Setting limit Failed.");
  } else {
    printf("Limit set Successfully.");
  }
  return 0;
}

// OUTPUT
// Limit set Successfully.
