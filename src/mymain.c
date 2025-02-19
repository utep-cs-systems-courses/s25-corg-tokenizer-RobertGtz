#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

#define MAXLINE 1000

int main(){
  char *str = (char *) malloc(MAXLINE);
  
  printf("$ ");
  fgets(str,MAXLINE,stdin);
  printf("%s", str);

  int lenghtStr = count_tokens(str);
  char **pStrs = tokenize(str);
  print_tokens(pStrs);
  free_tokens(pStrs);
  free(str);
  return 0;
}
