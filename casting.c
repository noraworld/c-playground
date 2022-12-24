#include<stdio.h>

int main() {

  int id1;
  int id_2;
  // int 3_id; 変数名は数字から始まってはいけない！
  int _5;
  int _4_id;
  int _;

  int i = 2;
  int m = 4.2;
  float f = 9.9;
  float g = 99;
  signed char c = 255;

  printf("%d\n", i + m);
  printf("%f\n", g - m);
  printf("%d\n", i - c);
  printf("%d\n", (int)f * i / m);
  printf("%d\n", (int)(f * i) / m);
  printf("%d\n", (int)f * (i / m));

  return 0;
}
