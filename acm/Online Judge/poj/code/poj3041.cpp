#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

vector<int>gra[505];
int nn,mm;
bool use[505];
int phx[505],phy[505],p[505];
int q[1005];
bool relable()
{
    for(int i=1;i<=nn;i++)phx[i]=0;
    for(int i=1;i<=mm;i++)phy[i]=0;
    int tail=0,front=0,s,y;
    bool f=0;
    for(int i=1;i<=nn;i++)
        if(!use[i])q[tail++]=i;
    while(tail!=front)
    {
        s=q[front++];
        for(int i=0;i<gra[s].size();i++)
            if(!phy[y=gra[s][i]])
            {
                phy[y]=phx[s]+1;
                if(!p[y])f=1;
                else phx[p[y]]=phy[y]+1,q[tail++]=p[y];
            }
    }
    return f;
}
bool find(int s)
{
    int y;
    for(int i=0;i<gra[s].size();i++)
        if(phy[y=gra[s][i]]==phx[s]+1)
        {
            phy[y]=0;
            if(!p[y]||find(p[y]))return p[y]=s,1;
        }
    return 0;
}
int Hopcroft_Karp()
{
    int ans=0;
    memset(use,0,sizeof(use));
    memset(p,0,sizeof(p));
    while(relable())
        for(int i=1;i<=nn;i++)
            if(!use[i]&&find(i))use[i]=1,ans++;
    return ans;
}
int main()
{
    int n,k,x,y;
    scanf("%d%d",&n,&k);
    nn=mm=n;
    for(int i=0;i<k;i++)
        scanf("%d%d",&x,&y),gra[x].push_back(y);
    printf("%d\n",Hopcroft_Karp());
    return 0;
}