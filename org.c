#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "org.h"

int main(){
  struct song * * tabletest = create_library();

  add_song(tabletest,"Astro","Who");
  add_song(tabletest,"Bas","One");
  add_song(tabletest,"Cat","why");
  add_song(tabletest,"Eat","me");



  printf("--------------------------------------------\n");

  //WORKS
  printf("TEST PRINTLETTER\n");
  printletter(tabletest,'A');
  printletter(tabletest,'B');
  printletter(tabletest,'C');
  printletter(tabletest,'D');
  printletter(tabletest,'E');

  printf("-------------------------------\n");
  //WORKS
  printf("TEST PRINT ARTIST LIBRARY\n");
  printartistlibrary(tabletest, "Astro");
  printartistlibrary(tabletest, "dese");
  printartistlibrary(tabletest, "Eat");

  printf("-------------------------------\n");
  //WORKS
  printf("TEST PRINT LIBRARY\n");
  printlibrary(NULL);
  printlibrary(tabletest);

  printf("-------------------------------\n");
  //WORKS
  printf("TEST ADD SONG\n");
  add_song(tabletest, "antimatter", "doesitmatter");
  add_song(tabletest,"Bas", "Two");
  add_song(tabletest,"Bas", "Three");
  printlibrary(tabletest);

  printf("-------------------------------\n");
  //RETURNS ACTUAL POINTER SO WORKS I GUESS
  printf("TEST SEARCH SONG\n");
  struct song * s = search_song(tabletest,"me","Eat");
  printf("Found! %s: %s \n", s->artist, s->name );

  printf("-------------------------------\n");
  //WORKS
  printf("TEST SEARCH ARTIST\n");
  s = search_artist(tabletest,"Bas");


  printf("-------------------------------\n");
  //WORKS
  printf("TEST SHUFFLE\n");
  srand(time(0));
  shuffle(tabletest);

  printf("-------------------------------\n");
  //NAH
  printf("TEST DELETE SONG\n");

  printletter(tabletest,'b');
  tabletest = delete_song(tabletest,"Two","Bas");
  printletter(tabletest,'b');

  printf("-------------------------------\n");
  //WORKS JK LOL
  printf("TEST CLEAR LIBRARY\n");
  printlibrary(tabletest);
  tabletest = clear_library(tabletest);
  printlibrary(tabletest);

  printf("--------------------------------------------\n");

  return 0;
}
