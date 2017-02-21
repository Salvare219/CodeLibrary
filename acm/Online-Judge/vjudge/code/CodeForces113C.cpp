#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


#include<bitset>
bitset<300000004>vis;
int prim[17000002],k;
void cal()
{
	for(int i=2;i<300000002;i++)
	{
		if(vis[i]==0) prim[k++]=i;
		for(int j=0;j<k && prim[j]*i<300000002;j++)
		{
			vis[prim[j]*i]=1;
			if(i%prim[j]==0) break;
		}
	}
}
int main()
{
    cal();
    int n,m,ans=0;scanf("%d%d",&n,&m);
    int l=lower_bound(prim,prim+k,n)-prim,r=upper_bound(prim,prim+k,m)-prim;
    for(int i=l;i<r;i++)
    {
        if(prim[i]==2)ans++;
        if(prim[i]%4==1)ans++;
    }
    printf("%d\n",ans);
	return 0;
}