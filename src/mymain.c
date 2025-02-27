#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

#define MAXLINE 1000

int main(){
  
  puts("Welcome!");



  List *list = init_history();

  char c[100];

  char count = 0;

  while(1){

    fputs("\nYou can write now! \nType h to see history. \ntype ! follow by a number to see a expesific number. \nType e to exit\n", stdout);

    fflush(stdout);
    char count_in = count;



    char curr_char = getchar();



    while(curr_char == '\n');

    while(curr_char != '\n'){

      c[count] = curr_char;

      curr_char = getchar();

      count++;

    }



    if (c[count_in] == 'h' && (count-count_in) == 1){
      if(!list->root) printf("there is no history yet\n");
      else{
	printf("Printing full History: \n");
	print_history(list);
      }

    } else if (c[count_in] == '!' && (count-count_in) == 2){

      int num = (int)c[count_in+1] -48;

      printf("Getting item %d from History: \n%d:", num, num);

      char *word = get_history(list, num);

      while (*word != 0){

	putchar(*word);

	word++;

      }

      putchar('\n');

    }else if (c[count_in] == 'e' && (count-count_in) == 1){

      break;

    }else{

      printf("Tokenizing your input: \n");

      char **tokens = tokenize(&c[count_in]);

      print_tokens(tokens);

      add_history(list, &c[count_in]);

    }

    count ++;

  }



  printf("goodbye\n");

  
}
