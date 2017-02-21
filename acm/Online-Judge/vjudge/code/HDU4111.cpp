#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

bool dp[50055][60],v[50050][60];
bool dfs(int a,int b)
{
    if(a<0||b<0) return 1;
    if(v[a][b]) return dp[a][b];
    v[a][b]=1;
    bool f;
    if(a==0) f=min(dfs(2,b-2),dfs(0,b-1));
    else if(a==2) f=min(min(dfs(0,b+1),dfs(a,b-1)),min(dfs(a+1,b-1),dfs(a+3,b-2)));
    else f=min(min(dfs(a-1,b),dfs(a,b-1)),min(dfs(a+1,b-1),dfs(a+3,b-2)));
    return dp[a][b]=f^1;
}
int main()
{
    int t,ti=1;scanf("%d",&t);
    while(t--)
    {
        int n,x,sum=-1,con=0;scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&x);
            if(x-1)sum+=x+1;
            else con++;
        }
        sum=max(sum,0);
        printf("Case #%d: %s\n",ti++,dfs(sum,con)?"Alice":"Bob");
    }
    return 0;
}
