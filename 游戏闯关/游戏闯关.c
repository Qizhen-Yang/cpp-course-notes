#include <stdio.h>

int main(int argv, char *argc[])
{
	int n, t;
	scanf("%d%d", &n, &t);
	int a[n + 1], b[n + 1], aa[n + 1], bb[n + 1];
	int i;
	for (i = 0; i < n; i ++)
	{
		scanf("%d", &a[i]);
		aa[i] = aa[i] + a[i];
	}
	for (i = 0; i < n; i++)
	{
		scanf("%d", &b[i]);
		aa[i] = aa[i] + a[i];
	}
	int jg=0;
	int j=n;
	for(int i = 0; i <= n; i ++)
	{
		while(aa[i] + bb[j] > t && j >= 1 )
			j --;
		if(aa[i] + bb[j] <=t )
			jg = (jg > i + j) ? jg : (i + j);
	}
	printf("%d", jg);
	return 0;
}