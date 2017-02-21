//#include<bits/stdc++.h>
#include<cstdio>
using namespace std;


char maz[1000][1000];
bool v[1000][1000];
int x1,y1,x2,y2;
int n,m;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
bool dfs(int x,int y)
{
    //printf("%d %d\n",x,y);
    v[x][y]=1;
    for(int i=0;i<4;i++)
    {
        int xx=x+dx[i],yy=y+dy[i];
        if(xx>=n||xx<0)continue;
        if(yy>=m||yy<0)continue;
        if(xx==x2&&yy==y2)return 1;
        if(v[xx][yy])continue;
        if(maz[xx][yy]=='.')
        {
            if(dfs(xx,yy))
                return 1;
        }
    }
    return 0;
}
int abs(int x)
{
    return x>0?x:-x;
}
int main()
{
    //freopen("1.txt","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%s",maz[i]);
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    x1--;y1--;
    x2--;y2--;
    if(x1==x2&&y1==y2)
    {
        int cnt=0;
        for(int i=0;i<4;i++)
        {
            int xx=x2+dx[i],yy=y2+dy[i];
            if(xx>=n||xx<0)continue;
            if(yy>=m||yy<0)continue;
            if(maz[xx][yy]=='.')
                cnt++;
        }
        if(cnt>=1)puts("YES");
        else puts("NO");
    }
    else
    {
        int f=dfs(x1,y1);
        if(f)
        {
            if(maz[x2][y2]=='X')
                puts("YES");
            else
            {
                int cnt=0;
                for(int i=0;i<4;i++)
                {
                    int xx=x2+dx[i],yy=y2+dy[i];
                    if(xx>=n||xx<0)continue;
                    if(yy>=m||yy<0)continue;
                    if(maz[xx][yy]=='.')
                        cnt++;
                }
                if(abs(x1-x2)+abs(y1-y2)==1)
                {
                    if(cnt>=1)puts("YES");
                    else puts("NO");
                }
                else
                {
                    if(cnt>=2)puts("YES");
                    else puts("NO");
                }
            }
        }
        else puts("NO");
    }
    return 0;
}

