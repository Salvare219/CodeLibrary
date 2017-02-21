#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
using namespace std;


char str[1000];
int num[1000],k;
int ans[1050];
bool dfs(int m,int sum,int las)
{
    if(m==0) return 1;
    else
    {
        for(int i=0;i<k;i++)
            if(num[i]>sum && num[i]!=las)
            {
                ans[m]=num[i];
                if(dfs(m-1,num[i]-sum,num[i])) return 1;
            }
    }
    return 0;
}
int main()
{
//    freopen("1.txt","r",stdin);
    int m;
    scanf("%s%d",str,&m);
    for(int i=0;str[i];i++)
        if(str[i]=='1') num[k++]=i+1;
    if(dfs(m,0,-1))
    {
        printf("YES\n");
        for(int i=m;i>0;i--)
            printf("%d ",ans[i]);
        putchar(10);
    }
    else printf("NO\n");
	return 0;
}
