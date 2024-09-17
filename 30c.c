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
