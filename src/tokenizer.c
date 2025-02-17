#include <stdlib.h>
#include <stdio.h>

//return true if c is a space or and enter (' ' or '\n')
int space_char(char c){

  if (c == ' ' || c == '\n')
    return 1; //c is a space or enter
  else
    return 0; 

}

//return true if c is a non-space or and enter 
int non_space_char(char c){
  
  if (!space_char(c) || c != '\0')
    return 1; //c is a char
  else
    return 0;
  
}

/* Returns a pointer to the first character of the next 

   space-separated token in zero-terminated str.  Return a zero pointer if 

   str does not contain any tokens. */

char *token_start(char *str){
  while (space_char(*str)){ //keep moving forward until find a char
    if (*str == '\0') return 0; //in case char not found
    str++;
  }
  
  return str; //char found
}


/* Returns a pointer terminator char following *token */

char *token_terminator(char *token){
  while (non_space_char(*str)) token++; //move forward until found the first space or enter
  return token; 
}


/* Counts the number of tokens in the string argument. */

int count_tokens(char *str){
  int count = 0; //initialized counter

  while(*str != '\0'){
    str = token_start(str);
    if (str==0) break; //reach the end of the string, not more token found
    count++;
    str = token_terminator(str); //end the token found, to start a new one
  }
  
  return count; //return total token
}


/* Returns a fresly allocated new zero-terminated string 

   containing <len> chars from <inStr> */

char *copy_str(char *inStr, short len){
  char *newStr = (char *) malloc(len + 1); //create a new pointer, will copy string +1 to add \0
  char *startp = *newStr; //create a new pointer so we don't lose the start point
  while(len > 0){ //copy string
    *newStr = *inStr;
    newStr++;
    inStr++;
    len--;
  }
  newStr[len]='\0'; //add the terminator 
  return startp;
}


/* Returns a freshly allocated zero-terminated vector of freshly allocated 

   space-separated tokens from zero-terminated str.



   For example, tokenize("hello world string") would result in:

     tokens[0] = "hello"

     tokens[1] = "world"

     tokens[2] = "string" 

     tokens[3] = 0

*/

char **tokenize(char* str){
  
  char **pStr = (char **) malloc((count_tokens(str) + 1) * sizeof(char *)); //create a pointer of poiter 
  char **startPStr = pStr; //create the start point of pStr
  char *strTemp; //point to use it as temp
  int countLen; //cout len of the word
  
  while(*str!='\0'){
    str = token_start(str); //skip any space char
    if (str == 0) break; // there is no more tokens
    
    countLen = 0; //reset the word to 0 len each time
    while (non_space_char(str)){ // count len of the word
      countlen++;
      str++;
    }
    
    strTemp = copy_str(str,countLen); // copy the word into a new pointer, temp is use here
    *pStr = strTemp; //add to the point of pointers 
    pStr++;

    str = token_terminator(str); //move to the next word to be added, 
  }
  
  *pStr = 0; //end the point of pointers with NULL
  return startPStr; //return the point of pointers 
}


/* Prints all tokens. */

void print_tokens(char **tokens){
  while(*tokens != 0){  //print all the pointer in tokens while is not null
    printf("%s\n",*tokens);
    tokens++; //move to the next token
  }
  
  return 0;
}


/* Frees all tokens and the vector containing themx. */

void free_tokens(char **token){
  if(token != 0){
    while(*token != 0){
      free(*token);
      token++;
    }
    free(token);
  }
}
