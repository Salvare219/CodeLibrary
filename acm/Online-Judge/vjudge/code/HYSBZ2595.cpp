#include <bits/stdc++.h>
using namespace std;


int a[22][22];
int dp[22][22][1<<10];
int pre[22][22][1<<10];
bool v[22][22];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
bool c[22][22];
void cal(int x,int y,int s)
{
    int f=pre[x][y][s];c[x][y]=1;
    int xx=f/100%100,yy=f%100,ss=f/10000;
    if(f==-1)return;cal(xx,yy,ss);
    if(xx==x&&yy==y)cal(xx,yy,s^ss);
}
int main()
{
    int n,m,k=0,fx,fy;scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&a[i][j]),k+=(!a[i][j]);
    int lim=1<<k,cnt=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            for(int z=0;z<lim;z++)
                dp[i][j][z]=1<<28;
            if(a[i][j]==0)
                dp[i][j][1<<cnt]=0,pre[i][j][1<<cnt]=-1,cnt++,fx=i,fy=j;
        }
    queue<int>q;
    for(int s=1;s<lim;s++)
    {
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                for(int f=s;f;f=(f-1)&s)
                {
                    if(dp[i][j][s]>dp[i][j][f]+dp[i][j][f^s]-a[i][j])
                    {
                        dp[i][j][s]=dp[i][j][f]+dp[i][j][f^s]-a[i][j];
                        pre[i][j][s]=f*10000+i*100+j;
                    }
                    if(dp[i][j][s]<(1<<28)&&v[i][j]==0)
                        q.push(i*100+j),v[i][j]=1;
                }
        while(!q.empty())
        {
            int x=q.front()/100,y=q.front()%100;
            v[x][y]=0;q.pop();
            for(int i=0;i<4;i++)
            {
                int xx=x+dx[i],yy=y+dy[i];
                if(xx<n&&xx>=0&&yy>=0&&yy<m)
                {
                    if(dp[xx][yy][s]>dp[x][y][s]+a[xx][yy])
                    {
                        dp[xx][yy][s]=dp[x][y][s]+a[xx][yy];
                        pre[xx][yy][s]=s*10000+x*100+y;
                        if(v[xx][yy]==0)
                            q.push(xx*100+yy),v[xx][yy]=1;
                    }
                }
            }
        }
    }
    printf("%d\n",dp[fx][fy][lim-1]);cal(fx,fy,lim-1);
    for(int i=0;i<n;i++,putchar(10))
        for(int j=0;j<m;j++)
            if(a[i][j]==0)putchar('x');
            else if(c[i][j])putchar('o');
            else putchar('_');
    return 0;
}
