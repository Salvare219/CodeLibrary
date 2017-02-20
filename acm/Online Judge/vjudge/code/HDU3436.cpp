#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

int k,x[100005],bit[200005],a[100005];
char y[100005],f[9];
int query(int x)
{
    int s=0;
    while(x)s+=bit[x],x-=x&-x;
    return s;
}
void updat(int x,int s)
{
    while(x<=k)bit[x]+=s,x+=x&-x;
}
int find(int x)
{
    int cnt=0,ans=0;
    for(int i=18;i>=0;i--)
    {
        ans+=(1<<i);
        if(ans>k||cnt+bit[ans]>=x)ans-=(1<<i);
        else cnt+=bit[ans];
    }
    return ans+1;
}
#include<map>
map<int,int>mr,mp;
int main()
{
    int t,n,m,ti=1;scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&m,&n);
        int p=0,l=0,r,mid;
        for(int i=0;i<n;i++)
        {
            scanf("%s%d",f,x+i);y[i]=f[0];
            if(y[i]!='R')a[p++]=x[i];
        }
        a[p++]=m;sort(a,a+p);p=unique(a,a+p)-a;
        k=(n<<1)+5;r=n+1;
        mp.clear();mr.clear();
        for(int i=1;i<=k;i++)bit[i]=0;
        for(int i=0;i<p;i++)
            updat(mp[a[i]]=r,a[i]-l),mr[r++]=l=a[i];
        printf("Case %d:\n",ti++);p=n;
        for(int i=0;i<n;i++)
            if(y[i]=='T')
                mr[mp[x[i]]]--,mr[p]=x[i],updat(mp[x[i]],-1),updat(mp[x[i]]=p--,1);
            else if(y[i]=='Q')
                printf("%d\n",query(mp[x[i]]));
            else
                r=find(x[i]),printf("%d\n",mr[r]-query(r)+x[i]);
    }
    return 0;
}
