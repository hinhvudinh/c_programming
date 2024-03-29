#include <stdio.h>
#include <stdlib.h>

struct _retire_info{
  int months;
  double contribution;
  double rate_of_return;
};
typedef struct _retire_info retire_info;

void retirement(int startAge, double initial, retire_info working, retire_info retired){
  double interest_earn = 0;
  double balance = initial;
  
  for (int i = 0; i < working.months; i++){
     printf("Age %3d month %2d you have $%.2f\n", (startAge + i) / 12, (startAge + i) % 12, balance);
    interest_earn = balance * working.rate_of_return;
    balance = balance + interest_earn + working.contribution;
  }

  for (int i = 0; i < retired.months; i++){
    printf("Age %3d month %2d you have $%0.2f\n", (startAge + working.months + i) / 12,(startAge + working.months + i) % 12, balance);
    interest_earn  = balance * retired.rate_of_return;
    balance = balance + interest_earn + retired.contribution;
  }
}

int main(){
  retire_info working;
  working.months = 489;
  working.contribution = 1000;
  working.rate_of_return = 4.5 / (100*12);

  retire_info retired;
  retired.months = 384;
  retired.contribution = -4000;
  retired.rate_of_return = 1.0 / (100*12);

  int startAge = 327;
  int saving = 21345;
  
  retirement(startAge, saving, working, retired);

  return 0;
}
