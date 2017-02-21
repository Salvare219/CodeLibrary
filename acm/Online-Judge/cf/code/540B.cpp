#include<bits/stdc++.h>
using namespace std;


int a[2000];
int main()
{
    //freopen("1.txt","r",stdin);
    int n,k,p,x,y,sum=0,z;scanf("%d%d%d%d%d",&n,&k,&p,&x,&y);
    for(int i=0;i<k;i++)
        scanf("%d",&z),sum+=z,a[i]=z;
    int r=n-k;
    if(sum+r>x)puts("-1");
    else
    {
        int f=-1,p=k;
        for(int i=0;i<=r;i++)
            if(i+(r-i)*y+sum<=x)
            {
                f=i;
                for(int j=0;j<i;j++)
                    a[p++]=1;
                for(int j=0;j<r-i;j++)
                    a[p++]=y;
                break;
            }
        sort(a,a+n);
        if(a[n/2]<y)puts("-1");
        else
        {
            for(int j=0;j<f;j++)
                printf("%d ",1);
            for(int j=0;j<r-f;j++)
                printf("%d ",y);
        }
    }
    return 0;
}

