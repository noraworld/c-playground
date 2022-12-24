#include<stdio.h>
int global = 0;

void f(int a, int b) {
  int global = 2;
  global = a; a = b; b = global;
  printf("global = %d, a = %d, b = %d\n", global, a, b);
}

void g(int *a, int *b) {
  global = *b; *b = *a; *a = global;
}

int main() {
  int x = 5;
  int y = 6;
  f(x, y);
  printf("global = %d, x = %d, y = %d\n", global, x, y);
  g(&x, &y);
  printf("global = %d, x = %d, y = %d\n", global, x, y);
  return 0;
}
