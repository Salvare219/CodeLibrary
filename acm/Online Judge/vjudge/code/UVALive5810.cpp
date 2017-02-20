#include<bits/stdc++.h>
using namespace std;


int a[20],b[20];
int v[105];
bool c[1030][105];
int main()
{
    int n,ti=1;
    int lim=1<<10;
    for(int i=1;i<lim;i++)
    {
        int f=0;
        for(int j=9;j>-1;j--)
            if((1<<j)&i)
                b[f++]=j;
        for(int j=0;j<f;j++)
            for(int k=j+1;k<f;k++)
            {
                v[b[j]*10+b[k]]=(1<<j)|(1<<k);
                v[b[k]*10+b[j]]=(1<<j)|(1<<k);
            }
        for(int j=0;j<f;j++)
            v[b[j]]=1<<j;
        for(int j=1;j<=100;j++)
        {
            int g=1;
            if(v[j]==0)
            {
                g=0;
                for(int k=1;k<j;k++)
                    if(v[k]&&v[j-k]&&(v[k]&v[j-k])==0)
                    {
                        g=1;
                        break;
                    }
            }
            c[i][j]=g;
        }
        for(int j=0;j<f;j++)
        {
            v[b[j]]=0;
            for(int k=j+1;k<f;k++)
            {
                v[b[j]*10+b[k]]=0;
                v[b[k]*10+b[j]]=0;
            }
        }
    }
    while(scanf("%d",&n)&&n)
    {
        for(int i=0;i<n;i++)
            scanf("%d",a+i);
        int len=20;
        long long ans=0;
        for(int i=1;i<lim;i++)
        {
            long long now=0;
            int cnt=0;
            for(int j=9;j>-1;j--)
                if((1<<j)&i)
                    now=now*10+j,cnt++;
            int g=1;
            for(int j=0;j<n;j++)
                if(c[i][a[j]]==0)
                {
                    g=0;
                    break;
                }
            if(g)
            {
                if(cnt<len)
                    len=cnt,ans=now;
                else if(cnt==len)
                    ans=min(ans,now);
            }
        }
        printf("Case %d: %lld\n",ti++,ans);
    }
    return 0;
}
