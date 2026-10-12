#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int find_first(const unsigned int *array, unsigned int what){
  int value = -1;
  int i = 0;
  while(array[i] != 0){
    if(array[i] == what){
      value = i;
    }
    i++;
  }
  return value;
}

int main(void){
  int arr[20]; 
  srand(time(NULL)); 
  for(int i = 0; i < 19; i++){
    arr[i] = (1 + rand()/((RAND_MAX + 1u)/20));
  }
  arr[20] = 0;
  int numberToFind = -1;
  int index = 0;
  do{
    printf("Enter a number to find or 0 to stop: ");
    if(scanf("%d", &numberToFind) == 1 && numberToFind != 0){
      index = find_first(arr, numberToFind);
      if(index == -1){
        printf("Number was not found\n");
      }else{
        printf("Number was found at %d\n", index);
      }
    }
    while(getchar() != '\n');
  }while(numberToFind != 0);
  return 0;
}
