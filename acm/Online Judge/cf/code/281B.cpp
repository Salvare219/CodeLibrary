#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;



int main()
{
//	freopen("1.txt","r",stdin);
	long long n,x,y;
	long long a,b;
	double temp=9999999;
	int ans[2];
	scanf("%I64d%I64d%I64d",&x,&y,&n);
	for(int i=1;i<=n;i++)
	{
		a=x*i/y;
		b=a+1;
		if(abs((double)(x*i-a*y)/(y*i))<temp) 
		{
			if(ans[0]*a!=ans[1]*i)
			{
				temp=abs((double)(x*i-a*y)/(y*i));
				ans[0]=i;
				ans[1]=a;
			}
		}
		if(abs((double)(x*i-b*y)/(y*i))<temp) 
		{
			if(ans[0]*b!=ans[1]*i)
			{
				temp=abs((double)(x*i-b*y)/(y*i));
				ans[0]=i;
				ans[1]=b;
			}
		}
	}
	printf("%d/%d\n",ans[1],ans[0]);
	return 0;
}