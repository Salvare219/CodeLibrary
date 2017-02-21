#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int nn,mm;
bool visx[105],visy[105];
int pre[105],gra[105][105];
int lx[105],ly[105],slack[105];
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
            if(find(i)) break;
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
char maze[105];
int s1[105][2],s2[105][2];
int main()
{
    while(scanf("%d%d",&nn,&mm))
    {
        if(nn==0) break;
        int k1=0,k2=0;
        for(int i=0;i<nn;i++)
        {
            scanf("%s",maze);
            for(int j=0;j<mm;j++)
            {
                if(maze[j]=='H')
                {
                    s1[k1][0]=i;
                    s1[k1++][1]=j;
                }
                if(maze[j]=='m')
                {
                    s2[k2][0]=i;
                    s2[k2++][1]=j;
                }
            }
        }
        for(int i=0;i<k1;i++)
            for(int j=0;j<k2;j++)
                gra[i+1][j+1]=-abs(s1[i][0]-s2[j][0])-abs(s1[i][1]-s2[j][1]);
        nn=k1;mm=k2;
        printf("%d\n",-Kuhn_Munkras());
    }
    return 0;
}

