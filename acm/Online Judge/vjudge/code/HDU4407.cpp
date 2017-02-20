#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;


#include<map>
map<int,int>mp;
long long sum[400050];
int f[55],s;
long long dfs(int m,int n,int x)
{
    if(n<=x)
    {
        long long ans=1ll*(x/n)*(n+x/n*n)/2;
        for(int i=m;i<s;i++)
            ans-=dfs(i+1,n*f[i],x);
        return ans;
    }
    else return 0;
}
int gcd(int a,int b)
{
    while(a&&b)a>b?a%=b:b%=a;
    return a+b;
}
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        int n,m;mp.clear();
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++)
        {
            int ty,x,y,z;scanf("%d",&ty);
            if(ty==1)
            {
                scanf("%d%d%d",&x,&y,&z);
                int h=z;s=0;
                for(int i=2;i*i<=h;i++)
                    if(h%i==0)
                    {
                        f[s++]=i;
                        do h/=i;
                        while(h%i==0);
                    }
                if(h!=1)f[s++]=h;
                long long ans=dfs(0,1,y)-dfs(0,1,x-1);
                for(map<int,int>::iterator j=mp.begin();j!=mp.end();j++)
                {
                    int a=j->first,b=j->second;
                    if(a>=x&&a<=y)
                    {
                        if(gcd(z,a)==1)
                            ans-=a;
                        if(gcd(z,b)==1)
                            ans+=b;
                    }
                }
                printf("%I64d\n",ans);
            }
            else
            {
                scanf("%d%d",&x,&y);
                mp[x]=y;
            }
        }
    }
    return 0;
}
