#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void print_numbers(const int* array, int count){
  
  for(int i = 0; i < count; i++){
    printf("%8d\n", array[i]);
  }
}

int main(void){
  int arr[15]; 
  srand(time(NULL)); 
  for(int i = 0; i < 15; i++){
    arr[i] = (1 + rand()/((RAND_MAX + 1u)/99999999));
  }

  print_numbers(arr, 15);

  return 0;
}
