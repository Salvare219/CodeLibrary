#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


int a[1005];
int ans[1005][1005];
int cnt;
int n,d,k;
int sa[1005];
void dfs(int h,int dep)
{
    if(d==dep)
    {
        for(int i=0;i<d;i++)
            ans[i][cnt]=sa[i];
        cnt++;
        return ;
    }
    for(int i=1;i<=k;i++)
    {
        sa[h]=i;
        dfs(h+1,dep+1);
        if(cnt==n)return ;
    }
}
int main()
{
    //freopen("1.txt","r",stdin);
    scanf("%d%d%d",&n,&k,&d);
    cnt=0;
    dfs(0,0);
    if(cnt<n)puts("-1");
    else
    {
        for(int i=0;i<d;i++,putchar(10))
            for(int j=0;j<n;j++)
                printf("%d ",ans[i][j]);
    }
    return 0;
}
