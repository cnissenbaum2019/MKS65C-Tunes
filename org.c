#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "org.h"

int main(){
    struct song * tabletest[27];
  	struct song s0;

    tabletest[0] = &s0;

  	s0.next = NULL;
  	s0.artist = "A";
  	s0.name = "Z";



  printletter(tabletest,"A");
  return 0;
}
