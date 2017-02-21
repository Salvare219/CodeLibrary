#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


int n;
int a[505];
bool check()
{
    for(int i=0;i<n;i++)
        if(a[i]!=1)
            return 1;
    return 0;
}
int ans[5000005];
int main()
{
    freopen("table.in","r",stdin);
    freopen("table.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<n;i++)
        a[i]=0;
    a[0]=n;
    if(n%2==0)
    {
        puts("IMPOSSIBLE");
    }
    else
    {
        int k=0;
        while(check())
        {
            int f=0,z=0;
            for(int i=0;i<n;i++)
                if(a[i]>f)
                {
                    f=a[i];
                    z=i;
                }
            ans[k++]=z+1;
            a[z]-=2;
            a[(z+1)%n]++;
            a[(z-1+n)%n]++;
        }
        for(int i=0;i<k;i++)
            printf("%d%c",ans[i],i==k-1?10:' ');
    }
    return 0;
}
