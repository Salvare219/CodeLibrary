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



int main()
{
//	freopen("1.txt","r",stdin);
	int n,k;
	scanf("%d%d",&n,&k);
	if(n/k<3) printf("-1\n");
	else 
	{
		printf("1 1");
		for(int i=2;i<=k;i++)
			printf(" %d %d",i,i);
		int s=1;
		for(int i=2*k;i<n;i++)
		{
			printf(" %d",s++);
			if(s>k) s=1;
		}
		putchar(10);
	}
	return 0;
}