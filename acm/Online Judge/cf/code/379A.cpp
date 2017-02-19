#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
//    freopen("1.txt","r",stdin);
    int a,b,c=0,d,ans=0;
    scanf("%d%d",&a,&b);
    while(a)
    {
        ans+=a;
        d=(a+c)/b;
        c=(a+c)%b;
        a=d;
    }
    printf("%d\n",ans);
    return 0;
}
