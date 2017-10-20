#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// LINKED LIST

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
//struct song_node * removeNode (struct song_node list, struct song_node *node);
struct song_node * freeList (struct song_node *list);

void printList (struct song_node *list) {
  while (list) {
    printf("%s : %s | ", list->artist, list->name);
    list = list->next;
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

// Can't insert into the front
struct song_node * insertNode (struct song_node *list, char *nombre, char *arte) {
  struct song_node *front = list, *before = 0;
  struct song_node *insert = (struct song_node *) malloc(sizeof(struct song_node));
  strcpy(insert->name, nombre);
  strcpy(insert->artist, arte);
  // Find node that the insert is after
  while(list) {
    if (strcmp(insert->name, list->name) < 0) {
      break;
    } else {
      before = list;
      list = list->next;
    }
  }
  before->next = insert;
  insert->next = list;
  return front;
}

struct song_node * removeNode (struct song_node *list, struct song_node *node) {
  struct song_node *newFront = list;
  if (list == node) {
    newFront = list->next;
  } else {
    while (list) {
      if (list->next == node) {
	list->next = node->next;
      }
      list = list->next;
    }
  }
  free(node);
  return newFront;
}

/*
int charToNum(char in){
  char ALPHABET[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char alphabet[] = "abcdefghijklmnopqrstuvwxyz";

  int counter = 0;
  //stop when: counter == 26 or letter found
  while(in != ALPHABET[counter] && in != alphabet[counter] && counter != 26){
    counter ++;
  }
  return counter;
}

struct node * addSong(struct song_node *musicLib, char song[], char artist[]){
  int tableNum = charToNum( artist[0]);
  struct song_node* list = musicLib[tableNum];
  insertNode(list, song, artist);
}

struct node * searchSong(struct song_node *musicLib, char song[], char artist[]){
  int tableNum = charToNum(artist[0]);
  struct song_node* list = musicLib[tableNum];
  //search the song
  //while the name doesn't match and there is a next song...
  while((*list).name != song && list){
    //go onto the next
    list = (*list).next;
  }
  return list;
}
*/

// Questionable randomness
struct song_node * randSong (struct song_node *list) {
  int count = 0;
  struct song_node *altList = list;
  while (altList) {
    count++;
    altList = altList->next;
  }
  printf("Count: %d\n", count);
  srand(time(0));
  int target = rand() % count;
  printf("Target: %d\n", target);
  while (target > 0) {
    target--;
    list = list->next;
  }
  return list;
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

// MUSIC PLAYER

//struct song_node * table[27];

void addNode (struct song_node *list, char *nombre, char *arte) {
  
}

/*
struct song_node * searchSongPlayer (struct song_node *list, char *nombre, char *arte) {
  
}

struct song_node * searchArtist (struct song_node *list, char *arte) {
  
}
*/

void printLetter (struct song_node *player[], char letter) {

}

void printArtist (struct song_node *player[], char *arte) {

}

void printLibrary (struct song_node *player[]) {
  int count = 0;
  while (count < 27) {
    if (player[count] != 0) {
      printf("[%c] | ", (char) (count + 65));
      printList(player[count]);
    }
    count++;
  }
  printf("Terminated lib printing\n");
}

void shuffle (struct song_node *player[]) {

}

void deleteSong (struct song_node *player[], char *nombre) {
  
}

void deleteAll (struct song_node *player[]) {
  int count = 0;
  while (count < 27) {
    freeList(player[count]);
  }
}



int main () {

  struct song_node *list = 0;
  list = insertFront(list, "Till I Collapse", "Eminem");
  list = insertFront(list, "Slippery", "Migos");
  list = insertFront(list, "All Me", "Drake");
  //list = removeNode(list, list->next);
  printList(list);
  printList(insertNode(list, "Sacrifices", "Big Sean"));
  //struct song_node *rand = randSong(list);
  //printList(rand);

  struct song_node * table[27];
  int count = 0;
  while (count++ < 27) {
    table[count] = 0;
  }
  printf("Zeroed table\n");
  table[0] = list;
  printLibrary(table);
  printf("The function call should be done now\n");
  
  return 0;
}
