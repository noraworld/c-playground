#include<stdio.h>
#include<string.h> // strcmp使用. ちなみにargvは文字"列"(1文字ではない)

void scanf_one_char_input();
void fgets_one_char_input();

int main(int argc, char *argv[]) {

  if (strcmp(argv[1], "scanf") == 0)
    scanf_one_char_input();
  if (strcmp(argv[1], "fgets") == 0)
    fgets_one_char_input();

  return 0;
}

void scanf_one_char_input() {

  char c = '\0';
  char dmy = '\0';
  int one_time = 0;

  do {
    printf("input nothing (only press return key): ");
    if (one_time == 1)
      scanf("%c", &dmy); // はじめの1回のみ実行されない
    scanf("%c", &c);
    one_time = 1;
  } while (c != 10);

  printf("This solution, however, is not completely.\n");
  printf("If input two or more characters, then overflow.\n");

  return;
}

void fgets_one_char_input() {

  char c[32];

  do {
    printf("input nothing (only press return key): ");
    fgets(c, sizeof(c), stdin);
  } while (c[0] != 10);

  printf("This solution, however, only gets string (not one character)\n");

  return;
}
