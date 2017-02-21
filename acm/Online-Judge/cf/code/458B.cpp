#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

#include<iostream>
int a[200000];
int b[200000];
int main()
{
    //freopen("2.txt","r",stdin);
    int n,m;scanf("%d%d",&n,&m);
    unsigned long long sum1=0,sum2=0;
    for(int i=0;i<n;i++)
        scanf("%d",a+i),sum1+=a[i];
    for(int i=0;i<m;i++)
        scanf("%d",b+i),sum2+=b[i];
    sort(a,a+n);sort(b,b+m);
    unsigned long long ans=-1,te;
    unsigned long long s=0;
    for(int i=n-1;i>-1;i--)
    {
        s+=a[i];
        te=sum1-s+(n-i)*sum2;
        ans=min(ans,te);
    }
    s=0;
    for(int i=m-1;i>-1;i--)
    {
        s+=b[i];
        te=sum2-s+(m-i)*sum1;
        ans=min(ans,te);
    }
    cout<<ans<<endl;
    return 0;
}

