#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


int main()
{
//    freopen("1.txt","r",stdin);
    int n,k;
    scanf("%d%d",&n,&k);
    int now=1;
    for(int i=0;i<k;i++)
        printf("%d %d ",now,now+1),now+=2;
    for(int i=k;i<n;i++)
        printf("%d %d ",now+1,now),now+=2;
    putchar(10);
    return 0;
}
