#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


int a[100050];
int n;
bool ok(long long mid)
{
    long long sum=0;
    for(int i=0;i<n;i++)
        sum+=mid-a[i];
    if(sum>=mid) return 1;
    else return 0;
}
int main()
{
 //   freopen("1.txt","r",stdin);
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",a+i);
    sort(a,a+n);
    long long mid,l=a[n-1],r=2*a[n-1];
    while(l<r)
    {
        mid=(l+r)/2;
        if(ok(mid)) r=mid;
        else l=mid+1;
    }
    printf("%I64d\n",r);
    return 0;
}
