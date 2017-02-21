#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;


int main()
{
 //   freopen("1.txt","r",stdin);
    int x,y,s1=0,s2=0,n;
    int ss=0,xx=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&x,&y);
        s1+=x;s2+=y;
        if(x%2 && y%2==0) ss=1;
        if(x%2==0 && y%2) xx=1;
    }
    if(s1%2==0 && s2%2==0) puts("0");
    else if(s1%2 && s2%2)
    {
        if(ss || xx) puts("1");
        else puts("-1");
    }
    else puts("-1");
    return 0;
}
