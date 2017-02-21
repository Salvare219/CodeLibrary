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


int num[155];
bool vis[2222];
int sg[10050];
int main()
{
    int k,n;
    while(scanf("%d",&k))
    {
        if(k==0) break;
        for(int i=0;i<k;i++)
            scanf("%d",num+i);
        sg[0]=0;
        for(int i=1;i<10001;i++)
        {
            memset(vis,0,sizeof(vis));
            for(int j=0;j<k;j++)
                if(i>=num[j]) vis[sg[i-num[j]]]=1;
            for(int j=0;;j++)
                if(vis[j]==0)
                {
                    sg[i]=j;
                    break;
                }
        }
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            int sum=0,temp,m;
            scanf("%d",&m);
            for(int j=0;j<m;j++)
                scanf("%d",&temp),sum^=sg[temp];
            if(sum) printf("W");
            else printf("L");
        }
        putchar(10);
    }
    return 0;
}
