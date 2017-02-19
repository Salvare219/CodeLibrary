#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


struct bit_tree
{
    int bit[100050],s;
    int ll[100050];
    inline void updat(int x,int v,int z)
    {
        while(x<100005)
        {
            if(bit[x]<v)
            {
                bit[x]=v;
                ll[x]=z;
            }
            x+=x&-x;
        }
    }
    inline pair<int,int> query(int x)
    {
        s=0;
        int z=-1;
        while(x)
        {
            if(s<bit[x])
            {
                s=bit[x];
                z=ll[x];
            }
            x-=x&-x;
        }
        return make_pair(s,z);
    }
}b1;
struct bit_tree2
{
    int bit[100050],s;
    int ll[100050];
    inline void updat(int x,int v,int z)
    {
        while(x)
        {
            if(bit[x]<v)
            {
                bit[x]=v;
                ll[x]=z;
            }
            x-=x&-x;
        }
    }
    inline pair<int,int> query(int x)
    {
        s=0;
        int z=-1;
        while(x<100005)
        {
            if(s<bit[x])
            {
                s=bit[x];
                z=ll[x];
            }
            x+=x&-x;
        }
        return make_pair(s,z);
    }
}b2;
int a[100050];
long long sa[100050];
int pre[100050];
int las[100050];
int main()
{
    freopen("financial.in","r",stdin);
    freopen("financial.out","w",stdout);
    int n,p;scanf("%d%d",&n,&p);
    for(int i=0;i<n;i++)
    {
        scanf("%d",a+i);
        sa[i]=a[i];
    }
    sort(sa,sa+n);
    int k=unique(sa,sa+n)-sa;
    int f=0,ans=0;
    memset(pre,-1,sizeof(pre));
    memset(b1.ll,-1,sizeof(b1.ll));
    memset(b2.ll,-1,sizeof(b2.ll));
    for(int i=0;i<n;i++)
    {
        long long ff=a[i]-p;
        long long yy=a[i]+p;
        //printf("%d\n",*upper_bound(sa,sa+k,ff));
        int l=upper_bound(sa,sa+k,ff)-sa-1,r=lower_bound(sa,sa+k,yy)-sa;
        pair<int,int> fa=b1.query(l+1);
        pair<int,int> fb=b2.query(r+1);
        int c=0;
        if(fa.first>fb.first)
        {
            pre[i]=fa.second;
            c=fa.first+1;
        }
        else
        {
            pre[i]=fb.second;
            c=fb.first+1;
        }
        if(c>ans)
        {
            ans=c;
            f=i;
        }
        int lp=lower_bound(sa,sa+k,a[i])-sa;
        b1.updat(lp+1,c,i);
        b2.updat(lp+1,c,i);
    }
    printf("%d\n",ans);
    int now=f,o=0;
    while(now!=-1)
    {
        las[o++]=now;
        now=pre[now];
    }
    for(int i=0;i<o;i++)
        printf("%d%c",a[las[o-i-1]],i==o-1?10:' ');
    return 0;
}
