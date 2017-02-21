#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


int deg[20000];
int main()
{
    int n,sum=0,s=0;scanf("%d",&n);
    if(n<=2)puts("0");
    else
    {
        for(int i=0;i<n;i++)
            scanf("%d",deg+i),sum+=deg[i],s=max(deg[i],s);
        s-=sum%3;
        sum-=sum%3;
        sum-=s;
        s=min(s,sum*2);
        printf("%d\n",(sum+s)/3);
    }
    return 0;
}
