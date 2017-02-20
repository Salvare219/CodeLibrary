#include<cstdio>
#include<cstring>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;
#define INF 0x7fffffff


struct t
{
	long long l,r,data;
}tree[262144*5];
void filltree(int i,long long lef,long long rig)
{
	tree[i].l=lef;
	tree[i].r=rig;
	if(lef!=rig) 
	{
		tree[i].data=0;
		filltree(2*i+1,lef,(rig+lef)/2);
		filltree(2*i+2,(rig+lef)/2+1,rig);
	}
	else tree[i].data=0;
}
long long find(int i,long long temp)
{
	if(tree[i].l==tree[i].r) return tree[i].l;
	else
	{
		int ans;
		int mid=(tree[i].l+tree[i].r)/2;
		if(mid>=temp+tree[i].data) 
		{
			ans=find(2*i+1,temp);
			tree[i].data++;
		}
		else
		{
			ans=find(2*i+2,temp+tree[i].data);
		}
		return ans;
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		printf("Case %d: ",i+1);
		int n,k,temp;
		scanf("%d%d",&n,&k);
		filltree(0,1,n);
		long long sum=0;
		for(int i=0;i<k;i++)
		{
			scanf("%d",&temp);
			sum=sum+find(0,temp);
		}
		printf("%I64d\n",sum);
	}
    return 0;
}
