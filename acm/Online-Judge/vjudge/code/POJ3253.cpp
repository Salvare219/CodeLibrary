#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

long long a[20050];
bool cmp(long long a,long long b){return a>b;}
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;i++)
            scanf("%I64d",a+i),push_heap(a,a+i+1,cmp);
        long long ans=0,b;
        for(int i=n;i>1;i--)
        {
            b=a[0];pop_heap(a,a+i,cmp);
            b+=a[0];pop_heap(a,a+i-1,cmp);
            ans+=a[i-2]=b;push_heap(a,a+i-1,cmp);
        }
        printf("%I64d\n",ans);
    }
    return 0;
}