#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;



int main()
{
 //   freopen("1.txt","r",stdin);
    int n;
    while(scanf("%d",&n)==1)
    {
        n%=3;
        if(n) printf("Kiki\n");
        else printf("Cici\n");
    }
    return 0;
}
