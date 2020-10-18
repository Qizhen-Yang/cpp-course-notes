/*
 *作者: Qizhen Yang
 *输入2个数字，就会输出所需的操作次数（详见题目）
 *只是一个习题，非法输入等情况都没有考虑
 *仅仅作为递归算法的一个小练习
 */
#include <stdio.h>
#include <stdlib.h>

int calc(
	int s, 								//起始
	int t, 								//目标
	int a								//计数
	)
{
	if (s == t)							//操作正常结束
		return a;
	else if (s > t)						//出现错误
		return -1;
	else
	{
		int m, n;
		m = calc(s + 1, t, a + 1);		//递归：增长
		n = calc(s * 2, t, a + 1);		//递归：翻倍
		if (m == -1 && n == -1)			//两者都出现错误
			return -1;					//返回错误
		else if (m == -1)				//一者出现错误
			return n;					//返回正常的
		else if (n == -1)				//一者出现错误
			return m;					//返回正常的
		else							//正常运行
			return m<n ? m : n;			//返回两者较小的（若两者相等，则返回n）
	}
}

int main()
{
	int s, t, a;
	scanf("%d%d", &s, &t);				//输入
	a = calc(s, t, 0);					//将起始，目标输入，并从0开始计数
	if (a == -1)						//出现错误时
		printf("Error\n");				//提示错误
	else								//正常运行
		printf("%d\n", a);				//打印次数
	system("pause");
}