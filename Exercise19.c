#include "Exercise15.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int sortByPrice(const void *a, const void *b){
   const menu_item *item1 = *(const menu_item **)a;
   const menu_item *item2 = *(const menu_item **)b;
   if (item1->price < item2->price) return -1;
   if (item1->price > item2->price) return 1;   
   return 0;
}

int sortByName(const void *a, const void *b){
   const menu_item *item1 = *(const menu_item **)a;
   const menu_item *item2 = *(const menu_item **)b;
   return strcmp(item1->name, item2->name);
}

int main(void){
   menu_item *items[40];
   size_t amountOfItems = 0;
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
   char sortBuffer[32];
   if(amountOfItems > 0){
      printf("Choose to sort items by price or name: ");
      if(fgets(sortBuffer, sizeof(sortBuffer), stdin)){
         sortBuffer[strlen(sortBuffer)-1] = '\0';
         if(strcmp(sortBuffer, "price") == 0){
            qsort(items, amountOfItems, sizeof(menu_item*), sortByPrice);
         }else if(strcmp(sortBuffer, "name") == 0){
            qsort(items, amountOfItems, sizeof(menu_item*), sortByName);
         }
      }
      for(size_t i = 0; i < amountOfItems; i++){
         printf("%-8.2f%s\n", items[i]->price, items[i]->name);
         free(items[i]);
      }
   }
}
