#include <bits/stdc++.h>
using namespace std;


int a[100050];
int main()
{
    int ti=1,n;
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;i++)
            scanf("%d",a+i);
        int l=a[0],cnt=0;
        for(int i=1;i<n;i++)
        {
            l=__gcd(l,a[i]);
            cnt++;
            if(l==1)break;
        }
        printf("Case %d: ",ti++);
        if(l==1)
        {
            int l=a[0],z;
            printf("%d\n",cnt+n-1);
            for(int i=1;i<n;i++)
            {
                l=__gcd(l,a[i]);
                printf("%d %d\n",i,i+1);
                if(l==1)
                {
                    z=i+1;
                    break;
                }
            }
            for(int i=1;i<=n;i++)
                if(i!=z)
                    printf("%d %d\n",min(i,z),max(z,i));
        }
        else puts("-1");
        puts("");
    }
    return 0;
}