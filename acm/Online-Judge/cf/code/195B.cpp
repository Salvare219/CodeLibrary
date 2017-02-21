#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
using namespace std;

int p[100005],num[2]={1,-1};
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	if(m%2)
	{
		p[0]=m/2+1;
		for(int i=1;i<m;i++)
			p[i]=m/2+1+num[i%2]*((i+1)/2);
	}
	else 
	{
		p[0]=m/2;
		for(int i=1;i<m;i++)
			p[i]=m/2+num[(i+1)%2]*((i+1)/2);
	}
	for(int i=0;i<n;i++)
		printf("%d\n",p[i%m]);
	return 0;
}