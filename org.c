#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include songs.c


struct song_node * table[27];

int tonum(char letter){
  char upper[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
  char lower[] = "abcdefghijklmnopqrstuvwxyz"
  int i = 0;
  for(i = 0;i < 27;i++){
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
struct song_node * add_song(struct song_node * table[27], struct song_node song){
  char tempname[] = song.artist;
  struct song_node * tempnode;
  tempnode = insert_song(table[tonum(tempname[0])], song);
  table[tonum(tempname[0])] = tempnode;
  return table;
}

//Search for a song given song and artist name (return a pointer).
struct song_node * search_song(struct song_node * table[27], char song[], char artist[]){
  struct song_node * tempnode = table[tonum(artist[0])];
  struct song_node * songpoint = findpointer(tempnode, song,artist);
  return songpoint;
}

//Search for an artist.
struct song_node * search_artist(char artist[]){
  struct song_node * tempnode = table[tonum(artist[0])];
  while(tempnode){
    char tempartist[] = tempnode -> artist;
    if(comp(artist,tempartist)){
      return *tempartist;
    }
    tempnode = tempnode -> next;
  }
}

//Print out all the entries under a certain letter.
void printletter(char letter[]){
  struct song_node * tempnode = table[tonum(letter)];
  int c = 0;
  while(tempnode){
    printf("%s,%s \n",tempnode -> name,tempnode -> artist);
    tempnode = tempnode -> next;
    c++;
  }
}

//Print out all the songs of a certain artist
void printartistlibrary(char artist[]){
  struct song_node * tempnode = table[tonum(artist[0])];
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
void printlibrary(table){};

//Shuffle - print out a series of randomly chosen songs.
void shuffle(){};

//Delete a song
void deletesong(char song[]){};

//Clear the library.
void clearlib(){

}
