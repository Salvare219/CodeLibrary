#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<queue>
using namespace std;

struct p
{
    int x,y;
}ar[2005];
vector<int> gra[2005];
bool vis[2005];
int stack[2005],k;
int low[2005],scc[2005];
int timer,cnt;
void tarjan_scc(int s)
{
    vis[s]=1;
    int temp=low[s]=++timer;
    stack[k++]=s;
    int to;
    for(int i=0;i<gra[s].size();i++)
    {
        to=gra[s][i];
        if(vis[to]==0) tarjan_scc(to);
        low[s]=min(low[to],low[s]);
    }
    if(temp==low[s])
    {
        do
        {
            to=stack[--k];
            vis[to]=0;
            scc[to]=cnt;
        }while(stack[k]!=s);
        cnt++;
    }
}
int main()
{
    int n,x,x1,y,y1,c;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d:%d%d:%d%d",&x,&x1,&y,&y1,&c);
        x=x*60+x1;y=y*60+y1;
        ar[i].x=x;ar[i].y=x+c;
        ar[i+n].x=y-c;ar[i+n].y=y;
    }
    for(int i=0;i<2*n;i++)
        for(int j=i+1;j<2*n;j++)
        {
            if(ar[i].y<=ar[j].x) continue;
            else if(ar[i].x>=ar[j].y) continue;
            else
            {
                x=(i+n>=2*n)?i-n:i+n;
                y=(j+n>=2*n)?j-n:j+n;
                gra[i].push_back(y);
                gra[j].push_back(x);
            }
        }
    cnt=1;timer=0;
    bool flag=1;
    for(int i=0;i<n;i++)
    {
        if(scc[i]==0 && scc[i+n]==0) tarjan_scc(i);
        if(scc[i]==scc[i+n])
        {
            flag=0;
            break;
        }
    }
    if(flag)
    {
        printf("YES\n");
        for(int i=0;i<n;i++)
        {
            if(scc[i] && scc[i+n])
            {
                if(scc[i+n]>scc[i]) x=ar[i].x,y=ar[i].y;
                else x=ar[i+n].x,y=ar[i+n].y;
            }
            else
            {
                if(scc[i+n]) x=ar[i+n].x,y=ar[i+n].y;
                if(scc[i]) x=ar[i].x,y=ar[i].y;
            }
            printf("%02d:%02d %02d:%02d\n",x/60,x%60,y/60,y%60);
        }
    }
    else printf("NO\n");
    return 0;
}
