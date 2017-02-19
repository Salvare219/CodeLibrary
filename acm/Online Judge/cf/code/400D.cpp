#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int h[100005];
int d[505][505];
int com[100005];
int ind[100005][505];
int re[506];
int find(int s)
{
    return com[s]==s?s:com[s]=find(com[s]);
}
int main()
{
//    freopen("1.txt","r",stdin);
    int n,m,k,x,y,s=0;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<k;i++)
    {
        scanf("%d",&x);re[i]=s;
        for(int j=0;j<x;j++)
            h[s+j]=i;
        s+=x;
    }
    re[k]=n;
    for(int i=0;i<n;i++)com[i]=i,ind[i][h[i]]++;
    for(int i=0;i<k;i++)
        for(int j=0;j<k;j++)
            if(i==j)d[i][j]=0;
            else d[i][j]=0x3fffffff;
    for(int i=0;i<m;i++)
    {
        int x1,y1;
        scanf("%d%d%d",&x,&y,&s);x--;y--;
        if(s==0)
        {
            x1=find(x);y1=find(y);
            if(x1!=y1)
            {
                com[x1]=y1;
                for(int j=0;j<k;j++)
                    ind[y1][j]+=ind[x1][j];
            }
        }
        d[h[x]][h[y]]=d[h[y]][h[x]]=min(d[h[x]][h[y]],s);
    }
    bool fin=1;
    for(int i=0;i<k;i++)
    {
        bool f=0;
        for(int j=re[i];j<re[i+1];j++)
            if(ind[find(j)][i]==re[i+1]-re[i])
            {
                f=1;
                break;
            }
        if(f==0)
        {
            fin=0;
            break;
        }
    }
    if(fin)
    {
        puts("Yes");
        for(int z=0;z<k;z++)
            for(int i=0;i<k;i++)
                for(int j=0;j<k;j++)
                    d[i][j]=min(d[i][j],d[i][z]+d[z][j]);
        for(int i=0;i<k;i++,putchar(10))
            for(int j=0;j<k;j++)
                if(d[i][j]<0x3fffffff)printf("%d ",d[i][j]);
                else printf("-1 ");
        putchar(10);
    }
    else puts("No");
    return 0;
}
