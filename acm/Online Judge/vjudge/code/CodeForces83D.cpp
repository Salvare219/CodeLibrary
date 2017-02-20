#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int prim[100050],inv[100050],kf;
bool vis[100050];
void cal()
{
	for(int i=2;i<100005;i++)
	{
		if(vis[i]==0) inv[i]=kf,prim[kf++]=i;
		for(int j=0;j<kf&&prim[j]*i<100005;j++)
		{
			vis[prim[j]*i]=1;
			if(i%prim[j]==0) break;
		}
	}
}
long long a,b,k;
int how;
long long dfs(int lim,int s,long long tot)
{
    long long ans=0,hh=1;
    while(s<how&&tot*prim[s]<=lim)
    {
        ans+=lim/(tot*prim[s])-dfs(lim,s+1,tot*prim[s]);
        s++;
    }
    return ans;
}
int main()
{
    cal();
    scanf("%I64d%I64d%I64d",&a,&b,&k);
    bool f=1;
    for(int i=2;i*i<=k&&f;i++)
        if(k%i==0)f=0;
    if(f)
    {
        if(k*k<=b)
        {
            how=inv[k];
            b/=k;a=(a+k-1)/k;
            int tc=dfs(b,0,1),tcc=dfs(a-1,0,1);
            tc=b-tc;tcc=a-1-tcc;
            printf("%d\n",tc-tcc);
        }
        else
        {
            if(a<=k&&k<=b)puts("1");
            else puts("0");
        }
    }
    else puts("0");
    return 0;
}
