#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "song.h"

struct song  *  table[27];

struct song * * create_library() {
  return malloc(sizeof(struct song *) * 27);

}

int tonum(char letter){
  char upper[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char lower[] = "abcdefghijklmnopqrstuvwxyz";
  int i = 0;
  for(;i < 27;i++){
    if(upper[i] == letter || lower[i] == letter){
      return i;
    }
  }
  return 27;
}

//Print out all the entries under a certain letter.
void printletter(struct song * table[27], char letter) {
  struct song * s = table[tonum(letter)];
  print_song_list(s);
}


//Print out all the songs of a certain artist
void printartistlibrary(struct song * table[27], char artistname[]) {

  struct song * s = table[tonum(artistname[0])];
  s = find_artist(s, artistname);
  while (s && strcmp(s->artist, artistname) == 0) {
    printf("%s: %s |\n", s->artist, s->name);
    s = s->next;
  }
  
}

//Print out the entire library.
void printlibrary(struct song * table[27]){
  if (table) {
    int i = 0;
    char lower[] = "abcdefghijklmnopqrstuvwxyz";
    for(;i < 27;i++){
      printletter(table,lower[i]);
    }
  }
}


//Add song nodes.
struct song * add_song(struct song * table[27], char * artname, char * songname){
  int i = tonum(artname[0]);

  table[i] = insert_in_order(table[i], artname, songname);
  return table[i];
}

//Search for a song given song and artist name (return a pointer).
struct song * search_song(struct song * table[27], char *songname, char *artistname){
  int i = tonum(artistname[0]);

  return find_song(table[i], songname, artistname); 
}

//Search for an artist.
struct song * search_artist(struct song * table[27], char artistname[]){
  int i = tonum(artistname[0]);

  return find_artist(table[i], artistname);  
}


//Shuffle - print out a series of randomly chosen songs.
void shufflehelp(struct song * table[27]){
  int randnum = rand()%27;
  if(!table[randnum]){
    shufflehelp(table);
  }
  else{
    struct song * randsong = random_song(table[randnum]);
    printf("%s : %s \n",randsong -> artist, randsong ->name);
  }
}
void shuffle(struct song * table[27]){
  int i = 0;
  for(;i < 5;i++){
    shufflehelp(table);
  }
}


//Delete a song
struct song * * delete_song(struct song * table[27], char * songname, char * artname) {
  int i = tonum(artname[0]);

  table[i] = remove_song(table[i], find_song(table[i],songname,artname));

  return table;

  
}

//Clear the library.
struct song * * clear_library(struct song * table[27]){

  int i = 0;

  while(i-27) {

    printf("%d:\n",i);

    if(table[i]) {
      free_song_list(table[i]->next);
    }
    i++;
  }
  

  return NULL;
  
}
