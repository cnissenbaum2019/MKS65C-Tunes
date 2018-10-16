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

  tabletest[4] = &s4;
  s4.next = NULL;
  s4.artist = "Eat";
  s4.name = "me";


  printf("-------------------------------\n");
  //WORKS
  printf("TEST PRINTLETTER\n");
  printletter(tabletest,'A');
  printletter(tabletest,'B');
  printletter(tabletest,'C');
  //printletter(tabletest,'D');
  printletter(tabletest,'E');

  printf("-------------------------------\n");
  //WORKS
  printf("TEST PRINT ARTIST LIBRARY\n");
  printartistlibrary(tabletest, "Arm");
  //printartistlibrary(tabletest, "dese");
  printartistlibrary(tabletest, "Eat");

  printf("-------------------------------\n");
  //DOES NOT PRINT NULL
  printf("TEST PRINT LIBRARY\n");
  //printlibrary(tabletest);

  printf("-------------------------------\n");
  //WORKS
  printf("TEST ADD SONG\n");
  s3.next = NULL;
  s3.artist = "adese";
  s3.name = "tho";
  struct song * newsongs = add_song(tabletest,s3);
  struct song s5;
  struct song s6;
  s5.next = NULL;
  s5.artist = "Bas";
  s5.name = "Are";
  struct song * newsongsbas = add_song(tabletest,s5);
  s6.next = NULL;
  s6.artist = "Bas";
  s6.name = "You";
  struct song * newsongsbas2 = add_song(tabletest,s6);
  //printlibrary(tabletest);

  printf("-------------------------------\n");
  //RETURNS ACTUAL POINTER SO WORKS I GUESS
  printf("TEST SEARCH SONG\n");
  struct song * searchfor = search_song(tabletest,"me","Eat");
  printf("%s\n",searchfor);

  printf("-------------------------------\n");
  //WORKS
  printf("TEST SEARCH ARTIST\n");
  struct song * searchforA = search_artist(tabletest,"Bas");

  printf("-------------------------------\n");
  //WOKS WHEN SMALL SAMPLE SIZE
  printf("TEST SHUFFLE\n");
  srand(time(0));
  shuffle(tabletest);

  printf("-------------------------------\n");
  //REPLACES INSTEAD OF DELETES
  printf("TEST DELETE SONG\n");
  struct song * onelesssong = deletesong(tabletest,s1);
  //printlibrary(tabletest);

  printf("-------------------------------\n");
  //WORKS
  printf("TEST CLEAR LIBRARY\n");
  //clearlib(tabletest);
  //printlibrary(tabletest);
  printf("-------------------------------\n");

  return 0;
}
