#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "song.c"


struct song * table[27];

int tonum(char letter){
  char upper[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char lower[] = "abcdefghijklmnopqrstuvwxyz";
  for(int i = 0;i < 27;i++){
    if(upper[i] == letter || lower[i] == letter){
      return i;
    }
  }
}
int comp(char first[],char second[]){
  int i;
  for(i = 0; i < 100;i++){
    if(first[i] != second[i]){
      return 0;
    }
  }
  return 1;
}

//Add song nodes.
struct song * add_song(struct song * table[27], struct song songnode){
  char *tempname = songnode.artist;
  struct song * tempnode;
  tempnode = insert_in_order(table[tonum(tempname[0])], songnode.artist,songnode.name);
  table[tonum(tempname[0])] = tempnode;
  return table[tonum(tempname[0])];
}

//Search for a song given song and artist name (return a pointer).
struct song * search_song(struct song * table[27], char *song, char *artist){
  struct song * tempnode = table[tonum(artist[0])];
  struct song * songpoint = find_song(tempnode, song,artist);
  return songpoint;
}

//Search for an artist.
struct song * search_artist(char artist[]){
  struct song * tempnode = table[tonum(artist[0])];
  while(tempnode){
    char tempartist[] = tempnode -> artist;
    if(comp(artist,tempartist)){
      return tempartist;
    }
    tempnode = tempnode -> next;
  }
}

//Print out all the entries under a certain letter.
void printletter(struct song * table[27], char letter[]){
  struct song * tempnode = table[tonum(letter[0])];
  int c = 0;
  while(tempnode){
    printf("%s,%s \n",tempnode -> name,tempnode -> artist);
    tempnode = tempnode -> next;
    c++;
  }
}

//Print out all the songs of a certain artist
void printartistlibrary(char artist[]){
  struct song * tempnode = table[tonum(artist[0])];
  int c = 0;
  while(tempnode){
    char tempartist[] = tempnode -> artist;
    if(comp(artist,tempartist)){
      printf("%s,%s \n",tempnode -> name,tempnode ->artist);
    }
    tempnode = tempnode -> next;
    c++;
  }
}

//Print out the entire library.
void printlibrary(struct song * table[27]){
  int i = 0;
  for(i = 0;i++;i<27){
    printletter(table[i]);
  }
}

//Shuffle - print out a series of randomly chosen songs.
srand(time(0));
void shuffle(struct song * table[27]){
  struct song * shufflesong[5];
  int i = 0;
  for(i = 0;i < 5;i++){
    struct song * randsong = random_song(table[rand()%27]);
    shufflesong = insert_front(shufflesong,randsong -> artist ,randsong -> name);
  }
  printf("random: %s \n",shufflesong);
}

//Delete a song
struct song * deletesong(struct song * table[27], struct song *s){


}

//Clear the library.
void clearlib(struct song * table[27]){
  int i = 0;
  for(i = 0;i < 27; i++){
    table[i] = free_song_list(table[i]);
  }
}
