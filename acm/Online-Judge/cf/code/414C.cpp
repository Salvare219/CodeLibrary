#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int a[1<<21];
bool v[30];
long long add[30];
long long how[30],te[30];
int bit[1<<21];
int n;
int query(int x)
{
    int s=0;
    while(x)s+=bit[x],x-=x&-x;
    return s;
}
void updat(int x,int v)
{
    while(x<n+5)bit[x]+=v,x+=x&-x;
}
void cal(int d,int l,int r)
{
    if(l==r)
    {
        how[d]=0;
    }
    else
    {
        int mid=((r-l+1)>>1)+l-1;
        cal(d-1,l,mid);cal(d-1,mid+1,r);
        for(int i=mid+1;i<=r;i++)
            updat(a[i],1);
        for(int i=l;i<=mid;i++)
            how[d]+=query(a[i]-1);
        for(int i=mid+1;i<=r;i++)
            updat(a[i],-1);

        for(int i=l;i<=mid;i++)
            updat(a[i],1);
        for(int i=mid+1;i<=r;i++)
            te[d]+=query(a[i]-1);
        for(int i=l;i<=mid;i++)
            updat(a[i],-1);

        add[d]=how[d]+te[d];
    }
}
#include<map>
map<int,int>mp;
int pp[1<<21];
int main()
{
 //   freopen("1.txt","r",stdin);
    int nn,m,x;
    scanf("%d",&nn);
    n=1<<nn;
    for(int i=1;i<=n;i++)
        scanf("%d",a+i),pp[i-1]=a[i];
    sort(pp,pp+n);
    int sb=unique(pp,pp+n)-pp;
    for(int i=0;i<sb;i++)
        mp[pp[i]]=i+1;
    for(int i=1;i<=n;i++)
        a[i]=mp[a[i]];
    cal(nn,1,n);
    long long sum=0;
    scanf("%d",&m);
    for(int i=nn;i>=0;i--)
        sum+=how[i];
    while(m--)
    {
        scanf("%d",&x);
        if(x==0)printf("%I64d\n",sum);
        else
        {
            sum=0;
            for(int i=x;i>=0;i--)
                how[i]=add[i]-how[i];
            for(int i=0;i<=nn;i++)
                sum+=how[i];
            printf("%I64d\n",sum);
        }
    }
    return 0;
}
