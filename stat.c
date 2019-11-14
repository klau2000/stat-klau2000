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

void permissionls (char * input) { //definitely not the most efficient way...
  printf("Permissions as shown in ls -l form:\n");
  printf("-");
  for (int i = 3; i < 6; i++){
    if (*(input + i) == '0')
      printf("---");
    else if (*(input + i) == '1')
      printf("--x");
    else if (*(input + i) == '2')
      printf("-w-");
    else if (*(input + i) == '3')
      printf("-wx");
    else if (*(input + i) == '4')
      printf("r--");
    else if (*(input + i) == '5')
      printf("r--x");
    else if (*(input + i) == '6')
      printf("rw-");
    else
      printf("rwx");
  }
  printf("\n");
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
  char permission[100];
  sprintf(permission, "%o", test.st_mode);
  permissionls(permission);
  printf("Time Last Accessed: %s\n", ctime(&test.st_atime));
}
