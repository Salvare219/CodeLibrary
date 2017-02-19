#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("horrible.in","r",stdin);
	freopen("horrible.out","w",stdout);
	int n,i,j;
	scanf("%d",&n);
	if(n==1)
		return puts("1\n1 0");
	printf("%d\n",(n-1)*(2*n-1)+3);
	puts("2 -1\n1 0");
	for(i=1;i<n;printf("%d 0\n",++i))
		for(j=1;j<=n;j++)
		{
			if(i+1!=j)
				printf("%d -%d\n",j,i+1);
			if(i!=j)
				printf("%d %d\n",j,i);
		}
	printf("%d %d\n",1,n);
	return 0;
}
