// Name: Aryan Rastogi      RollNo. MT2024026
/*7. Write a simple program to print the created thread ids.
 */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void func() { printf("ID: %lu\n", pthread_self()); }

int main(void) {
  pthread_t t1, t2, t3;
  pthread_create(&t1, NULL, (void *)func, NULL);
  pthread_create(&t2, NULL, (void *)func, NULL);
  pthread_create(&t3, NULL, (void *)func, NULL);
  return 0;
}

// OUTPUT
/*ID: 128287823103680
ID: 128287812617920
ID: 128287802132160
*/
