#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int main()
{
    //freopen("1.txt","r",stdin);
    int n,m,x,sum=0,tot=0;scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        if(sum+x<=m)sum+=x;
        else sum=x,tot++;
    }
    if(sum)tot++;
    printf("%d\n",tot);
    return 0;
}
