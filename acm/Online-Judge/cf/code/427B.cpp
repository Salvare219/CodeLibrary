#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int a[500000];
int main()
{
//    freopen("1.txt","r",stdin);
    int n,t,c;scanf("%d%d%d",&n,&t,&c);
    for(int i=0;i<n;i++)
        scanf("%d",a+i);
    int cnt=0,ans=0;
    for(int i=0;i<c;i++)
        if(a[i]>t)cnt++;
    if(cnt==0)ans++;
    for(int i=c;i<n;i++)
    {
        if(a[i]>t)cnt++;
        if(a[i-c]>t)cnt--;
        if(cnt==0)ans++;
    }
    printf("%d\n",ans);
    return 0;
}
