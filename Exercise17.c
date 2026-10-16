#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

char get_random_char(){
  return rand() % (126 + 1 - 33) + 33;
}

bool password_generator(char* str, int size, const char* word){
  int total_length = strlen(word) * 2 + 1;
  if(total_length >= size){
    return false;
  }
  int usedCharactersFromWord = 0;
  for(int i = 1; i <= total_length; i++){
    if(i % 2 == 0){
      str[i-1] = word[usedCharactersFromWord];
      usedCharactersFromWord++;
    }else{
      str[i-1] = get_random_char();
    }
  }
  str[total_length] = '\0';
  return true;
}

int main(void){
  srand(time(NULL) ^ (unsigned int)clock());
  char buffer[32];
  char passwordBuffer[128];
  bool running = true;
  while(running){
    printf("Please enter stop to exit or a word to enter the password: ");
    if(fgets(buffer, sizeof(buffer), stdin)){
      if (strchr(buffer, '\n') == NULL) {
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {
        }
      }else{
        buffer[strlen(buffer)-1] = '\0';
      }
    }
    if(strcmp(buffer, "stop") != 0){
      if(password_generator(passwordBuffer, sizeof(passwordBuffer), buffer)){
        printf("%s\n", passwordBuffer);
      }else{
        fprintf(stderr, "Error: password was not generated successfully\n");
      }
    }else{
      running = false;
    }
  }
}
