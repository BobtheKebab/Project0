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
  list = freeList(list);
  printf(list);

  printf("----------------------------------------------------\n");
  printf("----------------------------------------------------\n");
  printf("----------------------------------------------------\n");
  printf("Testing Music Library:");
  struct song_node * musicLib[26]; 
  printf("Testing addSong:");
  
  
  return 0;
}
