#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>

int main(void){

  char buffer[128];
  char intBuffer[256];
  int count = 0;
  int lowest = INT_MAX;
  int highest = INT_MIN;
  printf("Enter name of a file: ");

  fgets(buffer, sizeof(buffer), stdin);
  buffer[strlen(buffer) - 1] = '\0';
  FILE* fptr;
  fptr = fopen(buffer, "r");
  if(fptr != NULL){
    while(fgets(intBuffer, sizeof(intBuffer), fptr)){
      intBuffer[strlen(intBuffer)-1] = '\0';
      for(int i = 0; i < strlen(intBuffer); i++){
        int num = intBuffer[i] - '0';
        if(num > highest){
          highest = num;
        }
        if(num < lowest){
          lowest = num;
        }
        count++;
      }
    }
    fclose(fptr);
  }else{ 
    fprintf(stderr, "Cant open the %s file\n", buffer);
  }
  printf("Lowest was %d, highest was %d and the count was %d\n", lowest, highest, count);
}
