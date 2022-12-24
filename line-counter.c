#include<stdio.h>
#define MAX (128)

int main() {

  FILE *fp;
  FILE *next_fp;
  int ch;
  int next_ch;
  int i = 1;
  char filename[MAX];

  printf("ファイル名: ");
  scanf("%s", filename);

  fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("ファイルをオープンできません.\n");
    return -1;
  }

  next_fp = fopen(filename, "r");
  if (next_fp == NULL) {
    printf("ファイルをオープンできません.\n");
    return -1;
  }

  ch = fgetc(fp);
  next_ch = fgetc(next_fp);
  next_ch = fgetc(next_fp);
  while (ch != EOF) {
    if (i == 1) {
      printf("%3d | ", i);
      i++;
    }
    if (ch == '\n') {
      if (next_ch == EOF)
	break;
      putchar(ch);
      printf("%3d | ", i);
      i++;
    }
    else
      putchar(ch);

    ch = fgetc(fp);
    next_ch = fgetc(next_fp);
  }
  putchar('\n');

  fclose(fp);
  fclose(next_fp);

  return 0;
}
