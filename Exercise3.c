#include <stdio.h>

int main(){

  int amountOfStudents = 0;
  printf("How many students: ");
  scanf("%d", &amountOfStudents);
  int grades[amountOfStudents];
  for (int i = 0; i < amountOfStudents; i++) {
      grades[i] = -1;
  }
  int selection = -1;
  while(selection != 0){
  
    printf("Enter student number (1 – %d) or 0 to stop: ", amountOfStudents);
    scanf("%d", &selection);
    if(selection == 0){
      break;
    }
    printf("Enter grade (0 – 5) for student %d or -1 to cancel:", selection);
    int grade = 0;
    scanf("%d", &grade);
    if(grade == -1){
      continue;
    }
    if(grade < 0 || grade > 5){
      printf("Invalid grade!\n");
      continue;
    }
    grades[selection-1] = grade;

  }
  printf("Student Grade\n");
  for(int i = 0; i < amountOfStudents; i++){
    if(grades[i] == -1){
      printf("%d N/A\n", i+1);
    }else{
      printf("%d %d\n", i+1, grades[i]);
    }
  }
  return 0;

} 
