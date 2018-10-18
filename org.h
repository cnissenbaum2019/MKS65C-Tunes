#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "song.h"

struct song  *  table[27];

struct song * * create_library() {
  return calloc(sizeof(struct song *), 27);
  struct song garbage;
  int i = 27;
  for(;;i--){
    table[i] = &garbage;
    garbage.next = NULL;
    garbage.artist = NULL;
    garbage.name = NULL;
  }
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
void printartistlibrary(struct song * table[27], char artist[]){
  struct song * tempnode = table[tonum(artist[0])];
  tempnode = find_artist(tempnode,artist);
  printf("[%s] \n", artist);
  while(tempnode){
    char * tempartist = tempnode -> artist;
    if(!strcmp(artist,tempartist)){
      printf("%s: %s \n",tempnode -> artist,tempnode -> name);
    }
    tempnode = tempnode -> next;
  }
}

//Print out the entire library.
void printlibrary(struct song * table[27]){
  int i = 0;
  char lower[] = "abcdefghijklmnopqrstuvwxyz";
  for(;i < 27;i++){
    printletter(table,lower[i]);
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
    printf("song found! %s : %s \n",song,artist);
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
struct song * * deletesong(struct song * table[27], char * song,char *artist){
  struct song * tempnode = table[tonum(song[0])];
  printf("%c \n",song[0]);

  struct song * songpoint = find_song(tempnode, song, artist);
  tempnode = remove_song(tempnode, songpoint);
  table[tonum(song[0])] = tempnode;
  return table;
}


//Clear the library.
struct song * * clearlib(struct song * * table){
  int i = 0;
  for(;i < 27; i++){
    struct song * tempnode2 = table[i];
    if(tempnode2){
      printf("freeing node %s : %s \n",tempnode2 -> artist, tempnode2 -> name);
    }
  }
  int c = 0;
  for(;c < 27; c++){
    struct song * tempnode = table[i];
    if(tempnode){
      tempnode = free_song_list(tempnode);
    }
  }

}
