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
	int n;
	long long ans=0,a1,a2,a3=0;
	scanf("%d",&n);
	if(n==1) printf("1\n");
	else if(n==2) printf("2\n");
	else if(n==3) printf("6\n");
	else
	{
		if(n%2==0) 
		{
			a1=(long long)n*(n-1)*(n-2)/2;
			a2=(long long)(n-1)*(n-2)*(n-3);
			for(int i=n-3;i>=(n/2);i--)
				if(gcd(i,n)==1 && gcd(i,n-1)==1) 
				{
					a3=(long long)n*(n-1)*i;
					break;
				}
			a1=max(a1,a3);
			ans=max(a1,a2);
		}
		else ans=(long long)n*(n-1)*(n-2);
		printf("%I64d\n",ans);
	}
    return 0;
}