#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int main(void){ 
   char buffer[128];
   int number;
   srand(time(NULL));
   running = true;
   while(running){  
      int randomNumber = rand() % (100 + 1);
      bool numberIsValid = false;
      printf("Enter a number between 0 and 15 or negative to stop: ");
      if(fgets(buffer, sizeof(buffer), stdin)){
         if(sscanf(buffer, "%d", &number) == 1){
            numberIsValid = number >= 0 && number <= 15;
         }
      }
      if(numberIsValid == true){
         printf("%d: %02x\n", randomNumber, randomNumber);
         int shiftedNumber = randomNumber >> number; 
         shiftedNumber = shiftedNumber & 0x3F;
         printf("%d: %02x\n", shiftedNumber, shiftedNumber);
      }else{
         running = false;   
      }
   }
}
