// Name: Aryan Rastogi      RollNo. MT2024026
// 2. Write a program to print the system resource limits. Use getrlimit system
// call.

#include <stdio.h>
#include <sys/resource.h>

int main(void) {
  struct rlimit limits;
  int resources[] = {RLIMIT_CORE,  RLIMIT_CPU,     RLIMIT_DATA,
                     RLIMIT_FSIZE, RLIMIT_MEMLOCK, RLIMIT_NOFILE,
                     RLIMIT_NPROC, RLIMIT_RSS,     RLIMIT_STACK};
  const char *names[] = {"CORE",   "CPU",   "DATA", "FSIZE", "MEMLOCK",
                         "NOFILE", "NPROC", "RSS",  "STACK"};
  int n = sizeof(resources) / sizeof(resources[0]);
  int i;
  for (i = 0; i < n; i++) {
    getrlimit(resources[i], &limits);
    printf("RLIMIT_%s :rlim_cur => %zu , :rlim_max => %zu\n", names[i],
           limits.rlim_cur, limits.rlim_max);
  }
}

// OUTPUT
/*RLIMIT_CORE :rlim_cur => 0 , :rlim_max => 18446744073709551615
RLIMIT_CPU :rlim_cur => 18446744073709551615 , :rlim_max => 18446744073709551615
RLIMIT_DATA :rlim_cur => 18446744073709551615 , :rlim_max =>
18446744073709551615 RLIMIT_FSIZE :rlim_cur => 18446744073709551615 , :rlim_max
=> 18446744073709551615 RLIMIT_MEMLOCK :rlim_cur => 968466432 , :rlim_max =>
968466432 RLIMIT_NOFILE :rlim_cur => 1024 , :rlim_max => 1048576 RLIMIT_NPROC
:rlim_cur => 29277 , :rlim_max => 29277 RLIMIT_RSS :rlim_cur =>
18446744073709551615 , :rlim_max => 18446744073709551615 RLIMIT_STACK :rlim_cur
=> 8388608 , :rlim_max => 18446744073709551615
*/
