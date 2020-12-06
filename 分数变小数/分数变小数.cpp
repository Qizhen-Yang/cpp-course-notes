#include <stdio.h>

int pos[100000];
// pos[r] 表示 r 这个数
// 第一次出现在余数序列的哪个位置


int main()
{
	int p, q;							// 分子，分母
	scanf("%d%d", &p, &q);				// 输入
	printf("%d", p / q);				// 输出除法得到的整数部分

	int r = p % q;						// 取余
	if (r == 0)							// 如果余数为0
		return 0;						// 结束

	printf(".");						// 输出小数点
	int step = 1;						// 小数点后的数位

	while (r != 0 && pos[r] == 0)		// 
	{
		pos[r] = step;	  	
		r = r * 10 % q;
		step ++;	
	}
	if (r != 0)
	{
		int left = pos[r];
		int r = p%q;
		for (int i = 1; i < left; ++i)
		{
			cout << 10*r/q;
			r = 10*r%q;
		}
	cout << "(";
	for (int i = left; i < step; ++i)
	{
		cout << 10*r/q;
		r = 10*r%q;
	}
	cout << ")";
	}
	else
	{
		for (int i = 1; i < step; ++i)
		{
			cout << 10*r/q;
			r = 10*r%q;
		}
	}
}
