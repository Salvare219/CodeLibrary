#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<iostream>
#include<map>
#include<ctime>
using namespace std;



int main()
{
//	freopen("1.txt","r",stdin);
	long long x1,y1,x2,y2,c,d;
	scanf("%I64d%I64d%I64d%I64d%I64d%I64d",&x1,&y1,&x2,&y2,&c,&d);
	if((d-y1)*(x2-x1)==(y2-y1)*(c-x1)) printf("TOWARDS\n");
	else 
	{
		if(y2>y1) 
		{
			if(c>x2) printf("RIGHT\n");
			else printf("LEFT\n");
		}
		else if(y2==y1) 
		{
			if(x2<x1)
			{
				if(d>y2) printf("RIGHT\n");
				else printf("LEFT\n");
			}
			else 
			{
				if(d<y2) printf("RIGHT\n");
				else printf("LEFT\n");
			}
		}
		else 
		{
			if(c<x2) printf("RIGHT\n");
			else printf("LEFT\n");
		}
	}
    return 0;
}