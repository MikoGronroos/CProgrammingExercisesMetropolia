#include "Exercise16.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

nnode *apped_node(){
  
}

int main(void){
   
  char buffer[128];
  char *endptr;
  nnode *start;
  nnode *current;
  int running = 1;
  while(running == 1){
    printf("Enter number or end to stop: ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strlen(buffer)-1] = '\0';
    long val = strtol(buffer, &endptr, 10);
    if(strcmp(buffer, "end") != 0){
      if(endptr != buffer){
        nnode *newNode = malloc(sizeof(nnode));
        if(current != NULL){
          current->next = newNode;
        }
        current = newNode; 
        current->number = atoi(buffer);
        if(start == NULL){
          start = current;
        } 
      }else{ 
        fprintf(stderr, "%s was not a number\n", buffer);
      }
    }else{
      running = 0;
    }
  }
  current = start;
  do{
    printf("%d\n", current->number);
    nnode *temp = current;
    current = current->next;
    free(temp);
  }while(current != NULL);
}
