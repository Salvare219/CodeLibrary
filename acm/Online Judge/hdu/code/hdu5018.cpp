#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;


long long f[5555];
int main()
{
    //freopen("1.txt","r",stdin);
    int t;scanf("%d",&t);
    while(t--)
    {
        int a,b,c,i;
        scanf("%d%d%d",&a,&b,&c);
        if(c==a||c==b)puts("Yes");
        else
        {
            f[0]=a;f[1]=b;
            for(i=2;;i++)
            {
                f[i]=f[i-1]+f[i-2];
                if(f[i]>=c)break;
            }
            if(f[i]==c)puts("Yes");
            else puts("No");
        }
    }
    return 0;
}
