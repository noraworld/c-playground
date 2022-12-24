#include<stdio.h>

int main() {

  int hoge[2] = {0x10050403, 0x11030201};
  char *x = (char *)&hoge[0];
  short int *y = (short int *)&hoge[0];

  x = x + 2;  printf("x: %p *x: %d\n", x, *x);
  y = y + 2;  printf("y: %p *y: %d\n", y, *y);
  y = y - 1;  printf("y: %p *y: %d\n", y, *y);
}
