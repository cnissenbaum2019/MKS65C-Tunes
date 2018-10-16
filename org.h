#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "song.h"

struct song * table[27];

int tonum(char letter){
  char upper[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char lower[] = "abcdefghijklmnopqrstuvwxyz";
  for(int i = 0;i < 27;i++){
    if(upper[i] == letter || lower[i] == letter){
      return i;
    }
  }
  return 27;
}

int comp(char first[],char second[]){
  int i = 0;
  for(i = 0; i < 100;i++){
    if(first[i] != second[i]){
      return 0;
    }
  }
  return 1;
}
//Print out all the entries under a certain letter.
void printletter(struct song * table[27], char letter){
  struct song * tempnode = table[tonum(letter)];
  printf("%c list \n",letter);
  while(tempnode){
    printf("%s: %s  | ",tempnode -> artist,tempnode -> name);
    tempnode = tempnode -> next;
  }
  printf("\n");
  //printf("no songs here");
}


//Print out all the songs of a certain artist
void printartistlibrary(struct song * table[27], char artist[]){
  struct song * tempnode = table[tonum(artist[0])];
  tempnode = find_artist(tempnode,artist);
  printf("[%s] \n", artist);
  while(tempnode){
    char * tempartist = tempnode -> artist;
    if(comp(artist,tempartist)){
      printf("%s: %s \n",tempnode -> artist,tempnode -> name);
    }
    tempnode = tempnode -> next;
  }
}

//Print out the entire library.
void printlibrary(struct song * table[27]){
  int i = 0;
  char lower[] = "abcdefghijklmnopqrstuvwxyz";
  for(i = 0;i < 27;i++){
    if(table[i]){
    printletter(table, lower[i]);
  }
  }
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
  printf("lookin for [%s : %s] \n",song,artist);
  struct song * tempnode = table[tonum(artist[0])];
  struct song * songpoint = find_song(tempnode, song,artist);
  if(songpoint){
    printf("song found! [%s : %s] \n",song,artist);
    return songpoint;
  }
  else{printf("song not found\n");}
}

//Search for an artist.
struct song * search_artist(struct song * table[27], char artist[]){
  printf("lookin for [%s]\n",artist);
  struct song * tempnode = table[tonum(artist[0])];
  struct song * artpoint = find_artist(tempnode,artist);
  if(artpoint){
    printf("artist found! ");
    printartistlibrary(table,artist);
    return find_artist(tempnode,artist);
  }
  else{printf("artist not found\n");}
}

//Shuffle - print out a series of randomly chosen songs.
void shuffle(struct song * table[27]){
  int i = 0;
  printf("no");
  for(i = 0;i < 4;i++){
    struct song * randsong = random_song(table[rand()%27]);
    printf("%s : %s \n",randsong -> artist, randsong ->name);
  }
}

//Delete a song
struct song * deletesong(struct song * table[27], struct song songnode){
  char *tempname = songnode.artist;
  struct song * tempnode;
  struct song * gonenode = &songnode;
  tempnode = remove_song(tempnode, gonenode);
  table[tonum(tempname[0])] = tempnode;
  return table[tonum(tempname[0])];
}

//Clear the library.
void clearlib(struct song * table[27]){
  int i = 0;
  for(i = 0;i < 27; i++){
    table[i] = free_song_list(table[i]);
  }
}
