#include <stdio.h>
#include <string.h>

int replace_char(char* str, const char *rep1){
  int modifiedChars = 0; 
  for(int i = 0; i < strlen(str); i++){
    if(str[i] == rep1[0]){
      modifiedChars++;
      str[i] = rep1[1];
    }
  }
  printf("%s\n", str);
  return modifiedChars;
}

int main(void){
  char wordBuffer[128];
  char replacementBuffer[3];
  int count = 0;
  while(true){
    fgets(wordBuffer, sizeof(wordBuffer), stdin);
    wordBuffer[strcspn(wordBuffer, "\n")] = '\0';
    fgets(replacementBuffer, sizeof(replacementBuffer), stdin);
    replacementBuffer[strcspn(replacementBuffer, "\n")] = '\0';
    count = replace_char(wordBuffer, replacementBuffer);
    if(count > 0){
      printf("There were %d modified character\n", count);
    }else{
      printf("String was not modified\n");
    }
  }
}
