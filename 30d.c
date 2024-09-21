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
  int key = ftok(".", 'b');
  int shmid = shmget(key, 1024, 0);

  int del = shmctl(shmid, IPC_RMID, NULL);
  if (del == -1) {
    perror("Shared Mem deletion failed.");
  } else {
    printf("Deleted Shared memory successfully\n");
  }
  return 0;
}
