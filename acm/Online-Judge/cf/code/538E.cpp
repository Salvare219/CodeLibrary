#include<bits/stdc++.h>
using namespace std;


int n;
vector<int>gra[200050];
int dp1[200050][2];
int dfs1(int s,int f)
{
    int y,sz,r1=n,r2=0,sum=0,ff=0;
    for(int i=0;i<gra[s].size();i++)
    {
        ff=1;
        y=gra[s][i];
        sz=dfs1(y,f^1);
        sum+=sz;
        r1=min(r1,sz-dp1[y][f^1]);
        r2+=dp1[y][f^1]-1;
    }
    if(ff==0)
    {
        sum++;
        r1=r2=0;
        dp1[s][f]=1;
    }
    else
    {
        if(f==0)
        {
            dp1[s][f]=sum-r1;
        }
        else
        {
            dp1[s][f]=r2+1;
        }
    }
    return sum;
}
int dp2[200050][2];
int dfs2(int s,int f)
{
    int y,sz,r1=0,r2=n,sum=0,ff=0;
    for(int i=0;i<gra[s].size();i++)
    {
        ff=1;
        y=gra[s][i];
        sz=dfs2(y,f^1);
        sum+=sz;
        r1+=sz-dp2[y][f^1];
        r2=min(r2,dp2[y][f^1]-1);
    }
    if(ff==0)
    {
        sum++;
        r1=r2=0;
        dp2[s][f]=1;
    }
    else
    {
        if(f==0)
        {
            dp2[s][f]=sum-r1;
        }
        else
        {
            dp2[s][f]=r2+1;
        }
    }
    return sum;
}
int main()
{
    //freopen("1.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        gra[x].push_back(y);
    }
    dfs1(1,0);
    dfs2(1,0);
    printf("%d %d\n",dp1[1][0],dp2[1][0]);
    return 0;
}

