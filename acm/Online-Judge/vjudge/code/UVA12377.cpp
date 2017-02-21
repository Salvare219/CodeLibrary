#include<cstdio>
#include<cstring>
#include<cmath>
#include<stdlib.h>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;


char str[29];
int C[10][10];
long long ans;
int fac[]={1,1,2,6,24,120,720,5040,40320,362880};
void cal()
{
	for(int i=0;i<=9;i++)
		for(int j=0;j<=i;j++)
		{
			C[i][j]=fac[i]/(fac[j]*fac[i-j]);
		}
}
int ll[15];
int num;
void dfs(int num,int sta,int resl,int resn)
{
	if(resn==1)
	{
		for(int i=sta;str[i];i++)
			ll[num]=ll[num]*10+str[i]-'0';
		int flag=0,sama[10]={0};
 		sama[0]++;
		int k=0;
		for(int i=1;i<num+1;i++)
		{
			if(ll[i]==ll[i-1])
			{
				sama[k]++;
			}
			else if(ll[i-1]>ll[i]) 
			{
				flag=1;
				break;
			}
			else 
			{
				sama[++k]=1;
			}
		}
		long long A=1;
		ll[num]=0;
		for(int i=0;i<=k;i++)
			A*=fac[sama[i]];
		if(flag==0) ans=ans+fac[num+1]/A;
		else return;
	}
	else
	{
		int lim=resl/resn;
		for(int i=1;i<=lim;i++)
		{
			for(int j=0;j<i;j++)
			{
				ll[num]=ll[num]*10+str[j+sta]-'0';
			}
			if(str[sta+i]=='0') 
			{
				ll[num]=0;
				continue;
			}
			dfs(num+1,sta+i,resl-i,resn-1);
			ll[num]=0;
		}
	}
}
int main()
{
//	freopen("1.txt","r",stdin);
	int t;
	cal();
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",str);
		if(str[0]=='1') printf("9\n");
		else if(str[0]=='0') printf("0\n");
		else
		{
			ans=0;
			num=str[0]-'0';
			int act=strlen(str)-1;
			dfs(0,1,act,num);
			printf("%d\n",C[9][num]*ans);
		}
	}
    return 0;
}
