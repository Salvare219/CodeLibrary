#include <cstdio>
#include <map>

using namespace std;

map<long long, int> mp;

int a[100000];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	long long sum = 0;
	long long last = 0;
	for (int i = 0; i < n; ++i)
	{
		mp[sum]++;
		sum += a[i];
	}
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		ans = max(ans, mp[last]);
		mp[last]--;
		mp[sum]++;
		last += a[i];
		sum += a[i];
	}
	printf("%d\n", n - ans);
	return 0;
}