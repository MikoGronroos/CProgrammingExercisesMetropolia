#include <stdio.h>

int main(){

  float arr1[12];
  float arr2[12];

  float taxRate;
  int incomeLimit;
  float taxRateOverLimit;

  scanf("%f", &taxRate);
  scanf("%d", &incomeLimit);
  scanf("%f", &taxRateOverLimit);

  int lastVal = incomeLimit;

  int month = 1;
  int totalIncome = 0;
  for(; month <= 12; month++){
    printf("Enter income for month %d: \n", month);
    scanf("%f", &arr1[month - 1]);
    float tax = 0;
    float lowTax = arr1[month - 1];
    float highTax = 0;
    if(totalIncome + arr1[month - 1] > incomeLimit){
      int temp = totalIncome + arr1[month - 1] - lastVal;
      lastVal = totalIncome + arr1[month - 1]; 
      highTax = temp;
      lowTax = arr1[month - 1] - temp;
    }
    totalIncome += arr1[month - 1];
    tax += lowTax * (taxRate / 100); 
    tax += highTax * (taxRateOverLimit / 100);
    arr2[month - 1] = tax;
  }
  printf("month income tax\n");
  for(int i = 0; i < 12; i++){
    printf("%d %.2f %.2f\n", i + 1, arr1[i], arr2[i]);
  }
  
  return 0;
}
