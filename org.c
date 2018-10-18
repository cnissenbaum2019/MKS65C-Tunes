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

<<<<<<< HEAD
=======
  tabletest[0] = &s0;
  s0.next = NULL;
  s0.artist = "Astro";
  s0.name = "Who";

  tabletest[1] = &s1;
  s1.next = NULL;
  s1.artist = "Bas";
  s1.name = "What";

  tabletest[2] = &s2;
  s2.next = NULL;
  s2.artist = "Cat";
  s2.name = "why";

  tabletest[4] = &s4;
  s4.next = NULL;
  s4.artist = "Eat";
  s4.name = "me";
>>>>>>> be344d64c7b7f9d52fe411681ac3a53a0d0e9517

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
  printf("Found: %s: %s |\n", s->artist, s->name );

  printf("-------------------------------\n");
  //WORKS
  printf("TEST SEARCH ARTIST\n");
  s = search_artist(tabletest,"Bas");
  printf("Found: %s|\n", s->artist);

  printf("-------------------------------\n");
  //WORKS
  printf("TEST SHUFFLE\n");
  srand(time(0));
  shuffle(tabletest);

  printf("-------------------------------\n");
  //NAH
  printf("TEST DELETE SONG\n");
<<<<<<< HEAD
  printletter(tabletest,'b');
  tabletest = delete_song(tabletest,"Two","Bas");
  printletter(tabletest,'b');
=======
  printletter(tabletest,'a');
  //tabletest = deletesong(tabletest,"itdoesmatter","antimatter");
  printletter(tabletest,'a');
>>>>>>> be344d64c7b7f9d52fe411681ac3a53a0d0e9517

  printf("-------------------------------\n");
  //WORKS JK LOL
  printf("TEST CLEAR LIBRARY\n");
  printlibrary(tabletest);
<<<<<<< HEAD
  tabletest = clear_library(tabletest);
=======
  //tabletest = clearlib(tabletest);
>>>>>>> be344d64c7b7f9d52fe411681ac3a53a0d0e9517
  printlibrary(tabletest);

  printf("--------------------------------------------\n");

  return 0;
}
