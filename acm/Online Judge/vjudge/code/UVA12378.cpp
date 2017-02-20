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


int pp[100005];
char str[100005];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",str);
		int len=strlen(str),k=0;
		for(int i=0;i<len;i++)
			if(str[i]!=str[i+1]) str[k++]=str[i];
		str[k]='%';
		int mx = 0;
		int id;
		for(int i=0; i<k; i++)
		{
			if( mx > i )
				pp[i] = min( pp[2*id-i], mx-i );
			else
				pp[i] = 1;
			for(;str[i+pp[i]] == str[i-pp[i]]; pp[i]++);
			if( pp[i] + i > mx )
			{
				mx = pp[i] + i;
				id = i;
			}
		}
		int max=0;
		for(int i=0;i<k;i++)
			if(pp[i]>max) max=pp[i];
		printf("%d\n",max);
	}
    return 0;
}