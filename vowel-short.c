#include<stdio.h>
#include<string.h>
#define MAX (10)

int main() {

  char hrgn[81][4] = {
            "あ","い","う","え","お","か","き","く","け","こ",
	    "さ","し","す","せ","そ","た","ち","つ","て","と",
	    "な","に","ぬ","ね","の","ん","は","ひ","ふ","へ","ほ",
	    "ま","み","む","め","も","や","ゆ","よ",
	    "ら","り","る","れ","ろ","わ","を",           // ここまでで46
	    "が","ぎ","ぐ","げ","ご","ざ","じ","ず","ぜ","ぞ",
	    "だ","ぢ","づ","で","ど","ば","び","ぶ","べ","ぼ",
	    "ぱ","ぴ","ぷ","ぺ","ぽ","ぁ","ぃ","ぅ","ぇ","ぉ",
	    "ゃ","ゅ","ょ","ゎ","っ"};
  int roopcount[2][MAX];
  char str[MAX+1];
  unsigned a;
  unsigned i, j, k, l, m, n, o, p, q, r; // rまでで10個
  unsigned count = 0;
  unsigned brank = 0;
  unsigned brank_val;
  int flag = 0;

  printf("母音省略文字を入力: ");
  scanf("%s", str);

  for (a = 0; a < strlen(str); a++) {
    switch (str[a]) {
    case 'a' : roopcount[0][a] = 1; roopcount[1][a] =  0; break;
    case 'i' : roopcount[0][a] = 1; roopcount[1][a] =  1; break;
    case 'u' : roopcount[0][a] = 1; roopcount[1][a] =  2; break;
    case 'e' : roopcount[0][a] = 1; roopcount[1][a] =  3; break;
    case 'o' : roopcount[0][a] = 1; roopcount[1][a] =  4; break;
    case 'k' : roopcount[0][a] = 5; roopcount[1][a] =  5; break;
    case 's' : roopcount[0][a] = 5; roopcount[1][a] = 10; break;
    case 't' : roopcount[0][a] = 5; roopcount[1][a] = 15; break;
    case 'n' : roopcount[0][a] = 6; roopcount[1][a] = 20; break;
    case 'h' : roopcount[0][a] = 5; roopcount[1][a] = 26; break;
    case 'm' : roopcount[0][a] = 5; roopcount[1][a] = 31; break;
    case 'y' : roopcount[0][a] = 3; roopcount[1][a] = 36; break;
    case 'r' : roopcount[0][a] = 5; roopcount[1][a] = 39; break;
    case 'w' : roopcount[0][a] = 2; roopcount[1][a] = 44; break;
    case 'g' : roopcount[0][a] = 5; roopcount[1][a] = 46; break;
    case 'z' : roopcount[0][a] = 5; roopcount[1][a] = 51; break;
    case 'd' : roopcount[0][a] = 5; roopcount[1][a] = 56; break;
    case 'b' : roopcount[0][a] = 5; roopcount[1][a] = 61; break;
    case 'p' : roopcount[0][a] = 5; roopcount[1][a] = 66; break;
    case 'x' : roopcount[0][a] = 5; roopcount[1][a] = 71; break;
    case 'l' : roopcount[0][a] = 5; roopcount[1][a] = 76; break;
    default  : printf("スペルミス？\n");             return -1;
    }
  }

  for (a = strlen(str); a < MAX; a++) {
    roopcount[0][a] = 1;
    roopcount[1][a] = 70; // とりあえず使わない文字
  }

  switch (strlen(str)) {
  case  1 : brank_val = 25; break;
  case  2 : brank_val = 15; break;
  case  3 : brank_val = 11; break;
  case  4 : brank_val =  9; break;
  case  5 : brank_val =  7; break;
  case  6 : brank_val =  6; break;
  case  7 : brank_val =  11; break; // 5
  case  8 : brank_val =  5; break;
  case  9 : brank_val =  4; break;
  case 10 : brank_val =  4; break;
  default : printf("文字数オーバー？\n"); return -1;
  }

  for (i = 0; i < roopcount[0][0]; i++)
    for (j = 0; j < roopcount[0][1]; j++)
      for (k = 0; k < roopcount[0][2]; k++)
	for (l = 0; l < roopcount[0][3]; l++)
	  for (m = 0; m < roopcount[0][4]; m++)
	    for (n = 0; n < roopcount[0][5]; n++)
	      for (o = 0; o < roopcount[0][6]; o++)
		for (p = 0; p < roopcount[0][7]; p++)
		  for (q = 0; q < roopcount[0][8]; q++)
		    for (r = 0; r < roopcount[0][9]; r++) {
		      if (roopcount[1][0] != 70)
			printf("%s", hrgn[roopcount[1][0]+i]);
		      if (roopcount[1][1] != 70)
			printf("%s", hrgn[roopcount[1][1]+j]);
		      if (roopcount[1][2] != 70)
			printf("%s", hrgn[roopcount[1][2]+k]);
		      if (roopcount[1][3] != 70)
			printf("%s", hrgn[roopcount[1][3]+l]);
		      if (roopcount[1][4] != 70)
			printf("%s", hrgn[roopcount[1][4]+m]);
		      if (roopcount[1][5] != 70)
			printf("%s", hrgn[roopcount[1][5]+n]);
		      if (roopcount[1][6] != 70)
			printf("%s", hrgn[roopcount[1][6]+o]);
		      if (roopcount[1][7] != 70)
			printf("%s", hrgn[roopcount[1][7]+p]);
		      if (roopcount[1][8] != 70)
			printf("%s", hrgn[roopcount[1][8]+q]);
		      if (roopcount[1][9] != 70)
			printf("%s", hrgn[roopcount[1][9]+r]);
		      printf("　");
		      count++;
		      brank++;
		      if (brank == brank_val) {
			putchar('\n');
			brank = 0;
		      }
		    }


  printf("\n組み合わせ: %d通り\n", count);
  return 0;
}

/*
「あ」行をループしたい場合: hrgn[0+i]
「か」行をループしたい場合: hrgn[5+i]
「さ」行をループしたい場合: hrgn[10+i]
「た」行をループしたい場合: hrgn[15+i]
「な」行をループしたい場合: hrgn[20+i]
「は」行をループしたい場合: hrgn[25+i]
「ま」行をループしたい場合: hrgn[30+i]
「や」行をループしたい場合: hrgn[35+i] ループ回数は３回 for (i = 0; i < 3;...)
「ら」行をループしたい場合: hrgn[38+i]
「わ」行をループしたい場合: hrgn[43+i] ループ回数は３回 for (i = 0; i < 3;...)
「が」行をループしたい場合: hrgn[46+i]
「ざ」行をループしたい場合: hrgn[51+i]
「だ」行をループしたい場合: hrgn[56+i]
「ば」行をループしたい場合: hrgn[61+i]
「ぱ」行をループしたい場合: hrgn[66+i]
「ぁ」行をループしたい場合: hrgn[71+i]
「ゃ」行をループしたい場合: hrgn[76+i] ループ回数は３回 for (i = 0; i < 3;...)

「ゎ」を表示したい場合: hrgn[79]
「っ」を表示したい場合: hrgn[80]
 */
