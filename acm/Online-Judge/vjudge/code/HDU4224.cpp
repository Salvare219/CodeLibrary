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
	int t;
	scanf("%d",&t);
	for(int k=0;k<t;k++)
	{
		printf("Case %d: ",k+1);
		int num[3][2];
		int da=0,xi=0;
		for(int i=0;i<3;i++)
		{
			scanf("%d%d",&num[i][0],&num[i][1]);
			if(num[i][0]>num[i][1]) da=1;
			else if(num[i][0]<num[i][1]) xi=1;
		}
		if(da==0 && xi==0) printf("Yes\n");
		else 
		{
			if(da==1 && xi==1) printf("Yes\n");
			else printf("No\n");
		}
	}
    return 0;
}
