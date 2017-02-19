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


vector<int> gra[205];
bool inque[205];
int now[205],timer[205],maze[205][205];
int n,m;
int spfa(int s,int e)
{
    int x,to;
    queue<int> que;
    memset(timer,0,sizeof(0));
    memset(inque,0,sizeof(inque));
    for(int i=0;i<=n;i++) now[i]=0x3fffffff;
    que.push(s);now[s]=0;
	timer[s]++;
    while(!que.empty())
    {
        x=que.front();
        que.pop();
        inque[x]=0;
        for(int i=0;i<gra[x].size();i++)
        {
            to=gra[x][i];
            if(now[to]>now[x]+maze[x][to])
            {
                now[to]=now[x]+maze[x][to];
                if(inque[to]) continue;
                timer[to]++;
                inque[to]=1;
                que.push(to);
                if(timer[to]==n) return -1;
            }
        }
    }
    return now[e];
}
int dec[205],poi[205][2];
int main()
{
    int d;
    scanf("%d%d",&n,&d);
    dec[0]=dec[n-1]=0;
    for(int i=0;i<n-2;i++)
        scanf("%d",dec+i+1);
    for(int i=0;i<n;i++)
        scanf("%d%d",&poi[i][0],&poi[i][1]);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            if(i==j) continue;
            maze[i][j]=d*abs(poi[i][0]-poi[j][0])+d*abs(poi[i][1]-poi[j][1])-dec[j];
            gra[i].push_back(j);
            gra[j].push_back(i);
        }
    printf("%d\n",spfa(n-1,0));
    return 0;
}
