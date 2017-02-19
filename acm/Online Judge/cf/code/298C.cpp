#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;


char a[1005],b[1005];
int main()
{
//    freopen("1.txt","r",stdin);
    scanf("%s%s",a,b);
    int n1=0,n2=0;
    for(int i=0;a[i];i++)
        if(a[i]=='1') n1++;
    for(int i=0;b[i];i++)
        if(b[i]=='1') n2++;
    n1=n1+n1%2;
    if(n1>=n2) printf("YES\n");
    else printf("NO\n");
    return 0;
}





























