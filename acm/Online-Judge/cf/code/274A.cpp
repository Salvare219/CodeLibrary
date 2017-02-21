#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;



int num[200000];
bool vis[200000];
map<int,int> p;
map<int,bool>has;
int main()
{
//	freopen("1.txt","r",stdin);
	int n,s;
	scanf("%d%d",&n,&s);
	long long k=s;
	for(int i=0;i<n;i++)
	{
		scanf("%d",num+i);
		has[num[i]]=1;
	}
	int ans=0;
	sort(num,num+n);
	for(int i=0;i<n;i++)
	{
		p[num[i]]=i;
	}
	for(int i=0;i<n;i++)
	{
		if(vis[i]==0)
		{
			ans++;
			long long temp=k*num[i];
			if(temp<=0x7fffffff)
			{
				if(has[temp])
				{
					vis[p[temp]]=1;
				}
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}