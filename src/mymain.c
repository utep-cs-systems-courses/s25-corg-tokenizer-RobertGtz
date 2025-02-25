#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

#define MAXLINE 1000

int main(){
  
  int id;
  char out = 0;
  List *history = init_history();
  char **pointerString;
  char *str = malloc(MAXLINE);

  printf("this is a test to see if history works\n");
  char *one_str = "test to add the first string in the first number" ;
  char *two_str = "test to add the second string in the second number" ;
  char *three_str = "test to add the third string in the third number" ;
  char *four_str = "test to add the four string in the four number" ;
  
  printf("---try to get a history in empty. ID: 1:SHOULD BE INVALID\n %s", get_history(history,1));

  add_history(history,one_str);
  add_history(history,two_str);
  add_history(history,three_str);
  add_history(history,four_str);

  printf("---print the first string in ID 1:\n %s\n", get_history(history,1));
  printf("---print the first string in ID 2:\n %s\n", get_history(history,2));
  printf("---print the first string in ID 3:\n %s\n", get_history(history,3));
  printf("---print the first string in ID 4:\n %s\n", get_history(history,4));

  printf("---print the History:\n");
  print_history(history);
  printf("---Now we try in the loop---\n");
  printf(" WELCOME\n You can begin to write!\n To see your history just type '!h'.\n Do you want a specific history type '!number' ex !2.\n To exit just type '!o'.\n");
  
  while(!out){
    printf("$ ");
    fgets(str,MAXLINE,stdin);
    if (str[0]=='!'){
      switch (str[1]){
      case 'h' :
	print_history(history);
	break;
      case 'o' :
	out = 1;
	break;
      case '0': case '1': case '2': case '3': case '4':
      case '5': case '6': case '7': case '8': case '9':
	id = atoi(&str[1]);
	printf("your history at position %d is %s", id, get_history(history,id));
      }
    } else {
      pointerString = tokenize(str);
      add_history(history,str);
      print_tokens(pointerString);
    }
  }
  free(str);
  return 0;
}
