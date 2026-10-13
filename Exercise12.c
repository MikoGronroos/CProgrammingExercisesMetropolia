#include <stdio.h>
#include <string.h>

int count_words(const char* str, const char *word){
  int amountOfWords = 0;
  bool run = true;
  do{
    char const* pos = strstr(str, word);
    if(pos != NULL){
      str = pos + strlen(word);
      amountOfWords++;
    }else{
      run = false;
    }
  }while(run);
  return amountOfWords;
}

int main(void){
  char sentenceBuffer[256];
  char searchWordBuffer[256];
  bool run = true;
  int amountOfWords = 0; 
  while(run){
    printf("Enter a sentence: ");
    fgets(sentenceBuffer, sizeof(sentenceBuffer), stdin);
    sentenceBuffer[strlen(sentenceBuffer) - 1] = sentenceBuffer[strlen(sentenceBuffer)];
    printf("Enter a word to count in the sentence: ");
    fgets(searchWordBuffer, sizeof(searchWordBuffer), stdin);
    searchWordBuffer[strlen(searchWordBuffer) - 1] = searchWordBuffer[strlen(searchWordBuffer)];
    if(strcmp(searchWordBuffer, "stop") != 0){
      amountOfWords = count_words(sentenceBuffer, searchWordBuffer);
      printf("Amount of words %d\n", amountOfWords);
    }else{
      run = false;
    }
  }
}
