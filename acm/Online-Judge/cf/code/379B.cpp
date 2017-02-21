#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
//    freopen("1.txt","r",stdin);
    int n,ti=0;
    int a[400];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",a+i),ti=max(ti,a[i]);
    for(int i=0;i<ti;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[j])
            {
                a[j]--;
                putchar('P');
            }
            if(j!=n-1) putchar('R');
        }
        for(int j=1;j<n;j++)
            putchar('L');
    }
    putchar(10);
    return 0;
}
