#include <stdio.h>
#include <unistd.h>

int main(void) {
  int fd[2];
  pipe(fd);
  char buffer[10];
  if (fork()) { // parent

    close(fd[0]);
    printf("Input from Parent: ");
    scanf("%[^\n]%*c", buffer);
    write(fd[1], buffer, sizeof(buffer));
    close(fd[1]);

  } else {
    // Child
    close(fd[1]);
    read(fd[0], buffer, sizeof(buffer));
    printf("Output from Child: %s\n", buffer);
    close(fd[0]);
  }
  return 0;
}

// Output
// Input from Parent: ThankYou
// Output from Child: ThankYou
