#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

double a[450][450],x[450];
void Gauss(int equ,int var)
{
    int i,j,k,max_r,col=0;
    double ss;
    for(k=0;k<equ && col<var;k++,col++)
    {
        max_r=k;
        for(i=k+1;i<equ;i++)
            if(abs(a[i][col])>abs(a[max_r][col])) max_r=i;
        if(max_r!=k) for(j=k;j<var+1;j++) swap(a[k][j],a[max_r][j]);
        for(i=k+1;i<equ;i++)
            if(abs(a[i][col])>1e-8)
            {
                ss=a[i][col]/a[k][col];a[i][col]=0.0;
                for(j=col+1;j<var+1;j++)
                    a[i][j]=a[i][j]-a[k][j]*ss;
            }
            else a[i][col]=0.0;
    }
    for(i=var-1;i>-1;i--)
    {
        ss=a[i][var];
        for(j=i+1;j<var;j++)
            if(abs(a[i][j])>1e-8)ss-=a[i][j]*x[j];
        x[i]=ss/a[i][i];
    }
}
char maz[20][20];
int to[20][20];
int dx[]={-1,1,0,0},dy[]={0,0,-1,1};
#include<queue>
bool bfs(int x,int y,int &k)
{
    queue<int>q;q.push(x*100+y);
    memset(to,-1,sizeof(to));
    bool f=0;to[x][y]=k++;
    while(!q.empty())
    {
        int s=q.front();q.pop();
        x=s/100;y=s%100;
        for(int i=0;i<4;i++)
        {
            int x1=x+dx[i],y1=y+dy[i];
            if(maz[x1][y1]=='.'&&to[x1][y1]==-1)
                    q.push(x1*100+y1),to[x1][y1]=k++;
            if(maz[x1][y1]=='$')f=1;
        }
    }
    return f;
}
int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        memset(maz,0,sizeof(maz));
        for(int i=0;i<n;i++)
            scanf("%s",maz[i+1]+1);
        bool o=0;int k=0,x1,y1;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(maz[i][j]=='@')
                    o=bfs(x1=i,y1=j,k);
        if(o)
        {
            for(int i=0;i<k;i++)
                for(int j=0;j<=k;j++)
                    a[i][j]=0.0;
            for(int i=1;i<=n;i++)
                for(int j=1;j<=m;j++)
                    if(to[i][j]!=-1)
                    {
                        int s=to[i][j],con=0;
                        for(int z=0;z<4;z++)
                        {
                            int x=i+dx[z],y=j+dy[z];
                            if(to[x][y]!=-1)con++,a[s][to[x][y]]=-1;
                            if(maz[x][y]=='$')con++;
                        }
                        a[s][s]=a[s][k]=con;
                    }
            Gauss(k,k);
            printf("%.6f\n",x[to[x1][y1]]);
        }
        else puts("-1");
    }
    return 0;
}