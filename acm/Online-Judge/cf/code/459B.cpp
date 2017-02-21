#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


int a[500000];
int main()
{
    //freopen("1.txt","r",stdin);
    int n;scanf("%d",&n);
    long long mx=-0x3fffffff,mm=0x3fffffff;
    long long ca=0,cb=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",a+i);
        mx=max((long long)a[i],mx);
        mm=min((long long)a[i],mm);
    }
    for(int i=0;i<n;i++)
    {
        if(mm==a[i])cb++;
        if(mx==a[i])ca++;
    }
    long long ans;
    if(mx==mm)ans=ca*(ca-1)/2;
    else ans=ca*cb;
    printf("%I64d %I64d\n",mx-mm,ans);
    return 0;
}
