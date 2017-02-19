#include<stdio.h>
#include<string.h>

int main()
{
	int n,m,a,l,w;
	long long ans;
	scanf("%d%d%d",&n,&m,&a);
	l=n/a;w=m/a;
	if(n%a>0) l++;
	if(m%a>0) w++;
	ans=(long long)l*w;
	printf("%I64d",ans);
	return 0;
}