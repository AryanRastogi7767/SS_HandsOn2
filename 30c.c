// Name: Aryan Rastogi      RollNo. MT2024026
/*30. Write a program to create a shared memory.
a. write some data to the shared memory
b. attach with O_RDONLY and check whether you are able to overwrite.
c. detach the shared memory
d. remove the shared memory
 */
#include <stdio.h>
#include <sys/shm.h>

int main(void) {
  int key = ftok(".", 'b');
  int shmid = shmget(key, 1024, 0);
  char *data = shmat(shmid, (void *)0, 0);
  int del = shmdt(data);
  if (del == -1) {
    perror("Shared Mem detach failed.");
  } else {
    printf("Detached Shared memory successfully\n");
  }
  return 0;
}
