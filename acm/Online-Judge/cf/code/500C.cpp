#include <bits/stdc++.h>
using namespace std;


int w[5000];
int a[5000];
int b[5000];
int c[5000];
int v[5000];
int main()
{
    //freopen("1.txt","r",stdin);
    int n,m;scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",w+i);
    int p=0;
    for(int i=0;i<m;i++)
    {
        scanf("%d",a+i);
        if(v[a[i]]==0)
        {
            v[a[i]]=1;
            b[p++]=a[i];
        }
    }
    long long ans=0;
    for(int i=0;i<m;i++)
    {
        int f=0;
        long long sum=0;
        for(int j=0;j<n;j++)
            if(b[j]==a[i])
                break;
            else
                sum+=w[b[j]];
        ans+=sum;
        int p=1;
        c[0]=a[i];
        for(int j=0;j<n;j++)
            if(b[j]!=a[i])
            {
                c[p++]=b[j];
            }
        for(int j=0;j<n;j++)
            b[j]=c[j];
    }
    printf("%I64d\n",ans);
    return 0;
}
