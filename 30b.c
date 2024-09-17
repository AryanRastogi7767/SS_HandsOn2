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
