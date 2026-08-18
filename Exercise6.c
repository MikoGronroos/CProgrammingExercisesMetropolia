#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int render_menu(void){
  printf("1, Roll D6\n");
  printf("2, Roll D10\n");
  printf("3, Quit\n");
  return 0;
}

int handle_selection(int selection){
  int state = 1;
  if(selection >= 1 && selection <= 3){
    switch(selection){
      case 1:
        printf("D6: %d\n", (1 + rand()/((RAND_MAX + 1u)/6)));
        break;
      case 2:
        printf("D10: %d\n", (1 + rand()/((RAND_MAX + 1u)/10)));
        break;
      case 3:
        state = 0;
        break;
    }
  }else{
    printf("Error! Invalid input");
  }
  return state;
}

int main(void){
  srand(time(NULL));
  int running = 1;
  int selection = 0;
  while(running == 1){
    render_menu();
    scanf("%d", &selection);
    running = handle_selection(selection);
  }
  return 0;
}
