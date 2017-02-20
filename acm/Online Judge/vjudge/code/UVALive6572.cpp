#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

vector<pair<int,double> > gra[205];
bool inque[205];
double now[205];
int pre[205],te[205];
int n,m;
#include<queue>
void spfa(int s,int t)
{
    int x,to;double w;
    queue<int> que;
    memset(inque,0,sizeof(inque));
    for(int i=0;i<n;i++) now[i]=1e9;
    que.push(s);now[s]=0.0;pre[s]=-1;
    while(!que.empty())
    {
        x=que.front();que.pop();
        inque[x]=0;
        for(int i=0;i<gra[x].size();i++)
        {
            to=gra[x][i].first;
            w=gra[x][i].second;
            if(now[to]>now[x]+w)
            {
                now[to]=now[x]+w;
                pre[to]=x;
                if(inque[to]) continue;
                inque[to]=1;
                que.push(to);
            }
        }
    }
    x=0;
    while(t!=-1)te[x++]=t,t=pre[t];
    for(int i=x-1;i>-1;i--)
        printf("%d%c",te[i],i?' ':10);
}
struct p
{
    double x,y,z;
}po[204];
inline double sq(double c){return c*c;}
inline double dis(int i,int j)
{
    return sqrt(sq(po[i].x-po[j].x)+sq(po[i].y-po[j].y)+sq(po[i].z-po[j].z));
}
int main()
{
    bool f=0;
    char tt[50];
    while(~scanf("%d%d",&n,&m))
    {
        if(f)putchar(10);
        f=1;int q,x,y;
        double w,w1;
        for(int i=0;i<n;i++)
            scanf("%lf%lf%lf",&po[i].z,&po[i].x,&po[i].y),po[i].z*=5,gra[i].clear();
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%s",&x,&y,tt);
            if(tt[0]=='w'||tt[0]=='s')w=w1=dis(x,y);
            else if(tt[0]=='l')w=w1=1.0;
            else w=1.0,w1=3.0*dis(x,y);
            gra[x].push_back(make_pair(y,w));
            gra[y].push_back(make_pair(x,w1));
        }
        scanf("%d",&q);
        while(q--)
            scanf("%d%d",&x,&y),spfa(x,y);
    }
    return 0;
}
