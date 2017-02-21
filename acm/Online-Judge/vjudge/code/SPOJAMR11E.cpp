#include<cstdio>
#include<cstring>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;  


bool vis[8009]={0};
int prim[1100];
void cal()
{
	vis[0]=vis[1]=1;
	int flag,k=0;
	for(long long i=2;i<8000;i++)
	{
		flag=1;
		for(int j=2;j*j<=i;j++)
			if(i%j==0) 
			{
				flag=0;
				break;
			}
			if(flag) 
			{
				vis[i]=1;
				prim[k++]=i;
			}
	}
}
int num[1005];
void ini()
{
	for(int i=4;i<8000;i++)
	{
		int a=i;
		if(vis[i]) continue;
		int time=0;
		for(int j=0;j<1001 && time<2;j++)
		{
			int flag=0;
			while(a%prim[j]==0)
			{
				a/=prim[j];
				flag=1;
			}
			if(a==1) break;
			time+=flag;
		}
		if(a==1) vis[i]=1;
	}
	int k=0;
	for(int i=0;i<8000 && k<1001;i++)
		if(vis[i]==0) num[k++]=i;
}
int main()
{
//	freopen("1.txt","r",stdin);
	int t;
	cal();
	ini();
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		printf("%d\n",num[n-1]);
	}
    return 0;
}