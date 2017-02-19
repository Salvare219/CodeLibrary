#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
using namespace std;


void pri(int x)
{
    if(x!=0)
    {
        printf("(A%d|B%d)|(((A%d|A%d)|(B%d|B%d))|(",x,x,x,x,x,x);
        pri(x-1);
        printf("))");
    }
    else printf("(A%d|B%d)|(A%d|B%d)",x,x,x,x);
}
int main()
{
    //freopen("1.txt","r",stdin);
    //freopen("2.txt","w",stdout);
    int n;scanf("%d",&n);
    putchar('(');
    pri(n-1);
    putchar(')');
    putchar(10);
    return 0;
}
