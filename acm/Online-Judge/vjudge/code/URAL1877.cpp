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
	int a[2],max=0;
	scanf("%d%d",&a[0],&a[1]);
	for(int i=0;i<10000;i++)
	{
		if(a[i%2]==i) 
		{
			max=1;
			break;
		}
	}
	if(max) printf("yes\n");
	else printf("no\n");
    return 0;
}