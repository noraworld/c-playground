#include<stdio.h>
#include<string.h>
#define NUM (64)

int main() {

  char ascii[NUM];
  int i;

  printf("文字, 数字, 記号を入力: ");
  scanf("%s", ascii);

  puts("10進数表記");
  for (i = 0; i < strlen(ascii); i++)
    printf("%d ", ascii[i]);
  puts("");

  puts("16進数表記");
  for (i = 0; i < strlen(ascii); i++)
    printf("%x ", ascii[i]);
  puts("");


  return 0;
}
