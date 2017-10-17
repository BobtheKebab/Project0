#include <stdio.h>
#include <stdlib.h>

struct song_node{ 
  char name[256];
  char artist[256];
  struct song_node *next;
};

int charToNum(char in){
  char ALPHABET[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char alphabet[] = "abcdefghijklmnopqrstuvwxyz";

  int counter = 0;
  //stop when: counter == 26, letter found
  while(in != ALPHABET[counter] && in != alphabet[counter] && counter != 26){
    counter ++;
  }
  return counter;
}

struct node * searchSong(struct song_node[] musicLib, char[] artist, char[] song){
  int tableNum = charToNum( artist[0]);
  struct song_node* list = musicLib[tableNum];
  insertNode(list, song, artist);
}
