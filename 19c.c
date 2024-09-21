// Name: Aryan Rastogi      RollNo. MT2024026
/*19. Create a FIFO file by
a. mknod command
b. mkfifo command
c. use strace command to find out, which command (mknod or mkfifo) is better.
c. mknod system call
d. mkfifo library function
*/
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
int main(void) {

  if (mknod("special_file", S_IFIFO | 0666, 0) == -1) {
    perror("FIFO error");
  }
  return 0;
}
