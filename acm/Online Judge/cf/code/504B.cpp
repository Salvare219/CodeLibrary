#include <bits/stdc++.h>
using namespace std;


int bit[200050];
void updat(int x,int v)
{
    while(x<200005)bit[x]+=v,x+=x&-x;
}
int query(int x)
{
    int s=0;
    while(x)s+=bit[x],x-=x&-x;;
    return s;
}
int find(int x)
{
    int cnt=0,ans=0,p=1<<18;
    while(p)
    {
        ans|=p;
        if(ans>200005||cnt+bit[ans]>=x)ans^=p;
        else cnt+=bit[ans];p>>=1;
    }
    return ans+1;
}
int a[200050];
int ta[200050];
int tb[200050];
int tc[200050];
int main()
{
    //freopen("1.txt","r",stdin);
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",a+i);
    for(int i=n-1;i>-1;i--)
    {
        ta[i]=query(a[i]+1);
        updat(a[i]+1,1);
    }
    memset(bit,0,sizeof(bit));
    for(int i=0;i<n;i++)
        scanf("%d",a+i);
    for(int i=n-1;i>-1;i--)
    {
        tb[i]=query(a[i]+1);
        updat(a[i]+1,1);
    }
    int las=0;
    for(int i=n-1;i>-1;i--)
    {
        int c=ta[i]+tb[i]+las;
        las=c/(n-i);
        tc[i]=c%(n-i);
    }
    memset(bit,0,sizeof(bit));
    for(int i=1;i<=n;i++)
        updat(i,1);
    for(int i=0;i<n;i++)
    {
        a[i]=find(tc[i]+1)-1;
        printf("%d ",a[i]);
        updat(a[i]+1,-1);
    }
    putchar(10);
    return 0;
}
