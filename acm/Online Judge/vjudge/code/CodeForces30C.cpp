#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

struct ps
{
    int x,y,t;
    double p;
    bool operator<(ps a)const{return t<a.t;}
}am[2000];
double dp[2000];
bool ok(int i,int j)
{
    return abs(am[i].t-am[j].t)>=sqrt((am[i].x-am[j].x)*(am[i].x-am[j].x)+(am[i].y-am[j].y)*(am[i].y-am[j].y));
}
int main()
{
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d%d%d%lf",&am[i].x,&am[i].y,&am[i].t,&am[i].p);
    sort(am,am+n);
    double ans=0.0;
    for(int i=0;i<n;i++)
    {
        dp[i]=am[i].p;
        for(int j=0;j<i;j++)
        {
            if(ok(i,j))
                dp[i]=max(dp[j]+am[i].p,dp[i]);
        }
        ans=max(ans,dp[i]);
    }
    printf("%.10f\n",ans);
    return 0;
}
