#include <stdio.h>
#include <stdlib.h>

typedef struct s_Item {

  int id;

  char *str;

  struct s_Item *next;

} Item;



typedef struct s_List {

  struct s_Item *root;

} List;



/* Initialize the linked list to keep the history. */

List* init_history(){
  List *init = malloc(sizeof(List)); //create a poiter null
  init->root = 0; //have the poiter to point to the root
  return init;
}

/* Add a history item to the end of the list.

   List* list - the linked list

   char* str - the string to store

*/

void add_history(List *list, char *str){
  if (!list->root){ //check if root is empty, if yes, means that is the first word input
    list->root = malloc(sizeof(Item)); //create a new Item to store
    list->root->id = 1; //set the start counting
    list->root->str = str;
    list->root->next = 0; //next to null by default
  }
  else{
    Item *tempItem = list->root; //create a temporaly item to move forward wihtout changing the list
    while (tempItem->next) tempItem = tempItem->next; //move to no more items founds = end of the list
    Item *newItem = malloc(sizeof(Item)); //create the the new item to add
    newItem->id = tempItem->id + 1; //have the counting increase and store it
    newItem->str = str;
    newItem->next = 0;

    tempItem->next = newItem; //add the new item create to the end list
  }
}

/* Retrieve the string stored in the node where Item->id == id.

   List* list - the linked list

   int id - the id of the Item to find */

char *get_history(List *list, int id){
  Item *tempItem = list->root; //temp to modify
  while (tempItem){ //keep move forward till number is found
    if (tempItem->id == id) return tempItem->str; //found return the string
    tempItem = tempItem->next;
  }
  return "not a valid number, try again\n"; //not found 
}


/*Print the entire contents of the list. */

void print_history(List *list){
  Item *tempItem = list->root; //temp to modify
  while (tempItem){ 
    printf("%d) %s\n",tempItem->id,tempItem->str); //print id and string then move forward
    tempItem = tempItem->next;
  }
}



/*Free the history list and the strings it references. */

void free_history(List *list){
  Item *tempItem = list->root; //temp to free
  Item *next;  //save the next item so it does not get lose
  while (tempItem){
    next = tempItem->next; //save next item in next
    free(tempItem);
    tempItem->next = next; //set next item to free
  }
  free(list); //free list;
}
