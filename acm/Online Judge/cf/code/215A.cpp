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


int a[1000],b[1000];
int s[100000]={0};
int main()
{
	int n,m;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",a+i);
	scanf("%d",&m);
	for(int i=0;i<m;i++)
		scanf("%d",b+i);
	int maxx=-1,time=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			int ss=(b[j]/a[i]);
			if(ss*a[i]==b[j])
			{
				if(ss>maxx) 
				{
					maxx=ss;
					time=1;
				}
				else if(ss==maxx)
				{
					time++;
				}
			}
		}
	printf("%d\n",time);
    return 0;
}