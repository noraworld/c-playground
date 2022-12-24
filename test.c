#include<stdio.h>
#include<stdlib.h>
#include<time.h>/* 追加部分 */

int main()
{
	int sai, i;
	srand((unsigned)time(NULL));/* 追加部分 */

	for(i = 0; i < 10; i++)
	{
		sai = rand() % 6 + 1;
		printf("出た目は = %d\n",sai);
	}

	return 0;
}
