#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int in[6];
#include<map>
map<int,double>mp;
map<int,bool>inq;
int q[3500000];
double ans[6];
int main()
{
    int n,k;
    while(~scanf("%d%d",&n,&k))
    {
        int x,ex=0;int z=k;
        int sta=0,bas=1;inq.clear();
        for(int i=0;i<n;i++)
        {
            scanf("%d",&x);
            k-=x;in[i]=x;ex+=x;
            sta+=x*bas;bas<<=6;
        }
        int front=0,tail=0;
        q[tail++]=sta;mp[sta]=1.0;
        for(int i=0;i<n;i++)ans[i]=0.0;
        for(int i=0;i<k;i++)
        {
            int st=tail,m1,m2,m3;
            bool f;
            while(front<st)
            {
                f=0;bas=1;m1=m2=0;m3=100;
                sta=q[front];
                memset(in,0,sizeof(in));
                for(int j=0;j<n;j++)in[j]=sta&63,sta>>=6;
                for(int j=0;j<n;j++)
                {
                    if(in[j]>m1)m2=m1,m1=in[j];
                    else if(in[j]>m2)m2=in[j];
                    m3=min(m3,in[j]);
                }
                sta=q[front++];
                if(m1>(z-ex)+m2)
                {
                    for(int j=0;j<n;j++)
                        if(m1==in[j])
                        {
                            ans[j]+=mp[sta];
                        }
                }
                else if(m1==m3)
                {
                    for(int j=0;j<n;j++)
                        ans[j]+=mp[sta]/n;
                }
                else
                {
                    for(int j=0;j<n;j++)
                    {
                        if(inq[sta+bas]==0)
                        {
                            inq[sta+bas]=1;q[tail++]=sta+bas;
                            if(ex>0)mp[sta+bas]=mp[sta]*in[j]/ex;
                            else mp[sta+bas]=mp[sta]/n;
                        }
                        else
                        {
                            if(ex>0)mp[sta+bas]+=mp[sta]*in[j]/ex;
                            else mp[sta+bas]+=mp[sta]/n;
                        }
                        bas<<=6;
                    }
                }
            }
            ex++;
        }
        while(front<tail)
        {
            sta=q[front];
            ex=0;bas=1;
            int cnt=0;
            for(int j=0;j<n;j++)in[j]=sta&63,ex=max(ex,in[j]),sta>>=6;
            sta=q[front++];
            for(int j=0;j<n;j++)if(ex==in[j])cnt++;
            for(int j=0;j<n;j++)
                if(ex==in[j])ans[j]+=mp[sta]/cnt;
        }
        for(int i=0;i<n;i++)
            printf("pub %d: %.2f %%\n",i+1,ans[i]*100);
    }
    return 0;
}
