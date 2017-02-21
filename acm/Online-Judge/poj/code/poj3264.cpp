#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;



int num[50005],n,q;
int dpmax[50005][30],dpmin[50005][30];
void rmq_max()
{
	for(int i=0;i<n;i++)
		dpmax[i][0]=num[i];
	int len=1,s=1;
	while(len<=n)
	{
		len*=2;
		for(int j=0;j<n;j++)
		{
			if(j+len>n) break;
			dpmax[j][s]=max(dpmax[j][s-1],dpmax[j+len/2][s-1]);
		}
		s++;
	}
}
void rmq_min()
{
	for(int i=0;i<n;i++)
		dpmin[i][0]=num[i];
	int len=1,s=1;
	while(len<=n)
	{
		len*=2;
		for(int j=0;j<n;j++)
		{
			if(j+len>n) break;
			dpmin[j][s]=min(dpmin[j][s-1],dpmin[j+len/2][s-1]);
		}
		s++;
	}
}
int main()
{
//	freopen("1.txt","r",stdin);
	while(scanf("%d%d",&n,&q)==2)
	{
		for(int i=0;i<n;i++)
			scanf("%d",num+i);
		rmq_max();
		rmq_min();
		int l,r,mid,len;
		for(int i=0;i<q;i++)
		{
			scanf("%d%d",&l,&r);
			l--;r--;
			mid=log(r-l+1.0)/log(2.0);
			len=1<<mid;
			printf("%d\n",max(dpmax[l][mid],dpmax[r-len+1][mid])-min(dpmin[l][mid],dpmin[r-len+1][mid]));
		}
	}
	return 0;
}