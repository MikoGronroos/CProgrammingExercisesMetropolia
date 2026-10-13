#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <stdlib.h>

int main(void){

  char buffer[512];
  printf("Enter name of a file: ");
  char stringArray[100][80];
  fgets(buffer, sizeof(buffer), stdin);
  buffer[strlen(buffer) - 1] = '\0';
  FILE* fptr;
  fptr = fopen(buffer, "r");
  int lines = 0;
  if(fptr != NULL){
    while(lines < 100){
      if(fgets(stringArray[lines], sizeof(stringArray[lines]), fptr)){
        lines++;
      }
    }
    fclose(fptr);
  }else{ 
    fprintf(stderr, "Cant open the %s file\n", buffer);
  }
  
  fptr = fopen(buffer, "w");
  if(fptr != NULL){
    for(int i = 0; i < lines; i++){
      for(int j = 0; j < strlen(stringArray[i]); j++){
        stringArray[i][j] = toupper(stringArray[i][j]);
      }
      fprintf(fptr, stringArray[i]);
    }
    fclose(fptr);
  }else{
    fprintf(stderr, "Cant open the %s file\n", buffer);
  }
}
