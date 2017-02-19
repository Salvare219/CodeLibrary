#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;


vector<int>g[10050];
vector<int>w[10050];
int com[10050];
int lab[10050];
bool v[10050];
int find(int s)
{
    return com[s]==s?s:com[s]=find(com[s]);
}

double a[1050][1050];
double x[1050];
int sgn(double x)
{
    return fabs(x)<1e-8?0:(x>0.0?1:-1);
}
int Gauss(int equ,int var)
{
    int i,j,k,max_r,col=0;
    for(i=0;i<=var;i++)
        x[i]=0.0;
    for(k=0;k<equ && col<var;k++,col++)
    {
        max_r=k;
        for(i=k+1;i<equ;i++)
            if(fabs(a[i][col])>fabs(a[max_r][col])) max_r=i;
        if(max_r!=k) for(j=k;j<var+1;j++) swap(a[k][j],a[max_r][j]);
        if(sgn(a[k][col])==0)
        {
            k--;
            continue;
        }
        for(i=k+1;i<equ;i++)
            if(sgn(a[i][col])!=0)
            {
                double tt=a[i][col]/a[k][col];
                for(j=col;j<var+1;j++)
                    a[i][j]-=a[k][j]*tt;
            }
    }
    for(i=k;i<equ;i++)
        if(sgn(a[i][col])!=0)return -1;
    if(k<var)
    {
        return var-k;
    }
    else
    {
        for(i=var-1;i>-1;i--)
        {
            double temp=a[i][var];
            for(j=i+1;j<var;j++)
                if(a[i][j]!=0)temp-=a[i][j]*x[j];
            x[i]=temp/a[i][i];
        }
        return 0;
    }
}

int main()
{
    int tt;scanf("%d",&tt);
    while(tt--)
    {
        int n,m,s,t;
        scanf("%d%d%d%d",&n,&m,&s,&t);
        for(int i=1;i<=n;i++)
        {
            g[i].clear();w[i].clear();
            com[i]=i;lab[i]=-1;v[i]=0;
        }
        for(int i=0;i<m;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            if(z)g[x].push_back(y);
            else w[x].push_back(y);
            com[find(x)]=find(y);
        }
        if(find(s)!=find(t))puts("inf");
        else
        {
            for(int i=1;i<=n;i++)
                if(find(i)==find(s))v[i]=1;
            for(int i=1;i<=n;i++)com[i]=i;
            for(int i=1;i<=n;i++)
                if(v[i])
                    for(int j=0;j<w[i].size();j++)
                        com[find(i)]=find(w[i][j]);
            if(find(s)==find(t))puts("0.000000");
            else
            {
                int cnt=0,sx,sy;
                for(int i=1;i<=n;i++)
                    if(v[i])
                        if(lab[find(i)]==-1)
                            lab[find(i)]=cnt++;
                for(int i=1;i<=n;i++)
                    if(lab[find(i)]!=-1)
                        for(int j=0;j<g[i].size();j++)
                        {
                            sx=lab[find(i)];
                            sy=lab[find(g[i][j])];
                            a[sx][sy]++;
                            a[sx][sx]--;
                            a[sy][sx]++;
                            a[sy][sy]--;
                        }
                sx=lab[find(s)];sy=lab[find(t)];
                a[sx][cnt]=-1.0;
                a[sy][cnt]=1.0;
                for(int i=0;i<cnt;i++)
                    a[cnt-1][i]=0;
                a[cnt-1][sx]=1.0;
                a[cnt-1][cnt]=1.0;
                Gauss(cnt,cnt);
                printf("%.6f\n",1.0-x[sy]);
                for(int i=0;i<=cnt;i++)
                    for(int j=0;j<=cnt;j++)
                        a[i][j]=0;
            }
        }
    }
    return 0;
}
