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
    int n;
    long long x,y;
    scanf("%d%I64d%I64d",&n,&y,&x);
    if(n>x) printf("-1\n");
    else
    {
        if((x-n+1)*(x-n+1)+n-1<y) printf("-1\n");
        else
        {
            printf("%d\n",x-n+1);
            for(int i=1;i<n;i++)
                printf("1\n");
        }
    }
    return 0;
}