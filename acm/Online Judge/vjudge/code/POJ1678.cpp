#include<cstdio>
#include<algorithm>
using namespace std;

int dp[10005],f[10005];
bool v[10005];
int n,a,b;
int dfs(int s,int x)
{
    if(v[s]) return dp[s];
    v[s]=1;int i=s,y=-0x3fffffff;
    while(i<n&&f[i]<x+a)i++;
    while(i<n&&f[i]<=x+b)y=max(y,f[i]-dfs(i+1,f[i])),i++;
    if(y==-0x3fffffff) return dp[s]=0;
    else return dp[s]=y;
}
int main()
{
    int t,k;scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&a,&b);
        for(int i=k=0;i<n;i++)
            scanf("%d",f+k),f[k]<a?0:k++,v[i]=0;
        v[n=k]=0;sort(f,f+n);
        printf("%d\n",dfs(0,0));
    }
    return 0;
}