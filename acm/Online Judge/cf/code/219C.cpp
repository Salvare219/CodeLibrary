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
#define INF 0x7fffffff


char str[600000];
int main()
{
//	freopen("3.txt","r",stdin);
	int n,k;
	scanf("%d%d%s",&n,&k,str);
	if(k==2)
	{
		int a=1,b=0,ta=0,tb=0;
		for(int i=0;i<n;i++)
		{
			if(a+'A'!=str[i]) ta++;
			if(b+'A'!=str[i]) tb++;
			a=(a+1)%2;b=(b+1)%2;
		}
		if(ta>tb) 
		{
			printf("%d\n",tb);
			for(int i=0;i<n;i++)
				printf("%c",'A'+i%2);
			putchar(10);
		}
		else 
		{
			printf("%d\n",ta);
			for(int i=0;i<n;i++)
				printf("%c",'A'+(i+1)%2);
			putchar(10);
		}
	}
	else 
	{
		int time=0;
		for(int i=1;i<n;i++)
		{
			if(str[i]==str[i-1]) 
			{
				for(int j=0;j<5;j++)
				{
					if(str[i+1]-'A'==j) continue;
					if(str[i-1]-'A'==j) continue;
					str[i]='A'+j;
					break;
				}
				time++;
			}
		}
		printf("%d\n",time);
		printf("%s\n",str);
	}
	return 0;
}