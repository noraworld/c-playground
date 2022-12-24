#include<stdio.h>
#include<math.h>

int main() {

  double value;

  printf("整数を入力してください: ");
  scanf("%lf", &value);

  printf("    √%.0f = %.30f\n", value, sqrt(value));
  printf("(√%.0f)^2 = %.30f\n", value, sqrt(value) * sqrt(value));

  return 0;
}
