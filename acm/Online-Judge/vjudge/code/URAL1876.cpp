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


int main()
{
//	freopen("1.txt","r",stdin);
	int a,b,max=0;
	scanf("%d%d",&a,&b);
	for(int i=0;i<=40;i++)
	{
		int time;
		if(i!=40) time=i+2*a;
		else time=2*b+40;
		if(time>max) max=time;
	}
	printf("%d\n",max);
    return 0;
}