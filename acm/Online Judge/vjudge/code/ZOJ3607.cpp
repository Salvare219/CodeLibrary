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
#define eps 1e-8


int d[2000];
int bra[2000],tot[2000];
int ti[2000];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",bra+i);
			if(i==0) tot[i]=bra[i];
			else tot[i]=tot[i-1]+bra[i];
		}
		for(int i=0;i<n;i++)
		{
			scanf("%d",ti+i);
			if(i==0) 
			{
				d[i]=ti[i];
			}
			else 
			{
				d[i]=ti[i]-ti[i-1];
			}
		}
		double ava=0,get=0;
		int now=0;
		for(int i=0;i<n;i++)
		{
			if(i==0)
			{
				now=d[i];
				continue;
			}
			if(now>=d[i])
			{
				continue;
			}
			else 
			{
				double temp=(double)tot[i-1]/i;
				if(temp>ava)
				{
					ava=temp;
					get=now;
				}
				now=d[i];
			}
		}
		double o=(double)tot[n-1]/n;
		if(o>ava)
		{
			ava=o;
			int m=0;
			for(int i=0;i<n;i++)
				if(d[i]>m) m=d[i];
			get=(double)m;
		}
		printf("%.6lf %.6lf\n",get,ava);
 	}
    return 0;
}