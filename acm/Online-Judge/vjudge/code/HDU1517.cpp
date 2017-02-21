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
    unsigned long long n;
    while(scanf("%llu",&n)==1)
    {
        bool flag=1;
        while(1)
        {
            n=(n+8)/9;
            if(n<=1) break;
            n=(n+1)/2;
            if(n<=1)
            {
                flag=0;
                break;
            }
        }
        if(flag) printf("Stan wins.\n");
        else printf("Ollie wins.\n");
    }
    return 0;
}
