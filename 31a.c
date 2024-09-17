#include <stdio.h>
#include <sys/ipc.h>
#include <sys/sem.h>

int main(void) {
  union semun {
    int val;
    struct semid_ds *buf;
    unsigned short int *array;
  };
  int key = ftok(".", 'b');
  union semun arg;
  int semid = semget(key, 1, IPC_CREAT | 0744);
  arg.val = 1; // BINARY SEMAPHORE
  semctl(semid, 0, SETVAL, arg);

  return 0;
}
