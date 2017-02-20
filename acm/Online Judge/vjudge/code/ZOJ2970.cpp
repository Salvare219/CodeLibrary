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
	while(t--)
	{
		char str[15];
		int n,temp,min=99999,max=-1;
		scanf("%s",str);
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&temp);
			if(temp>max) max=temp;
			if(min>temp) min=temp;
		}
		if(str[0]=='F') printf("%d\n",min);
		else printf("%d\n",max);
	}
    return 0;
}