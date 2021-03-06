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
struct song_node * searchSong(struct song_node *musicLib[], char song[], char artist[]);
struct song_node * searchArtist(struct song_node *list, char *);
struct song_node * randsong(struct song_node *list);
//struct song_node * removeNode (struct song_node list, struct song_node *node);
void freeList (struct song_node *list);

void printList (struct song_node *list) {
  while (list) {
    printf("%s : %s | ", list->artist, list->name);
    list = list->next;
  }
  printf("\n");
}

void printNode (struct song_node *node) {
  printf("%s : %s \n", node->artist, node->name);
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

struct node * addSong(struct song_node *musicLib[], char song[], char artist[]){
  int tableNum = charToNum( artist[0]);
  struct song_node* list = musicLib[tableNum];
  insertNode(list, song, artist);
}

struct song_node * searchSong(struct song_node *musicLib[], char song[], char artist[]){
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

// Questionable randomness
struct song_node * randSong (struct song_node *list) {
  int count = 0;
  struct song_node *altList = list;
  while (altList) {
    count++;
    altList = altList->next;
  }
  //printf("Count: %d\n", count);
  srand(time(NULL));
  int target = rand() % count;
  //printf("Target: %d\n", target);
  while (target) {
    target--;
    list = list->next;
  }
  return list;
}

void freeList (struct song_node *list) {
  while (list) {
    struct song_node *remove = list;
    list = list->next;
    free(remove);
  }
}

// MUSIC PLAYER

//struct song_node * table[26];

/*
  void addNode (struct song_node *musicLib[], char *nombre, char *arte) {
  char target = arte[0];
  int count = 0;
  while (count + 97 - target) {
  count++;
  }
  addNode(player[count], nombre, arte);
  }


  struct song_node * searchSongPlayer (struct song_node *musicLib[], char *nombre, char *arte) {
  char target = arte[0];
  int count = 0;
  while (count + 97 - target) {
  count++;
  }
  }

  struct song_node * searchArtist (struct song_node *musicLib[], char *arte) {
  char target = arte[0];
  int count = 0;
  while (count + 97 - target) {
  count++;
  }
  struct song_node *node = player[count];
  while (node) {
  printNode(node);
  node = node->next;
  }
  }
*/

void printLetter (struct song_node *player[], char letter) {

}

void printArtist (struct song_node *player[], char arte[]) {
  charToNum(arte[1]);
}

void printLibrary (struct song_node * player[]) {
  printf("hi");
  int count = 0;
  while (count < 26) {
    if (player[count] != 0) {
      printf("[%c] | ", (char) (count + 65));
      printList(player[count]);
    }
    count++;
  }
  printf("Terminated lib printing\n");
}

void shuffle (struct song_node *player[], int numSongs) {
  srand(time(NULL));
  while (numSongs) {
    //apparently calling the variable rand fucks with C...
    int rng = rand();
    printNode(randSong(player[numSongs]));
    numSongs--;
  }
}

void deleteSong (struct song_node *player[], char *nombre) {
  int count = 0;
  while (count < 26) {
    struct song_node *current = player[0], *front = current;
    while(current) {
      if (current->name == nombre) {
	removeNode(front, current);
	break;
      }
      current = current->next;
    }
    count++;
  }
}

void deleteAll (struct song_node *player[]) {
  int count = 0;
  while (count < 26) {
    freeList(player[count]);
    count++;
  }
}



int main () {

  /*
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
  */

  printf("SONG NODE TESTS\n");
  printf("----------------------------------------------------\n");
  printf("Test insertFront (and printList):\n");
  struct song_node *list = 0;
  list = insertFront(list, "till i collapse", "eminem");
  list = insertFront(list, "slippery", "migos");
  list = insertFront(list, "all me", "drake");
  printList(list);
  printf("----------------------------------------------------\n");
  printf("Test addNode:\n");
  list = insertNode(list, "sacrifices", "big sean");
  printList(list);
  printf("----------------------------------------------------\n");
  printf("Test removeNode:\n");
  list = removeNode(list, list);
  printList(list);
  printf("----------------------------------------------------\n");
  list = insertFront(list, "all me", "drake");
  printList(list);
  printf("----------------------------------------------------\n");
  printf("Test randSong\n");
  printList(randSong(list));
  printList(randSong(list));
  printList(randSong(list));
  printList(randSong(list));
  printf("----------------------------------------------------\n");

  printf("----------------------------------------------------\n");

  printf("----------------------------------------------------\n");

  printf("----------------------------------------------------\n");

  printf("----------------------------------------------------\n");
  printf("Test freeList:\n");
  freeList(list);
  printf("It was freed, trust us\n");
  printf("If we print the list again theres a good chance of segfault\n");
  printf("----------------------------------------------------\n");
  
  
  printf("\n\n----------------------------------------------------\n");
  printf("MUSIC LIBRARY TESTS\n");
  printf("-----------------------------------------------------\n");
  printf("Initiating music library...\n");
  struct song_node *musicLibrary[26];
  printf("Testing addSong...\n");
  addSong(musicLibrary,"fast lane","bad meets evil");
  //printLibrary(musicLibrary);
  
  return 0;
}
