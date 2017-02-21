#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <stack>
#include <bitset>
using namespace std;


bool lin[405][405];
int v[405];
int q[405];
inline void extend(int n,int &l)
{
    int s=q[l-1],f;
    while(true)
    {
        for(f=1;f<=n;f++)
            if(lin[s][f]&&v[f]==0)break;
        if(f==n+1)return;
        v[q[l++]=s=f]=1;
    }
}
inline void rev(int l,int r)
{
    while(l<r)swap(q[l++],q[r--]);
}
bool hamiltun(int n)
{
    int l=1,s,t,x,y;
    for(int i=1;i<=n;i++)v[i]=0;
    q[0]=v[1]=s=t=1;
    while(1)
    {
        extend(n,l);rev(0,l-1);
        extend(n,l);
        if(!lin[s=q[0]][t=q[l-1]])
        {
            for(x=0;x<l;x++)
                if(lin[s][q[x+1]]&&lin[t][q[x]])break;
            rev(x+1,l-1);
        }
        if(l==n)return 1;
        for(x=0;x<l;x++)
        {
            for(y=1;y<=n;y++)
                if(v[y]==0&&lin[q[x]][y])break;
            if(y!=n+1)break;
        }
        rev(0,x-1);rev(x,l-1);
        v[q[l++]=y]=1;
    }
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)&&n)
    {
        int x,y;n<<=1;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                lin[i][j]=1;
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&x,&y);
            lin[x][y]=lin[y][x]=0;
        }
        hamiltun(n);
        for(int i=0;i<n;i++)
            printf("%d%c",q[i],i==n-1?10:32);
    }
    return 0;
}
