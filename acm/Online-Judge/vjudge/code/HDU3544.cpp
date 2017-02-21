#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

int w(int x,int y)
{
    if(x==1)return 1-y;
    if(y==1)return x-1;
    return w(x>>1,y>>1);
}
int main()
{
    int t,ti=1;scanf("%d",&t);
    while(t--)
    {
        int n,x,y;scanf("%d",&n);
        long long a=0;
        for(int i=0;i<n;i++)
            scanf("%d%d",&x,&y),a+=w(x,y);
        printf("Case %d: %s\n",ti++,a>0?"Alice":"Bob");
    }
    return 0;
}
