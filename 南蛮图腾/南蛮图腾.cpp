/*
	使用递归进行
	2就是三个1叠加
	3就是三个2叠加
	所以应当先把1画出来
*/
#include <stdio.h>

int Two(int time)						//计算二的time次幂
{
	if (time == 0)
		return 1;						//2^0=1
	else
		return 2 * Two(time - 1);		//2^n=2*2^(n-1)
}

void Draw(int size, int space)			//size: 大小; space: 空格数量
{
	if (size == 1)
	{
		printf(" /\\\n/__\\");			/*当大小为1时打印: 
											 /\
											/__\ */
	}
	else
	{
		for (int i = Two(size - 1); i > 0; i --)
			printf(" ");				//打印出合适数量的空格
		Draw(size - 1, space + Two(size - 1));	//递归
		printf("\n");					//换行
		for (int i = Two(size - 1); i > 0; i --)
			printf(" ");				//打印出合适数量的空格
		Draw(size - 1, space + Two(size - 1));	//递归
		Draw(size - 1, space + Two(size - 1));	//递归
	}
}

int main()
{
	int n;
	scanf("%d", &n);					//输入大小
	Draw(n, 0);							//画图
}