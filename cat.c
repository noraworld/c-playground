#include<stdio.h>

int main(void) {

  int ch;
  FILE *fp;
  char fname[64];

  printf("ファイル名: ");
  scanf("%s", fname);

  if ((fp = fopen(fname, "r")) == NULL)
    printf("ファイルをオープンできません.\n");
  else {
    while ((ch = fgetc(fp)) != EOF)
      putchar(ch);
    fclose(fp);
  }

  return 0;
}
