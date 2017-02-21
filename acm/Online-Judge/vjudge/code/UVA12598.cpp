#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int a[50050],sa[50050],n,k,q,x;
bool ok(int mid)
{
    int how=upper_bound(sa,sa+k,mid)-sa;
    return mid-how+k>=x;
}
int main()
{
    int t;scanf("%d",&t);
    int ti=1;
    while(t--)
    {
        printf("Case %d:\n",ti++);
        scanf("%d%d%d",&n,&k,&q);
        for(int i=0;i<k;i++)scanf("%d",a+i),sa[i]=a[i];
        sort(sa,sa+k);
        while(q--)
        {
            scanf("%d",&x);
            if(x<=k)printf("%d\n",a[x-1]);
            else
            {
                int l=1,r=n,mid;
                while(l<r)
                {
                    mid=(r+l)>>1;
                    if(ok(mid))r=mid;
                    else l=mid+1;
                }
                printf("%d\n",r);
            }
        }
    }
    return 0;
}
