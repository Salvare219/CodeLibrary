#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


vector<pair<int,int> > gra[100050];
int dis[100050];
int n,m;
bool inq[100050];
#include<queue>
void spfa(int s)
{
    int x,y,w;
    queue<int> q;
    for(int i=1;i<=n;i++) dis[i]=0x3fffffff;
    q.push(s);dis[s]=0;
    while(!q.empty())
    {
        x=q.front();
        q.pop();inq[x]=0;
        for(int i=0;i<gra[x].size();i++)
        {
            y=gra[x][i].first;w=gra[x][i].second;
            if(dis[y]>dis[x]+w)
            {
                dis[y]=dis[x]+w;
                if(inq[y]) continue;
                inq[y]=1;q.push(y);
            }
        }
    }
}
int main()
{
//    freopen("1.txt","r",stdin);
    int s,x,y,w;
    scanf("%d%d%d",&n,&m,&s);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d",&x,&y,&w);
        gra[x].push_back(make_pair(y,w));
        gra[y].push_back(make_pair(x,w));
    }
    int d,c=0,f=0;
    scanf("%d",&d);
    if(d==0) printf("1\n");
    else
    {
        spfa(s);
        for(int i=1;i<=n;i++)
        {
            if(dis[i]==d) f++;
            for(int j=0;j<gra[i].size();j++)
            {
                x=i;
                y=gra[i][j].first;
                w=gra[i][j].second+dis[y]+dis[x];
                if(dis[x]<d && 2*d<w) c++;
                if(dis[y]<d && 2*d<w) c++;
                if(2*d==w && d!=dis[x] && d!=dis[y]) c++;
            }
        }
        printf("%d\n",f+c/2);
    }
    return 0;
}
