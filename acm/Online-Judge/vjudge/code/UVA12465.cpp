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
#define INF 0x7fffffff
#define mod 1000000009


int num[500000];
int k,prim[500000];
void cal()
{
	k=0;
	bool vis[1000000]={0};
	for(int i=2;i<1000000;i++)
	{
		if(vis[i]==0) prim[k++]=i;
		for(int j=0;j<k && prim[j]*i<1000000;j++)
		{
			vis[prim[j]*i]=1;
			if(i%prim[j]==0) break;
		}
	}
}
bool is_prim(long long a)
{
	for(int i=2;i*i<=a;i++)
		if(a%i==0) return 0;
	return 1;
}
int main()
{
	long long a,b;
	cal();
	while(scanf("%lld%lld",&a,&b))
	{
		if(a==0 && b==0) break;
		long long sum=a-b;
		if(sum<0) sum=-sum;
		if(sum==1) printf("1\n");
		else
		{
			int z=0,flag=0;
			num[z]=0;
			for(int i=0;sum!=1;i++)
			{
				flag=0;
				if(is_prim(sum)) 
				{
					z++;
					num[z]=1;
					z++;
					break;
				}
				while(sum%prim[i]==0) 
				{
					flag=1;
					sum=sum/prim[i];
					num[z]++;
				}
				if(flag)
				{
					z++;
					num[z]=0;
				}
			}
			sum=1;
			for(int i=0;i<z;i++)
			{
				sum=sum*(num[i]+1);
			}
			printf("%lld\n",sum);
		}
	}
    return 0;
}