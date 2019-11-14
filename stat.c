#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <time.h>
#include <string.h>
//#include "rand.h"

int main() {
  struct stat test;
  stat("stat.c", &test);

  if(errno){ //see if any error
    printf("Error number: %d\n", errno);
    printf("Error message: %s\n", strerror(errno));
  }
  printf("Size of this file: %ld\n", test.st_size);
  printf("Mode(Permissions) of this file: %o\n", test.st_mode);
  printf("Time Last Accessed: %s\n", ctime(&test.st_atime));
}
