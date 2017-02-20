#include<bits/stdc++.h>
using namespace std;


char s[1005];
int sr[1005],sc[1005];
int solv(int s[],int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
        sum+=s[i];
    if(sum%n)return -1;
    else
    {
        int fin=1<<30;sum/=n;
        for(int i=0;i<n;i++)
        {
            int ans=0,now=0;
            for(int j=0;j<n;j++)
            {
                ans+=fabs(s[(i+j)%n]+now-sum);
                now+=s[(i+j)%n]-sum;
            }
            fin=min(fin,ans);
        }
        return fin;
    }
}
int main()
{
    int t,ti=1;scanf("%d",&t);
    while(t--)
    {
        int n,m;scanf("%d%d",&n,&m);
        memset(sr,0,sizeof(sr));
        memset(sc,0,sizeof(sc));
        for(int i=0;i<n;i++)
        {
            scanf("%s",s);
            for(int j=0;j<m;j++)
                if(s[j]=='1')sr[i]++,sc[j]++;
        }
        int ans1=solv(sr,n);
        int ans2=solv(sc,m);
        printf("Case %d: ",ti++);
        if(ans1==-1&&ans2==-1)puts("impossible");
        else if(ans1==-1)printf("column %d\n",ans2);
        else if(ans2==-1)printf("row %d\n",ans1);
        else printf("both %d\n",ans1+ans2);
    }
    return 0;
}
