#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

int a[500050];
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
//    freopen("1.txt","r",stdin);
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",a+i);
    sort(a,a+n,cmp);
    int p=n/2,tot=n;
    for(int i=0;i<n/2;i++)
    {
        while(p<n&&a[i]<a[p]*2)
            p++;
        if(p<n)tot--;
        p++;
    }
    printf("%d\n",tot);
    return 0;
}
