#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
//    freopen("1.txt","r",stdin);
    int n,a,b,c,d;scanf("%d",&n);
    int aa=-1,bb=-1,f=-1;
    for(int i=0;i<4;i++)
    {
        scanf("%d%d%d%d",&a,&b,&c,&d);
        a=min(a,b);c=min(c,d);
        if(a+c<=n)
        {
            aa=a;f=i+1;
            bb=n-a;
            break;
        }
    }
    if(f==-1) printf("-1\n");
    else
    {
        printf("%d %d %d\n",f,aa,bb);
    }
    return 0;
}

