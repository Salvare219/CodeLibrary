#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

set<pair<int, int> > st;

int a[100000];
int dep[100000];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	st.insert({a[0], 0});
	for (int i = 1; i < n; ++i)
	{
		auto it = st.lower_bound({a[i], -1});
		int id = -1;
		if (it != st.end())
		{
			id = it->second;
		}
		if (it != st.begin())
		{
			--it;
			if (id == -1 || (dep[id] < dep[it->second]))
				id = it->second;
		}
		dep[i] = dep[id] + 1;
		printf("%d ", a[id]);
		st.insert({a[i], i});
	}
	puts("");
	return 0;
}