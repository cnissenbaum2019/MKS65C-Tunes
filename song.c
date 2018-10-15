#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "song.h"

int main()
{
	srand(time(NULL));

	print_song_list(NULL);

	struct song s0;

	s0.next = NULL;
	s0.artist = "Z";
	s0.name = "Z";

	struct song * album;

	album = insert_in_order(NULL, "G", "G");

	print_song_list(album);

	album = insert_in_order(album, "B", "B");

	print_song_list(album);

	album = insert_in_order(album, "D", "D");

	print_song_list(album);

	album = insert_in_order(album, "E", "E");

	print_song_list(album);

	album = insert_in_order(album, "I", "I");

	print_song_list(album);

	album = insert_in_order(album, "A", "A");

	print_song_list(album);

	album = insert_in_order(album, "Z", "Z");

	print_song_list(album);

	album = insert_in_order(album, "M", "M");

	print_song_list(album);

	album = insert_in_order(album, "I", "B");

	print_song_list(album);

	album = insert_in_order(album, "M", "Y");

	print_song_list(album);

	printf("%d\n", length(album));

	struct song * eyes = find_song(album, "I", "I");

	printf("Find (I, I): (%s, %s)\n", eyes->artist, eyes->name);

	eyes = find_song(album, "Z", "Z");

	printf("Find (Z, Z): (%s, %s)\n", eyes->artist, eyes->name);

	eyes = find_song(album, "R", "J");

	printf("Find (R, J): %p\n", eyes);

	eyes = find_artist(album, "D");

	printf("Find (D): (%s, %s)\n", eyes->artist, eyes->name);

	eyes = find_artist(album, "I");

	printf("Find (I): (%s, %s)\n", eyes->artist, eyes->name);

	eyes = random_song(album);

	printf("Rand: %s\n", eyes->name);

	eyes = random_song(album);

	printf("Rand: %s\n", eyes->name);

	eyes = random_song(album);

	printf("Rand: %s\n", eyes->name);

	album = remove_song(album, find_song(album, "E","E"));

	printf("\nRemoved (E, E)\n");

	print_song_list(album);

	album = remove_song(album, find_song(album, "Z","Z"));

	printf("\nRemoved (Z, Z)\n");

	print_song_list(album);

	album = remove_song(album, find_song(album, "A","A"));

	printf("\nRemoved (A, A)\n");

	print_song_list(album);

	printf("KILL ALL!\n");

	album = free_song_list(album);

	print_song_list(album);


	return 0;
}