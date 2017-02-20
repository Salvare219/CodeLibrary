#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

int n;
int bit[100005],bit1[100005],p[100005];
void updat(int x,int s)
{
    while(x<=n)bit[x]+=s,x+=x&-x;
}
void updat1(int x,int s)
{
    while(x<=n)bit1[x]=max(bit1[x],s),x+=x&-x;
}
int query(int x)
{
    int s=0;
    while(x)s+=bit[x],x-=x&-x;
    return s;
}
int query1(int x)
{
    int s=0;
    while(x)s=max(s,bit1[x]),x-=x&-x;
    return s;
}
int find(int x)
{
    int cnt=0,ans=0,p=1<<18;
    while(p>n)p>>=1;
    for(;p;p>>=1)
    {
        ans|=p;
        if(ans>n||cnt+bit[ans]>=x)ans^=p;
        else cnt+=bit[ans];
    }
    return ans+1;
}
int main()
{
    int t,ti=1;scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            bit1[i]=0,updat(i,1);
        for(int i=0;i<n;i++)
            scanf("%d",p+i),p[i]++;
        for(int i=n-1;i>-1;i--)
        {
            updat(p[i]=find(p[i]),-1);
        }
        printf("Case #%d:\n",ti++);
        int l=0,r;
        for(int i=0;i<n;i++)
            printf("%d\n",l=max(l,r=query1(p[i])+1)),updat1(p[i],r);
        putchar(10);
    }
    return 0;
}
