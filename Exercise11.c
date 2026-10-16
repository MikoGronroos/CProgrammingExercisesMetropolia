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
  printf("Enter a sentence: ");
  fgets(wordBuffer, sizeof(wordBuffer), stdin);
  wordBuffer[strlen(wordBuffer)-1] = '\0';
  printf("Enter a replaced and replacing character: ");
  fgets(replacementBuffer, sizeof(replacementBuffer), stdin);
  replacementBuffer[strlen(replacementBuffer)] = '\0';
  size_t len = strlen(replacementBuffer);
  if (len > 0 && replacementBuffer[len - 1] == '\n') {
    replacementBuffer[len - 1] = '\0';
  } else {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
  }
  count = replace_char(wordBuffer, replacementBuffer);
  if(count > 0){
    printf("There were %d modified character\n", count);
  }else{
    printf("String was not modified\n");
  }
} 
