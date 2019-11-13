#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <time.h>
//#include "rand.h"

int main() {
  struct stat *test;
  stat("stat.c", test);
  
  if(errno){ //see if any error
    printf("Error number: %d\n", errno);
    printf("Error message: %s\n", strerror(errno));
  }
  printf("Size of file: %ld\n", test->st_size);
}
