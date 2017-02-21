#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
using namespace std;


//实数单纯形  z=a[0][0]+max(sigma(j,a[0][j]*x[j]))
//            0<=a[i][0]+sigma(j,a[i][j]*x[j])
//            n为变元个数,m为约束个数
//标准型要求: b[i]>=0

const int N=100;
const int M=100;
const double INF=1e20;
int sgn(double x)
{
    return fabs(x)<1e-8?0:(x>0.0?1:-1);
}
struct simplex
{
    int pf[N+M],m,n;
    double a[M][N],c[N],z;
    double x[N+M];
    int next[N];

    void pivot(int x,int y)
    {
        int las=-1;
        swap(pf[x],pf[n+y]);
        a[y][x]=1.0/a[y][x];
        for(int i=0;i<=n;i++)
            if(sgn(a[y][i])&&i!=x)next[i]=las,las=i,a[y][i]*=-a[y][x];
        for(int i=0;i<=m;i++)
            if(i!=y)
            {
                for(int j=las;~j;j=next[j])
                    a[i][j]+=a[y][j]*a[i][x];
                a[i][x]*=a[y][x];
            }
    }
    bool opt()
    {
        int pc,tc,i;
        double mc;
        while(1)
        {
            for(tc=i=1;i<=n;i++)
                if(sgn(a[0][i]-a[0][tc])>0)tc=i;
            if(sgn(a[0][tc])<=0)return z=a[0][0],1;
            pc=-1;mc=INF;
            for(i=1;i<=m;i++)
                if(sgn(a[i][tc])<0&&sgn(mc+a[i][0]/a[i][tc])>0)
                    mc=-a[pc=i][0]/a[i][tc];
            if(pc==-1)return 0;
            pivot(tc,pc);
        }
    }
    void pri()
    {
        for(int i=0;i<=m;i++,putchar(10))
            for(int j=0;j<=n;j++)
                printf("%f ",a[i][j]);
        putchar(10);
    }
    bool init()
    {
        double mc=1.0;
        int tc;
        for(int i=1;i<=n+m;i++)pf[i]=i;
        for(int i=1;i<=m;i++)
            if(sgn(mc-a[i][0])>0)mc=a[tc=i][0];
        if(sgn(mc)<0)
        {
            for(int i=1;i<=n;i++)c[i]=a[0][i],a[0][i]=0;
            a[0][++n]=-1;pf[n+m]=n+m;
            for(int i=1;i<=m;i++)a[i][n]=1;
            pivot(n,tc);opt();
            if(sgn(z)<0)return 0;
            for(int i=1;i<=n+m;i++)
                if(pf[i]==n)
                    if(i>n)pivot(1,i-n),tc=1;
                    else tc=i;
            for(int i=0;i<=m;i++)a[i][tc]=0;
            for(int i=1;i<=n;i++)if(pf[i]<n)a[0][i]+=c[pf[i]];
            for(int i=n+1;i<=m+n;i++)
                if(pf[i]<n)
                    for(int j=0;j<=n;j++)a[0][j]+=c[pf[i]]*a[i-n][j];
        }
        return 1;
    }
    int solv()
    {
        if(!init())return -1;     //无解
        if(!opt())return 0;       //无限大
        for(int i=1;i<=n;i++)
            x[pf[i]]=0;
        for(int i=n+1;i<=n+m;i++)
            x[pf[i]]=a[i-n][0];
        return 1;                 //有解
    }
}g;
int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        g.n=n;g.m=m;
        g.a[0][0]=0;
        for(int i=1;i<=n;i++)
            scanf("%lf",&g.a[0][i]);
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
                scanf("%lf",&g.a[i][j]),g.a[i][j]=-g.a[i][j];
            scanf("%lf",&g.a[i][0]);
        }
        if(g.solv())
            printf("Nasa can spend %.0f taka.\n",ceil(m*g.z));
    }
    return 0;
}
