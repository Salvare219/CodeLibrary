#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b)
{
    return b?gcd(b,a%b):a;
}

inline long long cal(int l,int r,int c)
{
    return 1ll*(l/c+1)*(r/c+1);
}

long long cal2(int l,int r)
{
    if(l>r)swap(l,r);
    int k;
    long long sum=0;
    for(int i=1;i<=l;i=k+1)
    {
        k=min(l/(l/i),r/(r/i));
        sum+=1ll*(k-i+1)*(l/i+1)*(r/i+1);
    }
    for(int i=l+1;i<=r;i=k+1)
    {
        k=r/(r/i);
        sum+=1ll*(k-i+1)*(r/i+1);
    }
    return sum-r;
}

int a[100005];

int main()
{
    freopen("trees.in","r",stdin);
    freopen("trees.out","w",stdout);
    int n,m,i,g,l,r;
    long long ans=0;
    for(scanf("%d%d",&n,&m),i=0;i<m;i++)
        scanf("%d",a+i);
    l=a[0]-1;r=n-a[m-1];
    if(m==1)
    {
        printf("%I64d\n",cal2(l,r)+1);
        return 0;
    }
    g=a[1]-a[0];
    for(i=1;i<m;i++)
        g=gcd(g,a[i]-a[i-1]);
    for(i=1;i*i<g;i++)
        if(g%i==0)
            ans+=cal(l,r,i)+cal(l,r,g/i);
    if(i*i==g)
        ans+=cal(l,r,i);
    printf("%I64d\n",ans);
    return 0;
}
