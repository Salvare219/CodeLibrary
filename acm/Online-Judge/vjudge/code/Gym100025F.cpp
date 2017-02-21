#include <bits/stdc++.h>
using namespace std;


int sz(int n,int m)
{
    if(n==0||m==0)return 0;
    int l,t,l2,t2;
    l=(n-1)%m+1;
    t=max(0,n-m);
    l2=min(m,l-1);
    t2=max(0,m-l+1);
    return sz(l,l2)+2;
}
void pri(int n,int m,int cnt)
{
    if(n==0||m==0)return;
    int l,t,l2,t2;
    l=(n-1)%m+1;
    t=max(0,n-m);
    l2=min(m,l-1);
    t2=max(0,m-l+1);
    if(t==0)printf("0");
    else
    {
        for(int i=0;i<t;i++)
            if(i%m==0)printf("1");
            else printf("0");
    }
    putchar(32);
    if(t2==0)printf("0");
    else
    {
        for(int i=0;i<t2;i++)
            printf("9");
    }
    if(cnt)putchar(32);
    pri(l,l2,cnt-2);
}
int main()
{
    //freopen("1.txt","r",stdin);
    freopen("continued.in","r",stdin);
    freopen("continued.out","w",stdout);
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        int f;
        printf("%d\n",f=sz(n+1,m)-1);
        pri(n+1,m,f);puts("");
    }
    return 0;
}
