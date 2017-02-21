#include<cstdio>
#include<cstring>
#include<cmath>
#include<stdlib.h>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;


int prim[500005];
bool vis[5000000]={0};
int num[100005];
struct p
{
	int ta,num;
}obc[100005];
long long sm[100005]={0};
void cal()
{
	int k=0;
	for(int i=2;i<5000005;i++)
	{
		if(vis[i]==0) prim[k++]=i;
		for(int j=0;j<k && prim[j]*i<5000005;j++)
		{
			vis[prim[j]*i]=1;
			if(i%prim[j]==0) break;
		}
	}
}
int main()
{
	int t;
	cal();
	int n,m;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int k=0;k<n;k++)
			num[k]=prim[k]%m;
		sm[0]=1;
		int front=0;
		obc[front].ta=num[0];
		obc[front].num=0;
		for(int k=1;k<n;k++)
		{
			if(num[k]<obc[front].ta) 
			{
				obc[++front].ta=num[k];
				obc[front].num=k;
				sm[k]=1;
			}
			else 
			{
				while(front>-1 && obc[front].ta<=num[k]) front--;
				if(front==-1) sm[k]=k+1;
				else sm[k]=k-obc[front].num;
				obc[++front].ta=num[k];
				obc[front].num=k;
			}
		}
		long long sum=0;
		for(int k=0;k<n;k++)
			sum=sum+sm[k];
		printf("%d\n",sum%m);
	}
    return 0;
}
