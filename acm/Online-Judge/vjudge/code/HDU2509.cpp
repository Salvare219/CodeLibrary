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


int sg[200];
int find(int s)
{
    if(sg[s]!=-1) return sg[s];
    bool vis[10005]={0};
    for(int i=0;i<s;i++)
        for(int j=s-i-1;j>-1;j--)
            vis[find(i)^find(j)]=1;
    for(int i=0;;i++)
        if(vis[i]==0) return sg[s]=i;
}
int main()
{
    int n;
    memset(sg,-1,sizeof(sg));
    sg[0]=0;
    for(int i=1;i<121;i++)
        find(i);
    while(scanf("%d",&n)==1)
    {
        bool anti=0;
        int sum=0,temp;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&temp);
            if(temp>1) anti=1;
            sum^=sg[temp];
        }
        if(sum) sum=1;
        if(anti^sum==0) printf("Yes\n");
        else printf("No\n");
    }
}