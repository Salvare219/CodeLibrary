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


int le[15555],bit[32555];
int query(int x)
{
    int s=0;
    while(x>0)
    {
        s+=bit[x];
        x-=x&-x;
    }
    return s;
}
int updat(int x)
{
    while(x<32556)
    {
        bit[x]++;
        x+=x&-x;
    }
}
int main()
{
    int n,x,y;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&x,&y);
        le[query(x+1)]++;
        updat(x+1);
    }
    for(int i=0;i<n;i++)
        printf("%d\n",le[i]);
    return 0;
}
