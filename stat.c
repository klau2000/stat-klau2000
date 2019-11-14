#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <time.h>
#include <string.h>
//#include "rand.h"

void readable(long size) {
  int count = 0;
  while (size >= 1000) {
    size = size / 1000;
    count += 1;
    if (count == 3) {
      break;
    }
  }
  if (count == 0) {
    printf("Readable Size: %dB\n", size);
  }
  if (count == 1) {
    printf("Readable Size:%dKB\n", size);
  }
  if (count == 2){
    printf("Readable Size:%dMB\n", size);
  }
  if (count == 3){
    printf("Readable Size:%dGB\n", size);
  }
}

int main() {
  struct stat test;
  stat("stat.c", &test);
  if(errno){ //see if any error
    printf("Error number: %d\n", errno);
    printf("Error message: %s\n", strerror(errno));
  }
  printf("Size of this file: %ld bytes\n", test.st_size);
  readable(test.st_size);
  printf("Mode(Permissions) of this file: %o\n", test.st_mode);
  printf("Time Last Accessed: %s\n", ctime(&test.st_atime));
}
