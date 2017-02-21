#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

struct bit_tree
{
    int bit[100050],s;
    inline void updat(int x,int v)
    {
        while(x<100005) bit[x]=bit[x]+v,x+=x&-x;
    }
    inline int query(int x)
    {
        s=0;
        while(x) s=s+bit[x],x-=x&-x;
        return s;
    }
}bit[18];
bool pre[100005][18];
int num[100005];
int main()
{
    int n,m,x,y;scanf("%d%d",&n,&m);
    long long ans=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);num[i]=x;
        for(int j=0;j<18;j++)
            if((1<<j)&x)
                bit[j].updat(i,1),pre[i][j]=1;
    }
    long long cnt=0;
    for(int i=0;i<18;i++)
    {
        cnt=0;
        for(int j=1;j<=n;j++)
            if(pre[j][i])cnt++;
            else
            {
                ans+=(cnt+1)*cnt/2*(1<<i);
                cnt=0;
            }
        if(cnt)ans+=(cnt+1)*cnt/2*(1<<i);
    }
    while(m--)
    {
        scanf("%d%d",&x,&y);
        for(int j=0;j<18;j++)
        {
            int a=(1<<j)&num[x],b=(1<<j)&y;
            if(a^b)
            {
                if(a)
                {
                    int l=0,r=x,mid,p1,p2;
                    long long len;
                    int sb=bit[j].query(x);
                    while(l<r)
                    {
                        mid=(l+r)/2;
                        if(sb-bit[j].query(mid)==x-mid)r=mid;
                        else l=mid+1;
                    }
                    p1=r+1;
                    l=x;r=n+1;
                    while(l<r)
                    {
                        mid=(l+r+1)/2;
                        if(bit[j].query(mid)-sb==mid-x)l=mid;
                        else r=mid-1;
                    }
                    p2=l;
                    len=p2-p1+1;
                    ans-=len*(len+1)/2*(1<<j);
                    len=x-p1;
                    ans+=len*(len+1)/2*(1<<j);
                    len=p2-x;
                    ans+=len*(len+1)/2*(1<<j);
                    bit[j].updat(x,-1);
                }
                else
                {
                    int l=0,r=x-1,mid,p1,p2;
                    long long len;
                    int sb=bit[j].query(x-1);
                    if(x==1)p1=1;
                    else
                    {
                        if(sb-bit[j].query(x-2)==0)p1=x;
                        else
                        {
                            while(l<r)
                            {
                                mid=(l+r)/2;
                                if(sb-bit[j].query(mid)==x-1-mid)r=mid;
                                else l=mid+1;
                            }
                            p1=r+1;
                        }
                    }
                    l=x+1;r=n+1;
                    sb=bit[j].query(x+1);
                    if(sb-bit[j].query(x)==0)p2=x;
                    else
                    {
                        while(l<r)
                        {
                            mid=(l+r+1)/2;
                            if(bit[j].query(mid)-sb==mid-x-1)l=mid;
                            else r=mid-1;
                        }
                        p2=l;
                    }
                    len=x-p1;
                    ans-=len*(len+1)/2*(1<<j);
                    len=p2-x;
                    ans-=len*(len+1)/2*(1<<j);
                    len=p2-p1+1;
                    ans+=len*(len+1)/2*(1<<j);
                    bit[j].updat(x,1);
                }
            }
        }
        num[x]=y;
        printf("%I64d\n",ans);
    }
    return 0;
}
