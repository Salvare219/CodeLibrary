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
    long long k,l;
    scanf("%I64d%I64d",&k,&l);
    int c=0;
    long long s=k;
    while(s<l)
    {
        s*=k;
        c++;
    }
    if(s==l) printf("YES\n%d\n",c);
    else printf("NO\n");
    return 0;
}
