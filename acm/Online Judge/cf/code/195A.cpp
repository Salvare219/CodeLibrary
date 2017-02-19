#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
using namespace std;


int main()
{
	int a,b,c,t;
	scanf("%d%d%d",&a,&b,&c);
	t=a*c;
	if(((a-b)*t)%(a*b)) c=(a-b)*t/(a*b)+1;
	else c=(a-b)*t/(a*b);
	if(c<0) c=0;
	printf("%d\n",c);
	return 0;
}