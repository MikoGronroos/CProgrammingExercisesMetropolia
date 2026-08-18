#include <stdio.h>

int read_integer(void){
  int number = 0;
  int result = 0;
  while(result == 0){
    result = scanf("%d", &number);
    if(result != 1){
      printf("Invalid input");
    }
  }
  return number;
}

int main(){
  int count = 0;
  float average = 0;
  int num = 0;
  while(num >= 0){
    printf("Enter positive numbers or negative to stop");
    num = read_integer();
    if(num >= 0){
      count++;
      average += num;
    }
  }
  printf("You entered %d positive numbers. The average is: %.3f\n", count, average / count);
  return 0;
}
