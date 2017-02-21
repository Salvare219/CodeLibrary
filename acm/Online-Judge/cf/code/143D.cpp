#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


int main()
{
//    freopen("1.txt","r",stdin);
    int n,m;
    scanf("%d%d",&n,&m);
    if(n>m) swap(n,m);
    if(n>=3) printf("%d\n",(n*m+1)/2);
    else
    {
        if(n==2)
        {
            if(m>3) printf("%d\n",m/4*4+min(4,m%4*2));
            else printf("4\n");
        }
        else printf("%d\n",m);
    }
    return 0;
}


