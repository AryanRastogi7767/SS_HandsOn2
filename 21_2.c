// Name: Aryan Rastogi      RollNo. MT2024026
// 21. Write two programs so that both can communicate by FIFO -Use two way
// communications.
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

int main(void) {
  int fd1 = open("special_fifo", O_RDONLY);
  int fd2 = open("special2", O_RDWR);
  char write_buff[80];
  char read_buff[80];
  printf("Write to process 1: \n");
  scanf("%[^\n]", write_buff);
  write(fd2, write_buff, sizeof(write_buff));
  read(fd1, read_buff, sizeof(read_buff));
  printf("Data sent by process 1: %s\n", read_buff);
  return 0;
}

// OUTPUT
/*Write to process 1:
Hello P2
Data sent by process 1: Hello P1
 */
