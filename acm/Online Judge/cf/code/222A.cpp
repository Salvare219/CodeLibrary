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


int num[100005];
int main()
{
//	freopen("1.txt","r",stdin);
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)
	{
		scanf("%d",num+i);
	}
	bool flag=0;
	for(int i=k;i<n;i++)
	{
		if(num[i]!=num[k-1]) 
		{
			flag=1;
			break;
		}
	}
	if(flag) printf("-1\n");
	else
	{
		int ff=0;
		for(int i=k-2;i>-1;i--)
		{
			if(num[i]!=num[k-1])
			{
				ff=i+1;
				break;
			}
		}
		printf("%d\n",ff);
	}
    return 0;
}