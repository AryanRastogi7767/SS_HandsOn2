#include <stdio.h>
#include <unistd.h>

int main(void) {
  int fd1[2];
  int fd2[2];
  pipe(fd1);
  pipe(fd2);
  if (fork()) { // parent

    char read_bufp[100];
    char write_bufp[100];
    close(fd1[0]);
    close(fd2[1]);
    printf("Input from Parent: ");
    scanf("%[^\n]%*c", write_bufp);
    write(fd1[1], write_bufp, sizeof(write_bufp));
    read(fd2[0], read_bufp, sizeof(read_bufp));
    printf("Message from Child to parent: %s\n", read_bufp);
    close(fd1[1]);
    close(fd2[0]);

  } else {
    // Child
    char read_bufc[100];
    char write_bufc[100];
    close(fd1[1]);
    close(fd2[0]);
    read(fd1[0], read_bufc, sizeof(read_bufc));
    printf("Output from Parent to Child: %s\n", read_bufc);
    printf("Input from child\n");
    scanf("%[^\n]%*c", write_bufc);
    write(fd2[1], write_bufc, sizeof(write_bufc));
    close(fd1[0]);
    close(fd2[1]);
  }
  return 0;
}

// Output
/*
Input from Parent: Hello Hello test
Output from Parent to Child: Hello Hello test
Input from child
Data recieved sending acknowledgement
Message from Child to parent: Data recieved sending acknowledgement*/
