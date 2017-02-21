#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 1 << 17;

pair<int, int> tree[maxn << 1];
int a[maxn];
int dp[maxn];

int get(int l, int r)
{
	pair<int, int> mx = {-1, -1};
	for (l += maxn - 1, r += maxn + 1; l ^ r ^ 1; l >>= 1, r >>= 1)
	{
		if (~l & 1)
			mx = max(mx, tree[l ^ 1]);
		if (r & 1)
			mx = max(mx, tree[r ^ 1]);
	}
	return mx.second;
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; ++i)
		scanf("%d", &a[i]);
	a[n - 1] = 1e9;
	for (int i = 1; i <= n; ++i)
		tree[maxn + i] = {a[i - 1], i};
	for (int i = maxn - 1; i > 0; --i)
		tree[i] = max(tree[i << 1], tree[i << 1 | 1]);
	long long ans = 0;
	for (int i = 0; i < n - 1; ++i)
	{
		dp[i]++;
		int t = get(i + 2, a[i]);
		ans += 1ll * dp[i] * (n - (i + 1) - (a[i] - t));
		dp[t - 1] += dp[i];
	}
	printf("%I64d\n", ans);
	return 0;
}