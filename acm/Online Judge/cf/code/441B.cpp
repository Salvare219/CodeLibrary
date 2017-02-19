#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int tot[5000];
int main()
{
    //freopen("1.txt","r",stdin);
    int n,c;scanf("%d%d",&n,&c);
    for(int i=0;i<n;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        tot[a]+=b;
    }
    int ans=0;
    for(int i=1;i<=3003;i++)
    {
        int v=c;
        if(tot[i-1]>v)
        {
            ans+=v;
            v=0;
        }
        else
        {
            v-=tot[i-1];
            ans+=tot[i-1];
        }
        if(tot[i]>v)
        {
            ans+=v;
            tot[i]-=v;
            v=0;
        }
        else
        {
            ans+=tot[i];
            tot[i]=0;
        }
    }
    printf("%d\n",ans);
    return 0;
}