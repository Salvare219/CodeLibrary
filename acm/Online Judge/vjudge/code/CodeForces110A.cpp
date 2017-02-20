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
    long long n;
    scanf("%I64d",&n);
    bool f=1;
    long long m=n;
    n=0;
    while(m)
    {
        int c=m%10;
        if(c==4 || c==7) n++;
        m/=10;
    }
    if(n==0)
    {
        puts("NO");
        return 0;
    }
    while(n)
    {
        int c=n%10;
        if(c==4 || c==7) ;
        else f=0;
        n/=10;
    }
    if(f) puts("YES");
    else puts("NO");
    return 0;
}
