#include <stdio.h>

char canvas [2049][1025];			//画布: 1024x2048

void draw(
			int size, 				//大小
			int x, 					//标记横轴
			int y					//标记纵轴
)
{
	if (size == 1)					//边长为2的基础三角形
	{
		//第一行
		canvas [x][y] = ' ';
		canvas [x+1][y] = '/';
		canvas [x+2][y] = '\\';
		canvas [x+3][y] = ' ';
		//第二行
		canvas [x][y+1] = '/';
		canvas [x+1][y+1] = '_';
		canvas [x+2][y+1] = '_';
		canvas [x+3][y+1] = '\\';
	}
	else							//递归部分
	{
		int len = 1 << (size - 1);	//2的(size-1)次幂
		draw(size - 1, x + len, y);
		draw(size - 1, x, y + len);
		draw(size - 1, x + len * 2, y + len);
	}
}

int main()
{
	int n;
	scanf("%d", &n);				//输入
	draw(n, 0, 0);					//从坐标(0,0)开始作图
	int len = 1 << n;				//2的n次幂
	for (int y = 0; y < len; y ++)
	{
		for (int x = 0; x < len*2; x ++)
			printf("%c", canvas [x][y]);
		printf("\n");
	}
}