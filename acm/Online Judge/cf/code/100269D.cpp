#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

#include<queue>
int w[10050];
int inq[10050];
int n,m;
vector<pair<int,int> >gra[10050];
vector<int>wic[10050];
void spfa(int s)
{
    queue<int>q;
    for(int i=0;i<n;i++)
        q.push(i),inq[i]=0;
    while(!q.empty())
    {
        int x=q.front(),y,z;q.pop();
        inq[x]=0;
        int las=w[x];
        for(int i=0;i<gra[x].size();i++)
        {
            y=gra[x][i].first;
            z=gra[x][i].second;
            if(w[x]>w[y]+w[z])
            {
                w[x]=w[y]+w[z];
            }
        }
        if(las>w[x])
        {
            for(int j=0;j<wic[x].size();j++)
                if(inq[wic[x][j]]==0)
                {
                    inq[wic[x][j]]=1;
                    q.push(wic[x][j]);
                }
        }
    }
}
int main()
{
    freopen("dwarf.in","r",stdin);
    freopen("dwarf.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%d",w+i);
    for(int i=0;i<m;i++)
    {
        int x,y,z;scanf("%d%d%d",&z,&x,&y);
        z--;x--;y--;
        gra[z].push_back(make_pair(x,y));
        wic[x].push_back(z);
        wic[y].push_back(z);
    }
    spfa(0);
    printf("%d\n",w[0]);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
