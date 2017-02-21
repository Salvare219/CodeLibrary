#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


int a[10000];
int main()
{
//    freopen("1.txt","r",stdin);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
        scanf("%d",a+i);sort(a,a+m);
    bool fl=1;
    if(a[0]==1 || a[m-1]==n) fl=0;
    for(int i=2;i<m;i++)
        if(a[i]==a[i-1]+1 && a[i]==a[i-2]+2) fl=0;
    puts(fl?"YES":"NO");
    return 0;
}
