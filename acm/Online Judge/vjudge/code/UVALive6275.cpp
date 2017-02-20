#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

#include<map>
map<int,bool>mp;
int main()
{
    int n,x;
    while(~scanf("%d%d",&x,&n))
    {
        int y,ans=-1,l1,l2;mp.clear();
        x*=10000000;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&y);
            if(mp[x-y])
            {
                if(abs(x-2*y)>=ans)
                {
                    ans=abs(x-2*y);
                    l1=x-y;l2=y;
                }
            }
            mp[y]=1;
        }
        if(l1>l2)swap(l1,l2);
        if(ans==-1)puts("danger");
        else
        {
            printf("yes %d %d\n",l1,l2);
        }
    }
    return 0;
}
