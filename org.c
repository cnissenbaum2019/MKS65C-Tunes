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
  struct song s3;
  struct song s4;

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
/*
  tabletest[3] = &s3;
  s3.next = NULL;
  s3.artist = "dese";
  s3.name = "tho";
*/
  tabletest[4] = &s4;
  s4.next = NULL;
  s4.artist = "Eat";
  s4.name = "me";

/*
  s3.next = NULL;
  s3.artist = "arch";
  s3.name = "music rocks";
  */


  //tabletest[0] = add_song(tabletest,s3);
  printf("-------------\n");
  printletter(tabletest,'A');
  printletter(tabletest,'B');
  printletter(tabletest,'C');
  printletter(tabletest,'D');
  printletter(tabletest,'E');

  printf("-------------\n");
  printartistlibrary(tabletest, "Arm");
  printartistlibrary(tabletest, "dese");
  printartistlibrary(tabletest, "Eat");
  printf("-------------\n");
  printlibrary(tabletest);
  printf("-------------\n");

  return 0;
}
