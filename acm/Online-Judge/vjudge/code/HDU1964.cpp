#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


const int sd=30007;
struct Hash_map
{
    int head[sd],st[sd],next[sd],sz;
    int val[sd];
    void init()
    {
        memset(head,0xff,sizeof(head));sz=0;
    }
    int insert(int t,int s)
    {
        int f=s%sd;
        for(int i=head[f];~i;i=next[i])
            if(st[i]==s)
                return val[i]=min(t,val[i]);
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
int le[13][13],dw[13][13];
char s[30];
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        int n,m;scanf("%d%d",&n,&m);
        getchar();gets(s);
        for(int i=1;i<2*n;i++)
        {
            gets(s);
            for(int j=1+(i&1);j<2*m;j+=2)
                if(i&1)le[(i-1)/2][(j-1)/2]=s[j]-'0';
                else dw[(i-1)/2][(j-1)/2]=s[j]-'0';
        }
        gets(s);
        int f=0,lim=1<<(m<<1);
        dp[0].init();
        dp[0].insert(0,0);
        int ans=1<<20;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                dp[f^=1].init();
                int s,h,l=j<<1;
                int x=3<<l,y=12<<l;
                int v;
                for(int z=0;z<dp[f^1].sz;z++)
                {
                    s=dp[f^1].st[z];v=dp[f^1].val[z];
                    h=(x&s)^((y&s)>>2);h|=h<<2;
                    if(!(x&s|y&s))dp[f].insert(v+le[i][j]+dw[i][j],s&~(9<<l)|(9<<l));
                    else if(!(h>>l&3))dp[f].insert(v,cg(s,l,(x&s)>>l));
                    else if((h>>l&3)<3)
                    {
                        if(((x&s)>>l&3)==0)dp[f].insert(v+dw[i][j],s^h),dp[f].insert(v+le[i][j],s);
                        else dp[f].insert(v+le[i][j],s^h),dp[f].insert(v+dw[i][j],s);
                    }
                    else if(((x&s)>>l)==2)dp[f].insert(v,s&~(15<<l));
                    else if((s&~(15<<l))==0&&i==n-1&&j==m-1)ans=min(ans,v);
                }
            }
            dp[f^1].init();
            for(int j=0;j<dp[f].sz;j++)
                if(dp[f].st[j]<lim)dp[f^1].insert(dp[f].val[j],dp[f].st[j]<<2);
            f^=1;
        }
        printf("%d\n",ans);
    }
    return 0;
}
