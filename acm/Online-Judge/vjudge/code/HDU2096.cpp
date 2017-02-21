#include<cstdio>
using namespace std;

int main()
{
    int t,a,b;scanf("%d",&t);
    while(t--)scanf("%d%d",&a,&b),printf("%d\n",(0ll+a+b)%100);
    return 0;
}