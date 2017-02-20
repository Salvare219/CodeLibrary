#include<bits/stdc++.h>
using namespace std;


int ans;
void dfs(int n,int las,int mul,int sum)
{
    if(n==0)
    {
        if(mul==sum)ans++;
    }
    else
    {
        for(int i=las;i>0;i--)
        {
            if(mul*i>sum+i+n-1)continue;
            dfs(n-1,i,mul*i,sum+i);
        }
    }
}
int main()
{
    freopen("sump.in","r",stdin);
    freopen("sump.out","w",stdout);
    int n;scanf("%d",&n);
    dfs(n,n,1,0);
    printf("%d\n",ans);
    return 0;
}
