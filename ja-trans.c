#include<stdio.h>
#define MAX (512)

int main() {

  char str[MAX];
  unsigned i;
  int flag;

  printf("日本語をローマ字で入力: ");
  fgets(str, sizeof(str), stdin);
  i = 0;
  while (str[i] != '\n')
    i++;
  str[i] = '\0';



  i = 0;
  while (str[i]) {
    flag = 0;

    if (str[i] == 'k') {
      if (flag == 0)
	switch (str[i+1]) {
	case 'a' : printf("か"); break;
	case 'i' : printf("き"); break;
	case 'u' : printf("く"); break;
	case 'e' : printf("け"); break;
	case 'o' : printf("こ"); break;
	}
      i += 2;
      flag++;
    }

    if (flag == 0) {
      if (str[i] == 's')
	switch (str[i+1]) {
	case 'a' : printf("さ"); break;
	case 'i' : printf("し"); break;
	case 'u' : printf("す"); break;
	case 'e' : printf("せ"); break;
	case 'o' : printf("そ"); break;
	}
      i += 2;
      flag++;
    }

    if (flag == 0) {
      if (str[i] == 't')
	switch (str[i+1]) {
	case 'a' : printf("た"); break;
	case 'i' : printf("ち"); break;
	case 'u' : printf("つ"); break;
	case 'e' : printf("て"); break;
	case 'o' : printf("と"); break;
	}
      i += 2;
      flag++;
    }

    if (flag == 0) {
      if (str[i] == 'n')
	switch (str[i+1]) {
	case 'a' : printf("な"); break;
	case 'i' : printf("に"); break;
	case 'u' : printf("ぬ"); break;
	case 'e' : printf("ね"); break;
	case 'o' : printf("の"); break;
	}
      i += 2;
      flag++;
    }

    if (flag == 0) {
      if (str[i] == 'h')
	switch (str[i+1]) {
	case 'a' : printf("は"); break;
	case 'i' : printf("ひ"); break;
	case 'u' : printf("ふ"); break;
	case 'e' : printf("へ"); break;
	case 'o' : printf("ほ"); break;
	}
      i += 2;
      flag++;
    }

    if (flag == 0) {
      if (str[i] == 'm')
	switch (str[i+1]) {
	case 'a' : printf("ま"); break;
	case 'i' : printf("み"); break;
	case 'u' : printf("む"); break;
	case 'e' : printf("め"); break;
	case 'o' : printf("も"); break;
	}
      i += 2;
      flag++;
    }

    if (flag == 0) {
      if (str[i] == 'y')
	switch (str[i+1]) {
	case 'a' : printf("や"); break;
	case 'i' : printf("い"); break;
	case 'u' : printf("ゆ"); break;
	case 'e' : printf("え"); break;
	case 'o' : printf("よ"); break;
	}
      i += 2;
      flag++;
    }

    if (flag == 0) {
      if (str[i] == 'r')
	switch (str[i+1]) {
	case 'a' : printf("ら"); break;
	case 'i' : printf("り"); break;
	case 'u' : printf("る"); break;
	case 'e' : printf("れ"); break;
	case 'o' : printf("ろ"); break;
	}
      i += 2;
      flag++;
    }

    if (flag == 0) {
      if (str[i] == 'w')
	switch (str[i+1]) {
	case 'a' : printf("わ"); break;
	case 'i' : printf("うぃ"); break;
	case 'u' : printf("う"); break;
	case 'e' : printf("うぇ"); break;
	case 'o' : printf("を"); break;
	}
      i += 2;
      flag++;
    }

    if (flag == 0) {
      if (str[i] == 'a')
	printf("あ");
      if (str[i] == 'i')
	printf("い");
      if (str[i] == 'u')
	printf("う");
      if (str[i] == 'e')
	printf("え");
      if (str[i] == 'o')
	printf("お");
      i++;
      flag++;
    }

  }


  putchar('\n');
  return 0;
}
