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
    int n,m;
    while(scanf("%d%d",&n,&m))
    {
        if(n==0) break;
        if((n&1) && (m&1)) printf("What a pity!\n");
        else printf("Wonderful!\n");
    }
    return 0;
}