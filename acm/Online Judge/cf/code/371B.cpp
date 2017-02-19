#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

int a1[3],a2[3];
int main()
{
//    freopen("1.txt","r",stdin);
    int a,b;scanf("%d%d",&a,&b);
    while(a%2==0)a/=2,a1[0]++;
    while(a%3==0)a/=3,a1[1]++;
    while(a%5==0)a/=5,a1[2]++;
    while(b%2==0)b/=2,a2[0]++;
    while(b%3==0)b/=3,a2[1]++;
    while(b%5==0)b/=5,a2[2]++;
    if(a!=b)puts("-1");
    else
    {
        int ans=abs(a1[0]-a2[0])+abs(a1[1]-a2[1])+abs(a1[2]-a2[2]);
        printf("%d\n",ans);
    }
    return 0;
}
