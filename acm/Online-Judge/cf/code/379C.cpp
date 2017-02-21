#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

struct p
{
    int i,x;
    bool operator<(p a)const{return x<a.x;}
}a[400000];
bool cmp(p a,p b)
{
    return a.i<b.i;
}
int main()
{
//    freopen("1.txt","r",stdin);
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i].x),a[i].i=i;
    sort(a,a+n);a[n].x=-1;
    int sta=1,i=0;
    while(i<n)
    {
        int s=i;
        sta=max(sta,a[i].x);
        for(;a[i].x==a[i+1].x;i++)
            a[i].x=sta++;
        a[i++].x=sta++;
    }
    sort(a,a+n,cmp);
    for(int i=0;i<n;i++)
        printf("%d ",a[i].x);
    return 0;
}
