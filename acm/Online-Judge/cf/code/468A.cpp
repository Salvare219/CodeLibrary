#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
using namespace std;


int main()
{
    //freopen("1.txt","r",stdin);
    int n;scanf("%d",&n);
    if(n<=3)puts("NO");
    else
    {
        if(n%2==0)
        {
            puts("YES");
            puts("1 * 2 = 2");
            puts("3 * 4 = 12");
            puts("2 * 12 = 24");
            for(int i=5;i<n;i+=2)
            {
                printf("%d - %d = 1\n",i+1,i);
                printf("%d * 24 = 24\n",1);
            }
        }
        else
        {
            puts("YES");
            puts("5 * 4 = 20");
            puts("3 - 1 = 2");
            puts("20 + 2 = 22");
            puts("22 + 2 = 24");
            for(int i=6;i<n;i+=2)
            {
                printf("%d - %d = 1\n",i+1,i);
                printf("%d * 24 = 24\n",1);
            }
        }
    }
    return 0;
}
