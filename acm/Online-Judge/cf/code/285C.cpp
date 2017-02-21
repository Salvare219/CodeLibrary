#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;


int num[300005];
bool vis[300005],col[300005];
int main()
{
 //   freopen("1.txt","r",stdin);
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",num+i);
    sort(num,num+n);
    for(i=0;i<n;i++)
        if(num[i]<=n && num[i]>0)
        {
            if(vis[num[i]]==0) vis[num[i]]=1,col[i]=1;
        }
    long long ans=0;
    int k=0;
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==0)
        {
            while(col[k]) k++;
            ans+=abs(num[k++]-i);
        }
    }
    printf("%I64d\n",ans);
    return 0;
}





























