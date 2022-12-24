// "==", "<", ">" の処理時間を計測する

#include<stdio.h>
#include<sys/time.h>
#define CHECK_NUM 1000000000  // 判定回数

// 処理時間を取得する
double gettimeofday_sec() {
  struct timeval t;
  gettimeofday(&t, NULL);
  return (double)t.tv_sec + (double)t.tv_usec * 1e-6;
}

int main() {

  int equal, lt, gt;
  double start, end; // 処理時間計測の開始時間と終了時間

  start = 0;
  end   = 0;
  start = gettimeofday_sec();
  for (equal = 1; equal <= CHECK_NUM; equal++)
    if (equal == CHECK_NUM) {
      end = gettimeofday_sec();
      printf("       equal calculation time = %f\n", (end - start) );
    }

  start = 0;
  end   = 0;
  start = gettimeofday_sec();
  for (lt = CHECK_NUM; lt >= 1; lt--)
    if (lt <= 1) {
      end = gettimeofday_sec();
      printf("   less than calculation time = %f\n", (end - start) );
    }

  start = 0;
  end   = 0;
  start = gettimeofday_sec();
  for (gt = 1; gt <= CHECK_NUM; gt++)
    if (gt >= CHECK_NUM) {
      end = gettimeofday_sec();
      printf("greater than calculation time = %f\n", (end - start) );
    }

  return 0;
}
