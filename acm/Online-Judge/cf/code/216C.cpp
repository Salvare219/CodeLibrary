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


int fin[50005];
int main()
{
//	freopen("1.txt","r",stdin);
	int n,m,k,num,sp;
	scanf("%d%d%d",&n,&m,&k);
	int mod=(m+1)%n;
	if(k!=1)
	{
		if(mod==0 || mod==1) 
		{
			num=((m+1)/n)*k+k;
			printf("%d\n1",num+mod);
			int now=0+(k==1);
			for(int i=1;i<num;i++)
			{
				if(i%k==1) now++;
				if(i%k==0) now+=n-1;
				printf(" %d",now);
			}
			if(mod) printf(" %d",now+n-1);
		}
		else 
		{
			num=((m+1)/n)*k+2*k;
			printf("%d\n1",num);
			int now=0+(k==1);
			for(int i=1;i<num;i++)
			{
				if(i%k==1) now++;
				if(i%k==0) now+=n-1;
				printf(" %d",now);
			}
		}
	}
	else
	{
		int k=1;
		fin[0]=1;
		int z=n;
		while(z<=n+m)
		{
			fin[k++]=z;
			z+=n-1;
		}
		printf("%d\n1",k);
		for(int i=1;i<k;i++)
			printf(" %d",fin[i]);
	}
	putchar(10);
    return 0;
}