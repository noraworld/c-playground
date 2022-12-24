#include<stdio.h>
#include<string.h>
#define MAX_STRING (512)
#define INFINITY (1)

int main(void) {

  char yes[MAX_STRING];

  printf("出力したい文字を入力: ");
  gets(yes);

  while (INFINITY)
    printf("%s\n", yes);

  return 0;
}
