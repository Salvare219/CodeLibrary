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


int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        if(n==1) printf("1 1\n");
        else
        {
            int a,b;
            for(int i=1;;i++)
            {
                if((long long)(i+i+2*(n-1))*(2*(n-1)+2)==(long long)(2*(n-1)+2)*(2*(n-1)+2)*(2*(n-1)+2)/2)
                {
                    a=i;b=i+2*(n-1);
                    break;
                }
            }
            printf("%d %d\n",a,b);
        }
    }
    return 0;
}
