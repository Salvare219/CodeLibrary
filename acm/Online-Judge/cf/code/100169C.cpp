#include<bits/stdc++.h>
using namespace std;

int a[100005];

int main()
{
    int n,m,i,x;
    long long s;
    for(scanf("%d%d",&n,&m),i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    for(s=i=0;i<m;i++)
    {
        scanf("%d",&x);
        s+=*lower_bound(a,a+n,x)-x;
    }
    printf("%I64d\n",s);
    return 0;
}
