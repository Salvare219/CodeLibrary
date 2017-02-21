#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;


bool maz[500][500];
int p[500];
int fin(int s)
{
    if(s==p[s]) return s;
    else return p[s]=fin(p[s]);
}
int main()
{
  //  freopen("1.txt","r",stdin);
    int n,m,x,y;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        p[i]=i;
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&x,&y);
        maz[x][y]=maz[y][x]=1;
        int a=fin(x),b=fin(y);
        p[a]=b;
    }
    int ss[500]={0};
    for(int i=1;i<=n;i++)
    {
        int f=fin(i);
        ss[f]++;
    }
    bool flag=1;
    int t2=0,t1=0;
    for(int i=1;i<=n;i++)
    {
        if(ss[i]>3)
        {
            flag=0;
            break;
        }
        if(ss[i]==2) t2++;
        if(ss[i]==1) t1++;
    }
    if(t2>t1) flag=0;
    if(flag)
    {
        bool vis[500]={0};
        for(int i=1;i<=n;i++)
        {
            if(ss[i]==3)
            {
                printf("%d",i);
                for(int j=1;j<=n;j++)
                    if(maz[i][j]) printf(" %d",j);
                ss[i]=0;
                putchar(10);
            }
            if(ss[i]==2)
            {
                ss[i]=0;
                printf("%d",i);
                for(int j=1;j<=n;j++)
                    if(maz[i][j]) printf(" %d",j);
                for(int j=1;j<=n;j++)
                {
                    if(ss[j]==1)
                    {
                        ss[j]=0;
                        printf(" %d",j);
                        break;
                    }
                }
                putchar(10);
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(ss[i]==1)
            {
                ss[i]=0;
                printf("%d",i);
                int re=1;
                for(int j=1;j<=n;j++)
                    if(ss[j]==1)
                    {
                        ss[j]=0;
                        re++;
                        printf(" %d",j);
                        if(re==3) break;
                    }
                putchar(10);
            }
        }
    }
    else printf("-1\n");
    return 0;
}
