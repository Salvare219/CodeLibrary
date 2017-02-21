#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

vector<long long> g[105],lc[105],gc[105];
void add(long long x,long long y,long long a,long long b)
{
    g[x].push_back(y);g[y].push_back(x);
    lc[x].push_back(b);lc[y].push_back(b);
    gc[x].push_back(a);gc[y].push_back(a);
}
long long v[105],ans[105];
bool test(int s)
{
    int x,y;
    queue<int>q;q.push(s);
    while(!q.empty())
    {
        x=q.front();q.pop();
        for(int i=0;i<g[x].size();i++)
        {
            y=g[x][i];
            if(v[y]==-1)
            {
                if(lc[x][i]%v[x]!=0)return 0;
                v[y]=lc[x][i]/v[x]*gc[x][i];
                if(__gcd(v[y],v[x])!=gc[x][i])return 0;
                q.push(y);
            }
            else
            {
                if(v[y]!=lc[x][i]/v[x]*gc[x][i]||__gcd(v[y],v[x])!=gc[x][i])return 0;
            }
        }
    }
    return 1;
}
int main()
{
    int n,m;
    long long x,y,a,b;scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        scanf("%I64d%I64d%I64d%I64d",&x,&y,&a,&b);
        if(b%a)
        {
            puts("NO");return 0;
        }
        add(x,y,a,b);
    }
    if(m==0)
    {
        puts("YES");
        for(int i=0;i<n;i++)printf("1 ");putchar(10);
    }
    else
    {
        memset(ans,-1,sizeof(ans));
        bool flag=1;
        for(int i=1;i<=n;i++)
            if(ans[i]==-1)
            {
                if(g[i].size()==0)ans[i]=1;
                else
                {
                    bool f=0;
                    long long a1=gc[i][0],a2=lc[i][0];
                    x=i;y=g[i][0];
                    for(int j=1;j*j<a2;j++)
                        if(a2%j==0)
                        {
                            for(int l=1;l<=n;l++)v[l]=-1;
                            v[x]=j;
                            if(test(x))
                            {f=1;break;}
                            for(int l=1;l<=n;l++)v[l]=-1;
                            v[y]=j;
                            if(test(y))
                            {f=1;break;}
                            for(int l=1;l<=n;l++)v[l]=-1;
                            v[x]=j*a1;
                            if(test(x))
                            {f=1;break;}
                            for(int l=1;l<=n;l++)v[l]=-1;
                            v[y]=j*a1;
                            if(test(y))
                            {f=1;break;}
                        }
                    if(f)
                    {
                        for(int i=1;i<=n;i++)
                            if(v[i]!=-1)ans[i]=v[i];
                    }
                    else
                    {
                        flag=0;break;
                    }
                }
            }
        if(flag)
        {
            puts("YES");
            for(int i=0;i<n;i++)printf("%I64d ",ans[i+1]);putchar(10);
        }
        else puts("NO");
    }
    return 0;
}
