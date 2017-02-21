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


int e_gcd(int a,int b,int &x,int &y)
{
	if(b==0)
	{
		x=1;
		y=0;
		return a;
	}
	int ans=e_gcd(b,a%b,x,y);
	int temp=x;
	x=y;
	y=temp-(a/b)*y;
	return ans;
}
int gcd(int a,int b)
{
	int c=a%b;
	while(c)
	{
		a=b;b=c;
		c=a%b;
	}
	return b;
}
int main()
{
	int t,a,m;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&a,&m);
		if(gcd(a,m)>1) printf("Not Exist\n");
		else
		{
			int x,y;
			e_gcd(a,m,x,y);
			if(x>0) while(x-m>0) x-=m;
			else while(x<=0) x+=m;
			printf("%d\n",x);
		}
 	}
    return 0;
}