#include<bits/stdc++.h>
using namespace std;

vector<string> z,f[2];
char a[100005],f0[100005];
int n,m;
const int tx[]={1,0,-1,0},ty[]={0,1,0,-1};

void dfs(int x,int y,int stu)
{
    if(f[stu][x][y]=='1')
        return;
    f[stu][x][y]='1';
    if(z[x][y]>='2')
        stu=0;
    else if(z[x][y]<='0')
        stu=1;
    f[stu][x][y]='1';
    for(int i=0;i<4;i++)
    {
        int xx=x+tx[i],yy=y+ty[i];
        if(xx<0||xx>=n||yy<0||yy>=m)
            continue;
        if(z[xx][yy]=='0'&&stu==1)
            continue;
        dfs(xx,yy,stu);
    }
}

int main()
{
    freopen("islands.in","r",stdin);
    freopen("islands.out","w",stdout);
    int i,sx,sy,ex,ey;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++)
        f0[i]='0';
    for(i=0;i<n;i++)
    {
        scanf("%s",a);
        z.push_back(a);
        f[0].push_back(f0),f[1].push_back(f0);
    }
    scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
    sx--,sy--,ex--,ey--;
    dfs(sx,sy,0);
    puts(f[0][ex][ey]=='1'||f[1][ex][ey]=='1'?"YES":"NO");
    return 0;
}
