#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;


int num[200005],con[200005];
map<int,int> mp;
map<int,int>::iterator a; 
int main()
{
//	freopen("1.txt","r",stdin);
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=0;i<n;i++)
	{
		scanf("%d",num+i);
	}
	sort(num,num+n);
	for(int i=0;i<q;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		con[x-1]++;
		con[y]--;
	}
	int time=0;
	for(int i=0;i<n;i++)
	{
		time+=con[i];
		mp[time]++;
	}
	long long sum=0;
	int k=0;
	for(a=mp.begin();a!=mp.end();a++)
	{
		for(int i=0;i<a->second;i++)
		{
			sum+=(long long)num[k++]*a->first;
		}
	}
	printf("%I64d\n",sum);
	return 0;
}