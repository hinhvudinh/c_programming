#include <stdio.h>
#include <stdlib.h>

struct _retire_info{
  int months;
  double contribution;
  double rate_of_return;
};
typedef struct _retire_info retire_info;

void retirement(int startAge, double initial, retire_info working, retire_info retired){
  double balance = initial;
  double current_balance = balance;
  
  for (int i = 0; i < working.months; i++){
    balance = current_balance * working.rate_of_return + working.contribution;
    printf("Age %3d month %2d you have %.21f\n", (startAge + i) / 12, (startAge + i) % 12, balance); 
    current_balance = balance;
  }

  for (int i = 0; i < retired.months; i++){
    balance = current_balance * retired.rate_of_return + retired.contribution;
    printf("Age %3d month %2d you have %0.21f\n", (startAge + working.months + i) / 12,
	   (startAge + working.months + i) % 12, balance);
    current_balance = balance;
  }
}

int main(){
  retire_info working;
  working.months = 489;
  working.contribution = 1000;
  working.rate_of_return = 4.5 / 12;

  retire_info retired;
  retired.months = 384;
  retired.contribution = -4000;
  retired.rate_of_return = 1.0 / 12;

  int startAge = 327;
  int saving = 21345;
  
  retirement(startAge, saving, working, retired);

  return 0;
}
