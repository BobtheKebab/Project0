#include <stdio.h>
#include <stdlib.h>

struct song_node{ 
  char name[256];
  char artist[256];
  struct song_node *next;
};

struct song_node * insertFront (struct song_node *list, char[] nombre, char[] arte);
struct song_node * insertNode (struct song_node *list, char[] nombre, char[] arte);
void printList (struct song_node *list);
struct song_node * searchSong (struct song_node *list, char[] song);
struct song_node * searchArtist (struct song_node *list, char[] artist);
struct song_node * randSong (struct song_node *list);
struct song_node * removeNode (struct song_node *node);
struct song_node * freeList (struct song_node *list);


