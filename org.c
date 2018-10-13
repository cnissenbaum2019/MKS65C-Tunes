#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct song_node * table[27];

//Add song nodes.
struct song_node * add_song(song_node * name){};

//Search for a song given song and 
//artist name (return a pointer).
struct song_node * search_song(char song[], char artist[]){};

//Search for an artist.


//Print out all the entries
//under a certain letter.
struct song_node * printletter(char letter[]){};

//Print out all the songs of a 
//certain artist
struct song_node * printartistlibrary(char name[]){};

//Print out the entire library.
void printlibrary(table){};

//Shuffle - print out a series of 
//randomly chosen songs.
void shuffle(){};

//Delete a song
void deletesong(char song[]){};

//Clear the library.
