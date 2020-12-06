#include <stdio.h>

int pos[100000];
// pos[r] 表示 r 这个数
// 第一次出现在余数序列的哪个位置


int main()
{
	// 初始化
	int p, q;								// 分子，分母
	scanf("%d%d", &p, &q);					// 输入
	
	// 整数部分
	printf("%d", p / q);					// 输出除法得到的整数部分

	// 没有小数部分的情况
	int r = p % q;							// 取余
	if (r == 0)								// 如果余数为0
		return 0;							// 结束

	//小数点
	printf(".");							// 输出小数点
	int step = 1;							// 小数点后的数位

	// [类比除法竖式] “探查情况”
	while (r != 0 && pos[r] == 0)			// 余数之前没有出现过
	{
		pos[r] = step;						// 记录
		r = r * 10 % q;						// 补零再除
		step ++;							// 小数位加一
	}

	// 探查完毕，正式输出
	if (r != 0)								// 余数不为零
	{
		int left = pos[r];					// 循环开始的地方
		int r = p % q;						// 取余（从头再来一遍）
		for (int i = 1; i < left; i ++)		// 不循环的部分：挨个输出
		{
			printf("%d", 10 * r / q);
			r = 10 * r % q;
		}
		printf("(");						// 循环开始
		for (int i = left; i < step; i ++)	// 循环的部分：挨个输出
		{
			printf("%d", 10 * r / q);
			r = 10 * r % q;
		}
		printf(")");						// 循环结束
	}
	else									// 余数为零（除的尽）
	{
		for (int i = 1; i < step; i ++)		// 直接挨个输出
		{
			printf("%d", 10 * r / q);
			r = 10 * r % q;
		}
	}
	
	return 0;
}
