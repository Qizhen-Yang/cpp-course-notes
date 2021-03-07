#include <stdio.h>

int Cut(int n, int k)
{
	if (n % k == 0 || n == 0 || k == 0)
		return 0;
	else if (k % n == 0)
		return (k - n);			// (k / n - 1) / n = k - n
	else if (n > k)
		return Cut(n - k, k);	// first give each people one then cut
	else						// k > n
		return Cut(n, k - n) + n;
}

int main(int argv, char *argc[])
{
	int n, k;
	scanf("%d%d", &n, &k);
	printf("%d", Cut(n, k));
	return 0;
}