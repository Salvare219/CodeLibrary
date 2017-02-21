#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

int a[7000],tim;
struct p
{
    int a[25050],l[25050],r[25050],laz[25050];
    inline void creat(int i,int x,int y)
    {
        a[i]=0;l[i]=x;r[i]=y;laz[i]=0;
        if(x<y) creat(2*i+1,x,(x+y)/2),creat(2*i+2,(x+y)/2+1,y);
    }
    inline void updat(int i,int x,int y,int v)
    {
        if(l[i]==x && r[i]==y) laz[i]+=v,a[i]+=v;
        else
        {
            if(laz[i])
            {
                laz[2*i+1]+=laz[i];a[2*i+1]+=laz[i];
                laz[2*i+2]+=laz[i];a[2*i+2]+=laz[i];
                laz[i]=0;
            }
            if(x>(l[i]+r[i])/2) updat(2*i+2,x,y,v);
            else if(y<=(l[i]+r[i])/2) updat(2*i+1,x,y,v);
            else updat(2*i+1,x,(l[i]+r[i])/2,v),updat(2*i+2,(l[i]+r[i])/2+1,y,v);
            a[i]=max(a[2*i+2],a[2*i+1]);
        }
    }
}t1;
int sum[4000],pre[4000];
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int low=4000,up=-4000;
        for(int i=0;i<n;i++)
            scanf("%d",a+i),low=min(a[i],low),up=max(up,a[i]);
        for(int i=0;i<n;i++)
            if(a[i]>0&&a[i]<=n)pre[i+1]=pre[i]+1;
            else pre[i+1]=pre[i];
        for(int i=0;i<n;i++)
            a[i]-=low-1,sum[i]=0;up-=low-1;
        t1.creat(0,0,up);
        for(int i=0;i<n;i++)
        {
            memset(t1.a,0,sizeof(t1.a));
            memset(t1.laz,0,sizeof(t1.laz));
            for(int j=i;j>-1;j--)
            {
                t1.updat(0,a[j],min(a[j]+n-1,up),1);
                sum[i]=max(pre[j]+t1.a[0],sum[i]);
            }
        }
        int ans=0;
        memset(t1.a,0,sizeof(t1.a));
        memset(t1.laz,0,sizeof(t1.laz));
        for(int i=n-1;i>0;i--)
        {
            t1.updat(0,a[i],min(a[i]+n-1,up),1);
            ans=max(sum[i-1]+t1.a[0],ans);
        }
        printf("%d\n",ans);
    }
    return 0;
}