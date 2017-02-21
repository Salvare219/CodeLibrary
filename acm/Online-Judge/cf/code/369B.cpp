#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

int ans[10000];
int main()
{
//    freopen("1.txt","r",stdin);
    int n,k,l,r,sa,sk;
    scanf("%d%d%d%d%d%d",&n,&k,&l,&r,&sa,&sk);
    if(k)
    {
        int a=sk/k,b=sk%k;
        for(int i=0;i<b;i++)
            ans[i]=a+1;
        for(int i=b;i<k;i++)
            ans[i]=a;
    }
    if(k!=n)
    {
        sa-=sk;int kk=k;k=n-k;
        int c=sa/k,d=sa%k;
        for(int i=0;i<d;i++)
            ans[i+kk]=c+1;
        for(int i=d;i<k;i++)
            ans[i+kk]=c;
    }
    for(int i=0;i<n;i++)
        printf("%d ",ans[i]);putchar(10);
    return 0;
}