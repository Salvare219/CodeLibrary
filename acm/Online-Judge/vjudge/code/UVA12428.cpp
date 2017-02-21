#include<cstdio>
#include<cstring>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;


int main()   
{   
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m,re;
		scanf("%d%d",&n,&m);
		if(m==1 && n==2) printf("1\n");
		else if(m>=(n-1)*n/2) printf("0\n");
		else
		{
			re=m-n+1;
			if(re==0) printf("%d\n",n-1);
			else
			{
				int i=3;
				while(i*(i-1)/2<re+i-1) i++;
				printf("%d\n",n-i);
			}
		}
	}
    return 0;
}