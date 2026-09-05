#include <stdio.h>

int read_range(int low, int high){
  int number = 0;
  int result = 0;
  int finished = 0;
  while(finished == 0){
    printf("Roll a die and enter your result\n");
    printf("Enter a number between %d and %d: ", low, high);
    result = scanf("%d", &number);
    if(result != 1 || number < low || number > high){
      printf("Invalid input\n");
      while(getchar() != '\n');
    }else{
      finished = 1;
    }
  }
  return number;
}

int main(void){
  printf("Let's play");
  int aiNum = 0;
  int low = 1;
  int high = 6;
  for(int i = 0; i < 3; i++){
    int value = read_range(1,6);
    aiNum = value + 1;
    if(aiNum > 6){
      aiNum = high;
    }
    if(aiNum > value){
      printf("I got %d. I win!\n", aiNum);
    }else if(aiNum == value){
      printf("I got %d. It is a tie!\n", aiNum);
    }
  }
  return 0;
}
