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
