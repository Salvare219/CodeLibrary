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


int px[2001],py[2001];
int pos[2001];
int root[2001];
int n;
int fin(int p)
{
	return (root[p]==p)?p:root[p]=fin(root[p]);
}
int main()
{
//	freopen("1.txt","r",stdin);
	scanf("%d",&n);
	int x,y;
	memset(px,-1,sizeof(px));
	memset(py,-1,sizeof(py));
	for(int i=0;i<n;i++)
		root[i]=i;
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		pos[i]=x*10000+y;
		if(px[x]==-1) px[x]=i;
		else 
		{
			root[i]=fin(px[x]);
		}
		if(py[y]==-1) py[y]=i;
		else 
		{
			int a=fin(py[y]);
			root[a]=root[i];
		}
	}
	int k=0;
	for(int i=0;i<n;i++)
		if(root[i]==i) k++;
	printf("%d\n",k-1);
    return 0;
}