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
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=k;i++)
        printf("%d ",n-i+1);
    for(int i=k;i<n;i++)
        printf("%d ",i-k+1);
    return 0;
}





























