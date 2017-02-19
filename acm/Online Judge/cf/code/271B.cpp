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



int num[1000][1000];
int pri[105005];
bool vis[105050];
int k;
void work()
{
	for(int i=2;i<105050;i++)
	{
		if(vis[i]==0) pri[k++]=i;
		for(int j=0;j<k && pri[j]*i<105050;j++)
		{
			vis[pri[j]*i]=1;
			if(pri[j]%i==0) break;
		}
	}
}
int main()
{
//	freopen("1.txt","r",stdin);
	work();
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			scanf("%d",&num[i][j]);
		}
	int ans=0x7fffffff;
	for(int i=0;i<n;i++)
	{
		int temp=0;
		for(int j=0;j<m;j++)
		{
			int a=*lower_bound(pri,pri+k,num[i][j]);
			temp+=a-num[i][j];
		}
		if(temp<ans) ans=temp;
	}
	for(int i=0;i<m;i++)
	{
		int temp=0;
		for(int j=0;j<n;j++)
		{
			int a=*lower_bound(pri,pri+k,num[j][i]);
			temp+=a-num[j][i];
		}
		if(temp<ans) ans=temp;
	}
	printf("%d\n",ans);
	return 0;
}