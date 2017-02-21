#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;



int gra[10005];
int main()
{
//	freopen("1.txt","r",stdin);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m,x,y;
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)
			gra[i+1]=0;
		for(int i=0;i<m;i++)
		{
			scanf("%d%d",&x,&y);
			gra[x]++;
			gra[y]++;
		}
		long long ans=0,temp;
		for(int i=0;i<n;i++)
		{
			temp=gra[i+1];
			ans+=temp*temp;
		}
		printf("%lld\n",ans);
		if(t) putchar(10);
	}
	return 0;
}