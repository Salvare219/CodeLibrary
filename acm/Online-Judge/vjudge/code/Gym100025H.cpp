#include <bits/stdc++.h>
using namespace std;


bool v[100050];
int sg[100050],f;
int dfs(int s)
{
    if(v[s])return sg[s];
    v[s]=1;
    if(s<f)return sg[s]=0;
    bool g[2000]={0};
    int k;
    for(int i=2;i<=s;i=k+1)
    {
        k=s/(s/i);
        int a=s/i;
        int x=dfs(a),y=dfs(a+1);
        int res=s%a;
        int c1=s/a-res,c2=res;
        if(c1%2&&c2%2)g[x^y]=1;
        else if(c1%2)g[x]=1;
        else if(c2%2)g[y]=1;
        else g[0]=1;
        if(k!=i)
        {
            if(a&1)c2++;
            else c1++;
            if(c1%2&&c2%2)g[x^y]=1;
            else if(c1%2)g[x]=1;
            else if(c2%2)g[y]=1;
            else g[0]=1;
        }
    }
        /*
    for(int i=2;i<=s;i++)
    {
        int x=dfs(s/i),y=dfs(s/i+1);
        int res=s%(s/i);
        int c1=s/(s/i)-res,c2=res;
        if(c1%2&&c2%2)g[x^y]=1;
        else if(c1%2)g[x]=1;
        else if(c2%2)g[y]=1;
        else g[0]=1;
    }*/
    for(int i=0;;i++)
        if(g[i]==0)
            return sg[s]=i;
}
int main()
{
    //freopen("2.txt","w",stdout);
    freopen("nimg.in","r",stdin);
    freopen("nimg.out","w",stdout);
    int n;scanf("%d%d",&n,&f);
    for(int i=1;i<100005;i++)dfs(i);
    for(int i=0;i<n;i++)
    {
        int x,y,s=0;
        scanf("%d",&x);
        while(x--)
            scanf("%d",&y),s^=sg[y];
        s=min(1,s);
        printf("%d%c",s,i==n-1?10:32);
    }
    return 0;
}
