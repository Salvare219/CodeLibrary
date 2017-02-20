#include<cstdio>
#include<cstring>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;  


char str[300];
int main()
{
	int t,s=0;
	scanf("%d",&t);
	while(t--)
	{
		s++;
		int n,time=0;
		scanf("%d",&n);
		scanf("%s",str);
		for(int i=0;i<n;i++)
		{
			if(str[i]=='.')
			{
				time++;
				str[i]='p';
				str[i+1]='p';
				if(i+2<n) str[i+2]='p';
			}
		}
		printf("Case %d: %d\n",s,time);
	}
    return 0;
}