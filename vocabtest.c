#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#define STR (64)

int main() {

  FILE *pre_rfp;
  FILE *rfp;
  FILE *wfp;
  char vocab1[STR][STR] = {0};
  char vocab2[STR][STR] = {0};
  char temp[STR] = {0};
  char answer[STR] = {0};
  int select = 0;
  int incorrect = 0;
  int i = 0;
  int j = 0;
  int ransu = 0;
  int answer_rate = 0;
  float answer_rate_percent = 0.0;


  // 前回不正解だった単語データの読み取り
  pre_rfp = fopen("vocabtest_incorrect.txt", "r");
  if (pre_rfp != NULL) {
    while (fscanf(pre_rfp, "%s%s", vocab1[i], vocab2[i]) == 2)
      i++;
  }
  if (pre_rfp != NULL && i > 0) {
    printf("前回不正解だった単語のみをテストしますか[1]: ");
    scanf("%d", &incorrect);
  }
  fclose(pre_rfp);


  // 単語データの読み取り
  if (incorrect != 1) {
    i = 0;
    rfp = fopen("vocabtest.txt", "r");
    if (rfp == NULL) {
      printf("ファイルをオープンできませんでした.\n");
      return -1;
    }
    while (fscanf(rfp, "%s%s", vocab1[i], vocab2[i]) == 2) {
      i++;
      if (i >= STR) {
	printf("単語数が多すぎます. このプログラムの受容単語数を増やすか, テキストファイル内の単語の量を減らしてください.\n");
	return -1;
      }
    }
    fclose(rfp);
  }


  // ランダムに並び替える
  srand((unsigned)time(NULL));
  while (j < i && i > 1) {
    ransu = rand() % i;
    //printf("%2d %2d ", j, ransu);

    if (j == ransu) {
      //printf("バッティング発覚!!! バッティング発覚!!! バッティング発覚!!! バッティング発覚!!!\n");
      continue;
    }

    strcpy(temp, vocab1[j]);
    strcpy(vocab1[j], vocab1[ransu]);
    strcpy(vocab1[ransu], temp);

    strcpy(temp, vocab2[j]);
    strcpy(vocab2[j], vocab2[ransu]);
    strcpy(vocab2[ransu], temp);

    //printf("%s %s\n", vocab1[j], vocab1[ransu]);

    j++;
  }


  // どちらをテストするか選択
  do {
    printf("英語→日本語[1], 日本語→英語[2]: ");
    scanf("%d", &select);
  } while (select != 1 && select != 2);

  wfp = fopen("vocabtest_incorrect.txt", "w");

  // 英語→日本語の単語テスト
  j = 0;
  if (select == 1) {
    for (j = 0; j < i; j++) {
      printf("%s: ", vocab1[j]);
      scanf("%s", answer);
      if (strcmp(answer, vocab2[j]) == 0) {
	printf("正解です.\n");
	answer_rate++;
      }
      else {
	printf("不正解です. %s = %s\n", vocab1[j], vocab2[j]);
	fprintf(wfp, "%s %s\n", vocab1[j], vocab2[j]);
      }
      putchar('\n');
    }
  }


  // 日本語→英語の単語テスト
  j = 0;
  if (select == 2) {
    for (j = 0; j < i; j++) {
      printf("%s: ", vocab2[j]);
      scanf("%s", answer);
      if (strcmp(answer, vocab1[j]) == 0) {
	printf("正解です.\n");
	answer_rate++;
      }
      else {
	printf("不正解です. %s = %s\n", vocab2[j], vocab1[j]);
	fprintf(wfp, "%s %s\n", vocab1[j], vocab2[j]);
      }
      putchar('\n');
    }
  }

  fclose(wfp);

  // 正答率を表示
  answer_rate_percent = (float)answer_rate / (float)i * 100;
  printf("正答率: %d / %d (%.1f%%)\n", answer_rate, i, answer_rate_percent);

  return 0;
}
