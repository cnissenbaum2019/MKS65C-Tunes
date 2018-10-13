#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct song_node{
  char name[];
  char artist[];
  struct song_node *next;
};

//insert nodes at the front
struct node * insert_front(struct node * next, char song[], char artist[]){

}

//insert nodes in order
  //alphabetical by Artist then by Song

struct node * insert_artist(struct node * next, char song[], char artist[]){

}

struct node * insert_song(struct node * next, char song[], char artist[]){

}

//print the entire list
void print_list(struct node *songs){

}

//find and return a pointer to a node based on artist and song name
struct node * findpointer(char song[], char artist[]){

}

//find and return a pointer to the first song of an artist based on artist name
struct node * find_firstsong(char artist[]){

}

//Return a pointer to random element in the list.
struct node * randomplace(struct node *songs){

}

//remove a single specified node from the list
void remove(struct node*songs){

}

//free the entire list

struct node *free_songs(struct node *songs){

}
