// Name: Aryan Rastogi      RollNo. MT2024026
// 21. Write two programs so that both can communicate by FIFO -Use two way
// communications.
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

int main(void) {
  int fd1 = open("special_fifo", O_RDWR);
  int fd2 = open("special2", O_RDONLY);
  char write_buff[80];
  char read_buff[80];
  printf("Write to process 2: \n");
  scanf("%[^\n]", write_buff);
  write(fd1, write_buff, sizeof(write_buff));
  read(fd2, read_buff, sizeof(read_buff));
  printf("Data sent by process 2: %s\n", read_buff);
  return 0;
}

// OUTPUT
/*Write to process 2:
Hello P1
Data sent by process 2: Hello P2
*/
