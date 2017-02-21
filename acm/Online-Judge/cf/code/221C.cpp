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


int num[500000];
int temp[600000];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",num+i);
		temp[i]=num[i];
	}
	int f=0;
	bool ff=1;
	sort(num,num+n);
	for(int i=0;i<n;i++)
	{
		if(num[i]!=temp[i])
		{
			f++;
		}
		if(f==3) 
		{
			ff=0;
			break;
		}
	}
	if(ff) printf("YES\n");
	else printf("NO\n");
	return 0;
}
