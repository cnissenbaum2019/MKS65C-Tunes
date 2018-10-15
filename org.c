#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "org.h"

int main(){
    struct song * tabletest[27];
  	struct song s0;
    struct song s1;
    struct song s2;

    tabletest[0] = &s0;
  	s0.next = NULL;
  	s0.artist = "Arm";
  	s0.name = "Z";

    tabletest[1] = &s1;
    s1.next = NULL;
    s1.artist = "Bas";
    s1.name = "what";

    tabletest[2] = &s2;
    s2.next = NULL;
    s2.artist = "Cat";
    s2.name = "why";



  printletter(tabletest,'A');
  printletter(tabletest,'B');
  printletter(tabletest,'C');
  printf("-------------\n");
  printartistlibrary(tabletest, "Arm");
  printf("-------------\n");
  printlibrary(tabletest);
  return 0;
}
