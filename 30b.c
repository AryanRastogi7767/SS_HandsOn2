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
  char *data = shmat(shmid, (void *)0, SHM_RDONLY);
  scanf("%[^\n]%*c", data);
  printf("Text in shared mem: %s", data);
  return 0;
}

// OUTPUT:
/*We are getting segmentation fault error
 * as we are trying to access read only memory.
 */
