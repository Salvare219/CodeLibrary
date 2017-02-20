#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;


int n;
long long num[100005];
int prim[500005];
bool vis[5000005];
void cal()
{
    int k=0;
    for(int i=2;i<5000002;i++)
    {
        if(vis[i]==0) prim[k++]=i;
        for(int j=0;j<k && prim[j]*i<5000002;j++)
        {
            vis[prim[j]*i]=1;
            if(i%prim[j]==0) break;
        }
    }
}
int main()
{
 //   freopen("1.txt","r",stdin);
    cal();
    int ss=1;
    while(scanf("%d",&n)==1)
    {
        for(int i=0;i<n;i++)
            scanf("%lld",num+i);
        long long ans,ti;
        int k;
        for(int i=0;i<n;i++)
        {
            ti=0;k=0;
            while(vis[num[i]])
            {
                while(num[i]%prim[k]==0)
                {
                    num[i]/=prim[k];
                    ti++;
                }
                k++;
            }
            if(num[i]==1) num[i]=ti;
			else num[i]=ti+1;
        }
        ans=0;
        for(int i=0;i<n;i++)
            ans^=num[i];
        if(ans)
        {
            int sa;
            long long oo;
            for(int i=0;i<n;i++)
            {
                oo=ans;
                oo^=num[i];
                if(oo<=num[i])
                {
                    sa=i;
                    break;
                }
            }
            printf("Test #%d: Alice %d\n",ss++,sa+1);
        }
        else printf("Test #%d: Bob\n",ss++);
    }
    return 0;
}

