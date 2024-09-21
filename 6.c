// Name: Aryan Rastogi      RollNo. MT2024026
/*6. Write a simple program to create three threads.
 */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void func() {
  printf("Thread is running\n");
  getppid();
  printf("Thread is finished\n");
}

int main(void) {
  pthread_t t1, t2, t3;
  pthread_create(&t1, NULL, (void *)func, NULL);
  pthread_create(&t2, NULL, (void *)func, NULL);
  pthread_create(&t3, NULL, (void *)func, NULL);
  return 0;
}

// OUTPUT
// Thread is running
// Thread is finished
// Thread is running
// Thread is finished
// Thread is running
// Thread is finished
