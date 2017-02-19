#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<iostream>
#include<map>
#include<set>
using namespace std;


char sta[20],temp[20];
int main()
{
	int n;
	scanf("%d",&n);
	sprintf(sta,"%d",n);
	int len=strlen(sta);
	int ans=0;
	for(int i=1;i*i<=n;i++)
	{
		if(n%i==0) 
		{
			sprintf(temp,"%d",i);
			for(int i=0;i<len;i++)
				if(strchr(temp,sta[i])!=NULL)
				{
					ans++;
					break;
				}
			if(n/i==i) continue;
			sprintf(temp,"%d",n/i);
			for(int i=0;i<len;i++)
				if(strchr(temp,sta[i])!=NULL)
				{
					ans++;
					break;
				}
		}
	}
	printf("%d\n",ans);
	return 0;
}
