#include "Exercise15.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(void){
  menu_item *items[40];
  int amountOfItems = 0;
  char buffer[128];
  char lineBuffer[128];
  char tokenBuffer[2][50];
  int tokenAmount = 0;
  printf("Enter a filename: ");
  fgets(buffer, sizeof(buffer), stdin);
  FILE* fptr;
  buffer[strlen(buffer)-1] = '\0';
  fptr = fopen(buffer, "r");
  if(fptr != NULL){
    while(amountOfItems < 40 && fgets(lineBuffer, sizeof(lineBuffer), fptr)){
      menu_item *item = malloc(sizeof(menu_item));
      items[amountOfItems] = item;
      char* find = strtok(lineBuffer, ";");
      while(find != NULL){
        strcpy(tokenBuffer[tokenAmount], find);
        find = strtok(NULL, ";");
        tokenAmount++;
      }
      strcpy(item->name, tokenBuffer[0]);
      item->price = atof(tokenBuffer[1]);
      amountOfItems++;
      tokenAmount = 0;
    } 
    fclose(fptr);
  }else{
    fprintf(stderr, "File %s could not open\n", buffer);
  }

  if(amountOfItems > 0){
    for(int i = 0; i < amountOfItems; i++){
      printf("%-8.2f%s\n", items[i]->price, items[i]->name);
    }
  }
}
