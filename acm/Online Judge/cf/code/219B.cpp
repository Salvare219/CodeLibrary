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


int num(long long a)
{
	int n=0;
	while(a)
	{
		a/=10;
		n++;
	}
	return n;
}
long long pp[40];
int main()
{
//	freopen("3.txt","r",stdin);
	long long d,p,temp=0;
	pp[0]=1;
	for(int i=1;i<20;i++)
		pp[i]=pp[i-1]*10;
	scanf("%I64d%I64d",&p,&d);
	int n=num(p);
	for(int i=0;i<n;i++)
		temp=temp*10+9;
	for(int i=0;i<n;i++)
	{
		temp=temp-9*pp[n-i-1]+p/pp[n-i-1]%10*pp[n-1-i];
		if(p-temp>=0 && p-temp<=d)
		{
			printf("%I64d\n",temp);
			break;
		}
		temp=temp-pp[n-i-1];
		if(p-temp>=0 && p-temp<=d)
		{
			printf("%I64d\n",temp);
			break;
		}
		temp=temp+pp[n-i-1];
	}
	return 0;
}