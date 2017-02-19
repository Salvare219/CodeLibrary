#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
using namespace std;


int main()
{
	int n;
	scanf("%d",&n);
	int c=(int)sqrt((double)n);
	if(n==c*c+c) printf("YES\n");
	else
	{
		int d,e,flag=1;
		n*=2;
		for(int i=1;i<c;i++)
		{
			d=n-i*i-i;
			e=(int)sqrt((double)d);
			if(d==e*e+e)
			{
				printf("YES\n");
				flag=0;
				break;
			}
		}
		if(flag) printf("NO\n");
	}
	return 0;
}