#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<queue>
using namespace std;

int fib[50];
int sg[1005];
int main()
{
    int m,n,p;
    fib[0]=fib[1]=1;
    for(int i=1;fib[i]<1001;i++)
        fib[i+1]=fib[i]+fib[i-1];
    sg[0]=0;
    bool vis[2000];
    for(int i=1;i<1001;i++)
    {
        memset(vis,0,sizeof(vis));
        for(int j=0;fib[j]<=i;j++)
            vis[sg[i-fib[j]]]=1;
        for(int j=0;;j++)
            if(vis[j]==0)
            {
                sg[i]=j;
                break;
            }
    }
    while(scanf("%d%d%d",&n,&m,&p))
    {
        if(n==0 && m==0 && p==0) break;
        if(sg[n]^sg[m]^sg[p]) printf("Fibo\n");
        else printf("Nacci\n");
    }
}
