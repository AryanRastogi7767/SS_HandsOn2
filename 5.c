// Name: Aryan Rastogi      RollNo. MT2024026
/*5. Write a program to print the system limitation of
a. maximum length of the arguments to the exec family of functions.
b. maximum number of simultaneous process per user id.
c. number of clock ticks (jiffy) per second.
d. maximum number of open files
e. size of a page
f. total number of pages in the physical memory
g. number of currently available pages in the physical memory.
 */

#include <stdio.h>
#include <unistd.h>

int main(void) {
  printf("System Limitations:\n");
  printf("a. MAX Length of args in exec : %lu\n", sysconf(_SC_ARG_MAX));
  printf("b. MAX no of simultaneous processes per UID : %lu\n",
         sysconf(_SC_CHILD_MAX));
  printf("c. No. of clock ticks per second : %lu\n", sysconf(_SC_CLK_TCK));
  printf("d. MAX no. of open files : %lu\n", sysconf(_SC_OPEN_MAX));
  printf("e. Size of a page : %lu\n", sysconf(_SC_PAGESIZE));
  printf("f. Total No. of pages in  physical memory : %lu\n",
         sysconf(_SC_PHYS_PAGES));
  printf("g. No. of currently available pages in physical memory : %lu\n",
         sysconf(_SC_AVPHYS_PAGES));
  return 0;
}

// OUTPUT
/*
System Limitations:
a. MAX Length of args in exec : 2097152
b. MAX no of simultaneous processes per UID : 29277
c. No. of clock ticks per second : 100
d. MAX no. of open files : 1024
e. Size of a page : 4096
f. Total No. of pages in  physical memory : 1891544
g. No. of currently available pages in physical memory : 648331*/
