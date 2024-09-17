#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main(void) {
  int key = ftok(".", 'b');
  int msgid = msgget(key, IPC_CREAT | 0744);
  printf("Key: %d  ,  Message Queue ID: %d \n", key, msgid);
  return 0;
}

// OUTPUT
// Key: 1644301500  ,  Message Queue ID: 0
