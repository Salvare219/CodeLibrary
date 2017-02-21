#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;



int num[100005];
int main()
{
//	freopen("1.txt","r",stdin);
	int n,t;
	scanf("%d%d",&n,&t);
	for(int i=0;i<n;i++)
	{
		scanf("%d",num+i);
	}
	int sta=0,now=0,ans=0,how=0;
	for(int i=0;i<n;i++)
	{
		if(num[i]>t) 
		{
			now=0;
			how=0;
			continue;
		}
		while(now+num[i]>t) 
		{
			now-=num[sta++];
			how--;
		}
		now+=num[i];
		how++;
		ans=max(ans,how);
	}
	printf("%d\n",ans);
    return 0;
}