#include<cstdio>
#include<cstring>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;
#define INF 0x7fffffff
#define eps 0.000000001


double k[5009],b[5009];
double hid[5009][2],l,r;
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
			hid[i][0]=-INF;
			hid[i][1]=INF;
		}
		for(int i=0;i<n;i++)
			scanf("%lf%lf",k+i,b+i);
		if(n==1) printf("1\n");
		else
		{
			int time=0;
			for(int i=0;i<n;i++)
			{
				for(int j=i+1;j<n;j++)
				{
						double a=k[i]-k[j],c=b[j]-b[i];
	if(a==0) 
	{
		if(c>0) 
		{
			r=-INF;
			l=INF;
		}
		else 
		{
			r=INF;
			l=-INF;
		}
	}
	else
	{
		double x=c/a;
		if(k[j]>k[i]) 
		{
			l=-INF;
			r=x;
		}
		else if(k[j]<k[i])
		{
			l=x;
			r=INF;
		}
		else
		{
			r=-INF;
			l=INF;
		}
	}
					if(l>hid[i][0]) hid[i][0]=l;
					if(hid[i][1]>r) hid[i][1]=r;
					if(l==-INF){if(hid[j][0]<r) hid[j][0]=r;}
					else{if(hid[j][1]>l) hid[j][1]=l;}
				}
				if(eps<=hid[i][1]-hid[i][0]) time++;
			}
			printf("%d\n",time);
		}
	}
    return 0;
}