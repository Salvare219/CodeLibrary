#include <bits/stdc++.h>
using namespace std;


int a[100050];
int main()
{
    int n,t;scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",a+i);
        while(1)
        {
            int f=0;
            for(int i=0;i<n;i++)
                if(a[i]!=a[0])
                {
                    f=1;
                    break;
                }
            if(f==0)break;
            sort(a,a+n);
            int b=a[n-1]-a[0];
            a[n-1]=a[0]=b;
        }
        printf("%d\n",a[0]);
    }
    return 0;
}