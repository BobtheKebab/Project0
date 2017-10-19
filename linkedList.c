#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct song_node{ 
  char name[256];
  char artist[256];
  struct song_node *next;
};

struct song_node * insertFront (struct song_node *list, char[], char[]);
struct song_node * insertNode (struct song_node *list, char *, char *);
void printList (struct song_node *list);
struct song_node * searchSong (struct song_node *list, char *, char *);
struct song_node * searchArtist (struct song_node *list, char *);
struct song_node * randSong (struct song_node *list);
struct song_node * removeNode (struct song_node *node);
struct song_node * freeList (struct song_node *list);

void printList (struct song_node *list) {
  int count = 0;
  printf("%s | ", "PLACEHOLDER");
  while (list) {
    printf("%s : %s | ", (*list).artist, (*list).name);
    count++;
    list = (*list).next;
  }
  printf("\n");
}

struct song_node * insertFront (struct song_node *list, char nombre[], char arte[]) {
  struct song_node *insert = (struct song_node *) malloc(sizeof(struct song_node));
  strcpy(insert->name, nombre);
  strcpy(insert->artist, arte);
  insert->next = list;
  return insert;
}

struct song_node * insertNode (struct song_node *list, char *nombre, char *arte) {
  struct song_node *front = list;
  struct song_node *insert = (struct song_node *) malloc(sizeof(struct song_node));
  strcpy(insert->name, nombre);
  strcpy(insert->artist, arte);
  // Find node that the insert is after
  while(list) {
    if (strcmp(list->name, insert->name) > 0) break;
  }
  struct song_node *after = list->next;
  list->next = insert;
  insert->next = after;
  return front;
}

struct song_node * freeList (struct song_node *list) {
  struct song_node *front = list;
  while (list) {
    
    struct song_node *remove = list;
    list = (*list).next;
    free(remove);
  }
  return front;
}

int main () {

  struct song_node *list = 0;
  list = insertFront(list, "Slippery", "Migos");
  //list = insertFront(list, "All Me", "Drake");
  printList(insertNode(list, "Sacrifices", "Big Sean"));
  
  return 0;
}
