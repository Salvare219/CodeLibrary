#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int n, a, b, c, d;
	scanf("%d %d %d %d %d", &n, &a, &b, &c, &d);
	int m = abs(a - d) + abs(b - c);
	if (m >= n)
		puts("0");
	else
		printf("%I64d\n", 1ll * n * (n - m));
	return 0;
}