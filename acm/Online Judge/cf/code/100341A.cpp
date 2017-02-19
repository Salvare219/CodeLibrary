#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
using namespace std;


int nn,mm;
bool visx[505],visy[505];
int pre[505],gra[505][505];
int lx[505],ly[505],slack[505];
bool find(int s)
{
    visx[s]=1;
    for(int i=1;i<=mm;i++)
        if(visy[i]==0)
        {
            int f=lx[s]+ly[i]-gra[s][i];
            if(f==0)
            {
                visy[i]=1;
                if(pre[i]==0 || find(pre[i]))
                {
                    pre[i]=s;
                    return 1;
                }
            }
            else slack[i]=min(slack[i],f);
        }
    return 0;
}
int Kuhn_Munkras()
{
    int i,j,d,ans=0;
    memset(ly,0,sizeof(ly));
    memset(pre,0,sizeof(pre));
    for(i=1;i<=nn;i++)
        for(j=1,lx[i]=-0x7fffffff;j<=mm;j++)
            lx[i]=max(lx[i],gra[i][j]);
    for(i=1;i<=nn;i++)
    {
        memset(slack,0x7f,sizeof(slack));
        while(1)
        {
            memset(visx,0,sizeof(visx));
            memset(visy,0,sizeof(visy));
            if(find(i))break;
            d=0x7fffffff;
            for(j=1;j<=mm;j++)
                if(visy[j]==0) d=min(d,slack[j]);
            for(j=1;j<=nn;j++)
                if(visx[j]) lx[j]-=d;
            for(j=1;j<=mm;j++)
                if(visy[j]) ly[j]+=d;
                else slack[j]-=d;
        }
    }
    for(i=1;i<=mm;i++)
        if(pre[i]) ans+=gra[pre[i]][i];
    return ans;
}
int p[500];
int n,m,k,s;
int sf[30][30];
void built(int s)
{
    int x=p[s]/100,y=p[s]%100;
    for(int z=1;z<=n+m;z++)
    {
        int cnt=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(abs(x-i)+abs(y-j)==z)
                {
                    if(sf[i][j]!=-1)
                    {
                        gra[s+1][sf[i][j]]=-z*1000-cnt;
                        cnt++;
                    }
                }
    }
}
vector<int>pl[500];
int deg[500];
void link(int s)
{
    int x=p[s]/100,y=p[s]%100;
    for(int z=1;z<=n+m;z++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(abs(x-i)+abs(y-j)==z)
                {
                    if(sf[i][j]!=-1)
                    {
                        if(pre[sf[i][j]]==0||pre[sf[i][j]]-1==s)
                            return ;
                        else
                        {
                            pl[pre[sf[i][j]]-1].push_back(s);
                            deg[s]++;
                            //printf("****%d %d\n",s,pre[sf[i][j]]-1);
                        }
                    }
                }
}
int ans[500];
int main()
{
    freopen("agrarian.in","r",stdin);
    freopen("agrarian.out","w",stdout);
    //freopen("1.txt","r",stdin);
    //freopen("2.txt","w",stdout);
    scanf("%d%d%d%d",&n,&m,&k,&s);
    int x,y;
    for(int i=0;i<k;i++)
    {
        scanf("%d%d",&x,&y);
        p[i]=x*100+y;
        sf[x][y]=-1;
    }
    for(int i=0;i<s;i++)
    {
        scanf("%d%d",&x,&y);
        sf[x][y]=-1;
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(sf[i][j]==0)
                sf[i][j]=++cnt;
    for(int i=0;i<k;i++)
        built(i);
    nn=k;mm=cnt;
    Kuhn_Munkras();

    //for(int i=1;i<=cnt;i++)
    //    if(pre[i])
    //        printf("%d %d\n",pre[i],i);

    for(int i=0;i<k;i++)
        link(i);
    queue<int>q;
    for(int i=0;i<k;i++)
        if(deg[i]==0)
            q.push(i);
    cnt=0;
    while(!q.empty())
    {
        x=q.front();q.pop();
        ans[cnt++]=x;
        for(int i=0;i<pl[x].size();i++)
        {
            y=pl[x][i];
            deg[y]--;
            if(deg[y]==0)
                q.push(y);
        }
    }
    for(int i=0;i<cnt;i++)
        printf("%d%c",ans[i]+1,i==cnt-1?10:32);
    return 0;
}
