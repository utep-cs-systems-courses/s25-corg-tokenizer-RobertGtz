#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

#define MAXLINE 1000

int main(){
  printf(" WELCOME\n You can begin to write!\n To see your history just time '!H'\n Do you want a specific history type '!number' ex !2.\nTo exit just type '!o'\n");
  List *list = init_history();
  int id;
  char out = 0;
  List *history = init_history();
  char **pointerString;
  char *str = malloc(MAXLINE);
  while(!out){
    printf("$ ");
    fgets(str,MAXLINE,stdin);
    if (str[0]=='!'){
      switch (str[1]){
      case 'h' :
	print_history(list);
	break;
      case 'o' :
	out = 1;
	break;
      case '0': case '1': case '2': case '3': case '4':
      case '5': case '6': case '7': case '8': case '9':
	id = str[1] - '0';
	printf("your history at position %d is %s", id, get_history(list,id));
      }
    }
    else{
    pointerString = tokenize(str);
    add_history(history,str);
    print_tokens(pointerString);
    }
  }  
}
