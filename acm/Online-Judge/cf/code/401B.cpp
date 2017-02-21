#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int com[5000],te[5000];
int main()
{
//    freopen("1.txt","r",stdin);
    int x,k;
    scanf("%d%d",&x,&k);
    for(int i=0;i<k;i++)
    {
        int ty,a,b;
        scanf("%d",&ty);
        if(ty==1)
        {
            scanf("%d%d",&a,&b);
            com[a]=2;com[b]=1;
        }
        else
        {
            scanf("%d",&a);
            com[a]=2;
        }
    }
    int ans1=0,ans2=0;
    for(int i=1;i<=x;i++)te[i]=com[i];
    for(int i=1;i<x;i++)
        if(te[i]==0)
        {
            if(i+1<x&&te[i+1]==0)
                te[i+1]=2,ans1++;
            else ans1++;
        }
    for(int i=1;i<x;i++)
        if(com[i]==0)ans2++;
    printf("%d %d\n",ans1,ans2);
    return 0;
}
