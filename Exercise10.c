#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int main(void){
  char buffer[128];
  char stop[] = "stop";
  do{
    printf("Enter a string: ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strlen(buffer) - 1] = buffer[strlen(buffer)];
    printf("String length is %d\n", strlen(buffer));
  }while(strcmp(buffer, "stop") != 0);
}
