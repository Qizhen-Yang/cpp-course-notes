#include <stdio.h>

int pos[100000];
// pos[r]表示 r这个数
// 第一次出现在余数序列的哪个位置


int main()
{
	int p, q;							// 分子，分母
	cin >> p >> q;
	cout << p/q;
	int r = p % q;
	if (r == 0)
		return 0;
	cout << ".";  
	int step = 1;
	while (r != 0 && pos[r] == 0)
	{
		pos[r] = step;	  	
		r = r * 10 % q;
		step ++;	
	}
	if (r != 0)
	{
		int left = pos[r];
		int r = p%q;
	}
}
