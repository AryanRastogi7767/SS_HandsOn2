// Name: Aryan Rastogi      RollNo. MT2024026
/*30. Write a program to create a shared memory.
a. write some data to the shared memory
b. attach with O_RDONLY and check whether you are able to overwrite.
c. detach the shared memory
d. remove the shared memory
 */

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(void) {
  char *data;
  int key = ftok(".", 'b');
  int shmid = shmget(key, 1024, IPC_CREAT | 0744);
  data = shmat(shmid, (void *)0, 0);
  scanf("%[^\n]%*c", data);
  return 0;
}
