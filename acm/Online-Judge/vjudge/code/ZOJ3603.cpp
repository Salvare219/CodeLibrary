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
#define eps 1e-8


char str[50];
int num[50][26];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		memset(num,0,sizeof(num));
		for(int i=0;i<n;i++)
		{
			scanf("%s",str);
			for(int j=0;str[j];j++)
			{
				num[i][str[j]-'A']++;
			}
		}
		for(int i=n-2;i>-1;i--)
		{
			for(int j=0;j<26;j++)
			{
				num[i][j]=min(num[i][j],num[i+1][j]);
			}
		}
		for(int i=0;i<26;i++)
		{
			if(num[0][i]==0) continue;
			else
			{
				while(num[0][i])
				{
					putchar(i+'A');
					num[0][i]--;
				}
			}
		}
		putchar(10);
 	}
    return 0;
}