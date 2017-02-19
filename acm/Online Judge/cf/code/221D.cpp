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


int num[100006],has[100006],time[100006],ans[500][100006];
int main()
{
//	freopen("1.txt","r",stdin);
	int n,q,k=0;
	scanf("%d%d",&n,&q);
	for(int i=0;i<n;i++)
	{
		scanf("%d",num+i);
		if(num[i]<=n) 
		{
			if(has[num[i]]==0) time[k++]=num[i];
			has[num[i]]++;
		}
	}
	int l=0;
	for(int i=0;i<k;i++)
	{
		if(has[time[i]]>=time[i])
		{
			time[l]=time[i];
			for(int j=0;j<n;j++)
			{
				if(num[j]==time[i]) ans[l][j]++;
				if(j>0) ans[l][j]+=ans[l][j-1];
			}
			l++;
		}
	}
	int x,y;
	for(int i=0;i<q;i++)
	{
		int oo=0;
		scanf("%d%d",&x,&y);
		x--;y--;
		for(int j=0;j<l;j++)
		{
			int p=(x==0)?0:ans[j][x-1];
			if(ans[j][y]-p==time[j]) oo++; 
		}
		printf("%d\n",oo);
	}
	return 0;
}