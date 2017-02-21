#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<iostream>
#include<map>
using namespace std;



int main()
{
//	freopen("1.txt","r",stdin);
	int n,ans;
	scanf("%d",&n);
	for(int i=n+1;1;i++)
	{
		bool vis[20]={0};
		int a=i/1000;
		int b=i/100-a*10;
		int d=i%10;
		int c=(i%100-d)/10;
		vis[a]=1;vis[b]=1;
		vis[c]=1;vis[d]=1;
		int time=0;
		for(int j=0;j<10;j++)
		{
			if(vis[j]) time++;
		}
		if(time==4)
		{
			ans=i;
			break;
		}
	}
	printf("%d\n",ans);
	return 0;
}