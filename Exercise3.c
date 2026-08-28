#include <stdio.h>

int is_valid_grade(int grade){
  int value = 0;
  if((grade < 0 || grade > 5) && grade != -1){
    printf("Invalid grade!\n");
    value = 1;
  }
  return value;
}

int is_valid_selection(int selection, int amountOfStudents){
  int value = 0;

  if (selection <= 0 || selection > amountOfStudents){
    value = 1;
  }
  return value;

}

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
    if(is_valid_selection(selection, amountOfStudents) == 0){
      int grade = 0;
      do{
        printf("Enter grade (0 – 5) for student %d or -1 to cancel:", selection);
        scanf("%d", &grade);
      }
      while(is_valid_grade(grade) == 1);
      if(grade != -1){
        grades[selection-1] = grade;
      }
    }

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
