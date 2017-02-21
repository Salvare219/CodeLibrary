#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

int n,mod,ans;
int prim[30005],mi[40005],k;
vector<pair<int,int> >co;
inline void cal()
{
    for(int i=2;i<40001;i++)
    {
        if(mi[i]==0)prim[k++]=i;
        for(int j=0;j<k&&prim[j]*i<40001;j++)
        {
            mi[i*prim[j]]=prim[j];
            if(i%prim[j]==0)break;
        }
    }
}
inline int pow_mod(int a,int b)
{
    int c=1;a%=mod;
    while(b)
    {
        if(b&1)c=(c*a)%mod;
        b>>=1;a=(a*a)%mod;
    }
    return c;
}
inline void f(int s)
{
    int con;co.clear();
    for(int i=0;i<k&&prim[i]*prim[i]<=s;i++)
        if(n%prim[i]==0)
        {
            con=0;
            while(s%prim[i]==0)s/=prim[i],con++;
            co.push_back(make_pair(prim[i],con));
            if(s<40004&&mi[s]==0)break;
        }
    if(s!=1)co.push_back(make_pair(s,1));
}
inline int phi(int s)
{
	int ret=1;
	if(s==1)return 1;
	for(int i=0;i<k&&prim[i]*prim[i]<=s;i++)
		if(s%prim[i]==0)
		{
			s/=prim[i],ret*=prim[i]-1;
			while(s%prim[i]==0) s/=prim[i],ret*=prim[i];
			if(s<40004&&mi[s]==0)break;
		}
    if(s>1) ret*=s-1;
    return ret%mod;
}
inline void dfs(int s,int now)
{
    for(int i=0;i<=co[s].second;i++)
        if(1ll*now*now<n)
        {
            if(s!=co.size()-1)dfs(s+1,now);
            else ans=(ans+phi(now)*pow_mod(n,n/now-1)+phi(n/now)*pow_mod(n,now-1))%mod;
            now*=co[s].first;
        }
        else break;
}
int main()
{
    int t;cal();
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&mod);
        if(n==1) printf("%d\n",1%mod);
        else if(mod==1) puts("0");
        else
        {
            f(n);ans=0;dfs(0,1);
            int s=sqrt(n);
            if(s*s==n) ans+=phi(s)*pow_mod(n,s-1);s++;
            if(s*s==n) ans+=phi(s)*pow_mod(n,s-1);
            printf("%d\n",ans%mod);
        }
    }
    return 0;
}
