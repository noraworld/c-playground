#include<stdio.h>
#define ELEMENT (16)
#define ESC (-1)

int main() {

  char ascii[ELEMENT]      = {0};
  int ascii_input[ELEMENT] = {0};
  int menu, i, j;

  // 実行したいメニューの選択
  puts("実行したいメニューを入力してください.");
  do {
    printf("ASCII制御文字表示[0], ASCII出力可能文字[1], ASCIIコード入力[2], 終了[3]: ");
    scanf("%d", &menu);

    if (menu == 0) {
      puts(" -------------------------------------------------------------------------------------- ");
      puts("|   0: NULL           |  8: 後退         | 16: 伝送制御拡張     | 24: 取消             |");
      puts("|   1: ヘディング開始 |  9: 水平タブ     | 17: 装置制御         | 25: 媒体終端         |");
      puts("|   2: テキスト開始   | 10: 改行         | 18: 装置制御2        | 26: 置換             |");
      puts("|   3: テキスト終了   | 11: 垂直タブ     | 19: 装置制御3        | 27: エスケープ       |");
      puts("|   4: 伝送終了       | 12: 書式送り     | 20: 装置制御         | 28: ファイル分離標識 |");
      puts("|   5: 問い合わせ     | 13: 復帰         | 21: 否定応答         | 29: グループ分離標識 |");
      puts("|   6: 肯定応答       | 14: シフトアウト | 22: 同期信号         | 30: レコード分離標識 |");
      puts("|   7: ベル           | 15: シフトイン   | 23: 伝送ブロック終結 | 31: ユニット分離標識 |");
      puts("| --------------------+------------------+----------------------+--------------------- |");
      puts("| 127: 抹消           |                  |                      |                      |");
      puts(" -------------------------------------------------------------------------------------- ");
    }

    else if (menu == 1) {
      puts(" --------------------------------------------------------------------------------------- ");
      puts("|   32: SP |   42: *  |   52: 4  |   62: >  |   72: H  |   82: R  |   92: \\  |  102: f  |");
      puts("|   33: !  |   43: +  |   53: 5  |   63: ?  |   73: I  |   83: S  |   93: ]  |  103: g  |");
      puts("|   34: \"  |   44: ,  |   54: 6  |   64: @  |   74: J  |   84: T  |   94: ^  |  104: h  |");
      puts("|   35: #  |   45: -  |   55: 7  |   65: A  |   75: K  |   85: U  |   95: _  |  105: i  |");
      puts("|   36: $  |   46: .  |   56: 8  |   66: B  |   76: L  |   86: V  |   96: `  |  106: j  |");
      puts("|   37: %  |   47: /  |   57: 9  |   67: C  |   77: M  |   87: W  |   97: a  |  107: k  |");
      puts("|   38: &  |   48: 0  |   58: :  |   68: D  |   78: N  |   88: X  |   98: b  |  108: l  |");
      puts("|   39: \'  |   49: 1  |   59: ;  |   69: E  |   79: O  |   89: Y  |   99: c  |  109: m  |");
      puts("|   40: (  |   50: 2  |   60: <  |   70: F  |   80: P  |   90: Z  |  100: d  |  110: n  |");
      puts("|   41: )  |   51: 3  |   61: =  |   71: G  |   81: Q  |   91: [  |  101: e  |  111: o  |");
      puts("| ---------+----------+----------+----------+----------+----------+----------+--------- |");
      puts("|  112: p  |  114: r  |  116: t  |  118: v  |  120: x  |  122: z  |  124: |  |  126: ~  |");
      puts("|  113: q  |  115: s  |  117: u  |  119: w  |  121: y  |  123: {  |  125: }  |          |");
      puts(" --------------------------------------------------------------------------------------- ");
    }

    else if (menu == 3)
      return ESC;

    else
      puts("不正な入力です. 0〜3の数値で入力してください.");

  } while (menu != 2);


  // ASCIIコードを入出力する
  if (menu == 2) {

    // ASCIIコードの入力
    printf("0〜127の10進数で入力. 128で入力終了. 最大%d文字まで可.\n", ELEMENT);
    for (i = 0; i < ELEMENT; i++) {
      printf("ascii[%02d]: ", i);
      scanf("%d", &ascii_input[i]);

      // 128で入力終了
      if (ascii_input[i] == 128)
	break;

      // 0〜127の範囲外の数字が入力されたら再入力
      if (ascii_input[i] > 128 || ascii_input[i] < 0) {
	puts("無効な数値です. 0〜127の数値で入力してください.");
	i--;
	continue;
      }

      // int型の数字をchar型の変数に代入
      ascii[i] = ascii_input[i];
    }

    // 一番最初のASCIIコードが128なら何も入力されていないので終了
    if (ascii_input[0] == 128) {
      puts("ASCIIコードは入力されませんでした.");
      return ESC;
    }

    // ASCIIコードの10進数表記を16進数表記に変換
    puts("\n入力コードの16進数表記");
    for (j = 0; j < i; j++)
      printf("%x ", ascii_input[j]);
    puts("\n");

    // 実際のASCIIコードの出力
    puts("-----output-----");
    for (j = 0; j < i; j++)
      printf("%c", ascii[j]);
    if ( !(ascii[j-1] == 10) && (j > 0) )
      puts("");
    puts("----------------");
  }


  return 0;
}
