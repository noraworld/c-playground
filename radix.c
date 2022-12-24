#include<stdio.h>

int main() {

  int num = 0;

  printf("数値を入力: ");
  scanf("%d", &num);

  printf(" 8進数: %o\n", num);
  printf("10進数: %d\n", num);
  printf("16進数: %x\n", num);


  return 0;
}
