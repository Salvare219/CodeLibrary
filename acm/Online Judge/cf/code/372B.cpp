#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

char maz[50][50];
int sum[50][50];
int tot[50][50][50][50];
int pre[50][50][50][50];
int sa[50][50][50][50];
int main()
{
//    freopen("1.txt","r",stdin);
    int n,m,q;
    scanf("%d%d%d",&n,&m,&q);
    for(int i=0;i<n;i++)
        scanf("%s",maz[i+1]+1);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            sum[i][j]=maz[i][j]-'0'+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            for(int x=i;x<=n;x++)
                for(int y=j;y<=m;y++)
                    if(sum[x][y]-sum[x][j-1]-sum[i-1][y]+sum[i-1][j-1]>0)
                        tot[i][j][x][y]=0;
                    else
                        tot[i][j][x][y]=1;
        }
    for(int i=n;i>0;i--)
        for(int j=m;j>0;j--)
        {
            for(int x=1;x<=n;x++)
                for(int y=1;y<=m;y++)
                    pre[i][j][x][y]=pre[i+1][j][x][y]+pre[i][j+1][x][y]-pre[i+1][j+1][x][y]+tot[i][j][x][y];
        }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            for(int x=1;x<=n;x++)
                for(int y=1;y<=m;y++)
                    sa[i][j][x][y]=pre[i][j][x][y]+sa[i][j][x-1][y]+sa[i][j][x][y-1]-sa[i][j][x-1][y-1];
        }
    for(int i=0;i<q;i++)
    {
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        printf("%d\n",sa[a][b][c][d]-sa[a][b][c][b-1]-sa[a][b][a-1][d]+sa[a][b][a-1][b-1]);
    }
    return 0;
}
