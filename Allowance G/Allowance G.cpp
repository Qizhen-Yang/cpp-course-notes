#include <stdio.h>

long long v[100], b[100];
long long n, c;

bool pay(long long c)
{
	for (int i = 0; i < n; i ++)
	{
		while (b[i] > 0 && c > 0)
		{
			b[i] --;
			c -= v[i];
		}
	}
	for (int i = n - 1; i >= 0; i --)
	{
		while (b[i] > 0 && c > 0)
		{
			b[i] --;
			c -= v[i];
		}
	}
	return c <= 0;
}

int main()
{
	scanf("%d%d", &n, &c);
	for (int i = 0; i < n; i ++)
		scanf("%d%d", &v[i], &b[i]);
	for (int i = 0; i < n; i ++)
	{
		for (int j = i + 1; j < n; j ++)
		{
			int t;

			t = v[i];
			v[i] = v[j];
			v[j] = t;

			t = b[i];
			b[i] = b[j];
			b[j] = t;
		}
	}
	int ans = 0;
	while (pay(c))
		ans ++;
	printf("%d\n", ans);
}