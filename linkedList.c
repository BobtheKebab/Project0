#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct song_node{ 
  char name[256];
  char artist[256];
  struct song_node *next;
};

struct song_node * insertFront (struct song_node *list, char[] nombre, char[] arte);
struct song_node * insertNode (struct song_node *list, char[] nombre, char[] arte);
void printList (struct song_node *list);
struct song_node * searchSong (struct song_node *list, char[] artist, char[] song);
struct song_node * searchArtist (struct song_node *list, char[] artist);
struct song_node * randSong (struct song_node *list);
struct song_node * removeNode (struct song_node *node);
struct song_node * freeList (struct song_node *list);

void printList (struct node *list) {
  int count = 0;
  while (list) {
    printf("%d : %d\n", count++, (*list).num);
    list = (*list).next;
  }
}

struct node * insertFront (struct node *list, int data) {
  struct node *insert = (struct node *) malloc(sizeof(struct node));
  (*insert).num = data;
  (*insert).next = list;
  return insert;
}

struct song_node * insertNode (struct song_node *list, char[] nombre, char[] arte) {
  struct song_node *insert = (struct song_node *) malloc(sizeof(struct song_node));
  (*insert).name = nombre;
  (*insert).artist = arte;
  // Find node that the insert is after
  while(list) {
    if (strcmp(list->name, insert->name) > 0) break;
  }
  struct song_node *after = list->next;
  list->next = insert;
  insert->next = after;
}

struct node * freeList (struct node *list) {
  struct node *front = list;
  while (list) {
    
    struct node *remove = list;
    list = (*list).next;
    free(remove);
  }
  return front;
}
