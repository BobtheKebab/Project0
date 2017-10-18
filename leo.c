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
  //stop when: counter == 26 or letter found
  while(in != ALPHABET[counter] && in != alphabet[counter] && counter != 26){
    counter ++;
  }
  return counter;
}

struct node * addSong(struct song_node[] musicLib, char[] song, char[] artist){
  int tableNum = charToNum( artist[0]);
  struct song_node* list = musicLib[tableNum];
  insertNode(list, song, artist);
}

struct node * searchSong(struct song_node[] musicLib, char[] song, char[] artist){
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

int main(){
  struct song_node musicLib[26];
  addSong(musicLib, "whatever it takes", "imagine dragons");
  addSong(musicLib, "the man who can't be moved", "the script");

  while (songListwefasdfsedf
  printf("successfully added %s by %s", song, artist);
  searchSong(musicLib, "whatever it takes", "imagine dragons");
}
