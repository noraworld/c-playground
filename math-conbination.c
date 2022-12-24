#include<stdio.h>

int main() {

  int a, b, c, d;  // (10a + b) and (10c + d)
  int count = 0;
  int ascii_digit = 0;
  int one_time = 0;
  char ascii = '\0';
  char dmy = '\0';

  printf("2つの2桁の整数 a, b (a < b) を定義する.\n");
  printf("この2つの整数の1の位を入れ替えた整数 c, d (c < d) に対して,\n");
  printf("c の値を2倍するとちょうど d になるような整数 a, b の組み合わせは\n");
  printf("全部で何通りあるか求めよ.\n");

  do {
    printf("[リターンキーで解答を表示] ");
    if (one_time == 1)
      scanf("%c", &dmy);  // scanf()の仕様によりはじめの1回だけ実行されないようにする
    scanf("%c", &ascii);
    one_time = 1;
  } while (ascii != 10);

  for (a = 1; a <= 9; a++)
    for (b = 0; b <= 9; b++)
      for (c = 1; c <= 9; c++)
	for (d = 0; d <= 9; d++)
	  if ( (2 * (10 * a + d)) == (10 * c + b) ) {
	    printf("a = %d, b = %d (2 x %d = %d)\n", (10 * a + b), (10 * c + d), (10 * a + d), (10 * c + b));
	    count++;
	  }
  printf("count = %d\n", count);

  return 0;
}
