#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

const int sd=300007;
struct Hash_map
{
    int head[sd],st[sd],next[sd],sz;
    long long val[sd];
    void init()
    {
        memset(head,0xff,sizeof(head));sz=0;
    }
    int insert(long long t,int s)
    {
        int f=s%sd;
        for(int i=head[f];~i;i=next[i])
            if(st[i]==s)
                return val[i]+=t;
        st[sz]=s;val[sz]=t;
        next[sz]=head[f];head[f]=sz++;
        return t;
    }
}dp[2];
int cg(int s,int l,int f)
{
    int z=(f&1)?2:-2,cnt=0;
    s^=(f|f<<2)<<l;
    while(cnt>=0)
    {
        l+=z;
        if((s>>l&3^f)==3)cnt--;
        if((s>>l&3^f)==0)cnt++;
    }
    return s^3<<l;
}
int a[13][13];
int main()
{
    int t,ti=1;scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                scanf("%d",&a[i][j]);
        int f=0,lim=1<<(m<<1);
        dp[0].init();
        dp[0].insert(1,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                dp[f^=1].init();
                int s,h,l=j<<1;
                int x=3<<l,y=12<<l;
                long long v;
                for(int z=0;z<dp[f^1].sz;z++)
                {
                    s=dp[f^1].st[z];v=dp[f^1].val[z];
                    h=(x&s)^((y&s)>>2);h|=h<<2;
                    if(a[i][j]==0)!(x&s|y&s)?dp[f].insert(v,s):0;
                    else if(!(x&s|y&s))dp[f].insert(v,s&~(9<<l)|(9<<l));
                    else if(!(h>>l&3))dp[f].insert(v,cg(s,l,(x&s)>>l));
                    else if((h>>l&3)<3)dp[f].insert(v,s^h),dp[f].insert(v,s);
                    else dp[f].insert(v,s&~(15<<l));
                }
            }
            dp[f^1].init();
            for(int j=0;j<dp[f].sz;j++)
                if(dp[f].st[j]<lim)dp[f^1].insert(dp[f].val[j],dp[f].st[j]<<2);
            f^=1;
        }
        long long ans=0;
        for(int i=0;i<dp[f].sz;i++)
            if(dp[f].st[i]==0)
                ans=dp[f].val[i];
        printf("Case %d: There are %I64d ways to eat the trees.\n",ti++,ans);
    }
    return 0;
}
