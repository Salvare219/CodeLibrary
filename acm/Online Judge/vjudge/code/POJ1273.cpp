//#include <bits/stdc++.h>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#include<cmath>
using namespace std;


namespace Commodity_Flow
{
    const int N=700;
    const int M=700;
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
        bool __opt()
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
        bool __init()
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
                pivot(n,tc);__opt();
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
            if(!__init())return -1;     //无解
            if(!__opt())return 0;       //无限大
            for(int i=1;i<=n;i++)
                x[pf[i]]=0;
            for(int i=n+1;i<=n+m;i++)
                x[pf[i]]=a[i-n][0];
            return 1;                 //有解
        }
    }g;
    int solv(int n,int m,int d,int bx[],int by[],int bw[],int fx[],int fy[],int fw[])
    {
//实数单纯形  z=a[0][0]+max(sigma(j,a[0][j]*x[j]))
//            0<=a[i][0]+sigma(j,a[i][j]*x[j])
//            n为变元个数,m为约束个数
//标准型要求: a[i][0]>=0
//解为 x[i] 1<=i<=n
        int s=n+1,t=n;
        g.m=n+n+m;
        g.n=m+1;
        for(int i=0;i<=n+n+m;i++)
        {
            for(int j=0;j<=m+1;j++)
                g.a[i][j]=0.0;
        }
        g.a[0][m+1]=1.0;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<m;j++)
                if(bx[j]==i)
                {
                    g.a[i][j+1]=-1.0;
                    g.a[i+n][j+1]=1.0;
                }
                else if(by[j]==i)
                {
                    g.a[i][j+1]=1.0;
                    g.a[i+n][j+1]=-1.0;
                }
            if(i==1)
            {
                g.a[i][m+1]=1.0;
                g.a[i+n][m+1]=-1.0;
            }
            if(i==n)
            {
                g.a[i][m+1]=-1.0;
                g.a[i+n][m+1]=1.0;
            }
        }
        for(int i=0;i<m;i++)
        {
            g.a[i+n+n+1][i+1]=-1.0;
            g.a[i+n+n+1][0]=bw[i];
        }
        //g.pri();
        g.solv();
        int ans=(int)(g.x[m+1]+0.5);
        return ans;
    }
}
int bx[500],by[500],bw[500];
int fx[2],fy[2],fw[2];
int main()
{
    int n,m;
    while(~scanf("%d%d",&m,&n))
    {
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",bx+i,by+i,bw+i);
            if(bx[i]==by[i])
            {
                m--;
                i--;
            }
        }
        fx[0]=1;
        fy[0]=n;
        printf("%d\n",Commodity_Flow::solv(n,m,1,bx,by,bw,fx,fy,fw));
    }
    return 0;
}
