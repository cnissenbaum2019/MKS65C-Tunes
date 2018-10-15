#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct song{
  char * name;
  char * artist;
  struct song * next;
};

//insert songs at the front
struct song * insert_front(struct song * start,
						   char * artistname,
						   char * songname) {

	struct song * p = malloc(sizeof(struct song));

	p->name = songname;
	p->artist  = artistname;
	p->next = start;

	return p;

}


//compares two songs
int compare_song(struct song * s0, struct song * s1) {
	if (strcmp(s0->artist,s1->artist) == 0) return strcmp(s0->name, s1->name);

	return strcmp(s0->artist,s1->artist);
}


//insert songs in order given the first element of the list
  //alphabetical by Artist then by Song
struct song * insert_in_order(struct song * s,
							  char * artistname,
							  char * songname)
{

	struct song * start = s;

	struct song * p = malloc(sizeof(struct song));

	p->name = songname;
	p->artist = artistname;

	if (!s) return p;

	if (compare_song(p,s) < 0) {
		p->next = s;
		return p;
	}

	struct song * b;

	while (compare_song(p,s) > 0) {
		
		if (!s->next) {
			s->next = p;
			return start;
		}

		b = s;
		s = s->next;
	}

	p->next = s;
	b->next = p;


	return start;

}

//print the entire list
void print_song_list(struct song * s) {

	printf("[");
	while (s) {
		printf("(%s: %s), ", s->artist, s->name );
		s = s->next;
	}
	printf("]\n");

}

//find and return a pointer to a song based on artist and song name
struct song * find_song(struct song * s, char * songname, char * artistname) {

	while(s) {
		if (strcmp(s->artist, artistname) == 0 &&
			strcmp(s->name,     songname) == 0) return s;
		s = s->next;

	}

	return NULL;

}

//find and return a pointer to the first song of an artist based on artist name
struct song * find_artist(struct song * s,char * artistname) {

	while(s) {
		if (strcmp(s->artist, artistname) == 0) return s;
		s= s->next;
	}

	return NULL;

}

//returns length of songlist
int length(struct song * s) {
	int i = 0;
	while(s) {s=s->next; i++;}

	return i;

}

//Return a pointer to random element in the list.
struct song * random_song(struct song * s) {
	int x = rand() % length(s);

	while (x--) {s=s->next;}

	return s;

}

//remove a single specified song from the list
struct song * remove_song(struct song * s, struct song * gone) {
	
	if (s == gone) {
		struct song * placeholder = s->next;
		free(s);
		return placeholder;
	}


	struct song * start = s;

	while(s && s->next != gone) {
		s = s->next;
	}

	if (s) {
		s->next = gone->next;
		free(gone);
	}

	return start;

}

//free the entire list

struct song * free_song_list(struct song * s) {

	struct song * placeholder = s;

	while (s) {
		placeholder = s->next;
		free(s);
		s = placeholder;
	}

	return s;

}
