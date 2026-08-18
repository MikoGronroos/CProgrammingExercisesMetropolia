#include <stdio.h>

int main(){
  float busPrice;
  printf("Give price of the bus ticket: \n");
  scanf("%255f", &busPrice);

  float taxiPrice;
  printf("Give price of the taxi: \n");
  scanf("%255f", &taxiPrice);

  float howMuchMoney;
  printf("How much money you have: \n");
  scanf("%255f", &howMuchMoney);

  while(howMuchMoney >= busPrice || howMuchMoney >= taxiPrice){
    printf("Choose\n");
    printf("1, taxi (%f)\n", taxiPrice);
    printf("2, bus (%f)\n", busPrice);

    int selection;
    scanf("%d", &selection);
    if(selection == 1){
      if(howMuchMoney >= taxiPrice){
        howMuchMoney -= taxiPrice;
        printf("You chose taxi\n");
      }
    }

    if(selection == 2){
      if(howMuchMoney >= busPrice){
        howMuchMoney -= busPrice;
        printf("You chose bus\n");
      }
    }

    printf("Money left: %f\n", howMuchMoney);
    
  }
  printf("You need to walk. Bye\n");
  return 0;
}
