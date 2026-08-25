#include <stdio.h>

bool read_positive(int *value){
  int val;
  printf("Enter positive number: ");
  if(scanf("%d", &val) == 1 && val > 0){
    *value = val;
    return true;
  }
  while(getchar() != '\n');
  printf("Incorrect input!\n");
  return false;
}

int main(void){
  int tries = 0;
  int value;
  while(tries < 3){
    printf("Guess how much money I have!\n");
    if(read_positive(&value)){
      printf("You didnt get it right. I have %d euros\n", value * 2 + 20);
    }else{
      tries++;
    }
    
  }
  printf("I give up! See you later!\n");
  return 0;
}
