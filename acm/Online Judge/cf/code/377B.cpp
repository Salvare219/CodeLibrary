#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

/*
int main()
{
    freopen("2.txt","w",stdout);
    printf("100000 1000 50000000\n");
    for(int i=0;i<1000;i++)
        printf("%d ",rand());putchar(10);
    for(int i=0;i<100000;i++)
        printf("%d ",rand()+rand()+rand());putchar(10);
    for(int i=0;i<100000;i++)
        printf("%d ",rand());putchar(10);
    return 0;
}*/

int n,m,s;
struct p
{
    int le,i,j;
    bool operator<(p a)const{return a.le<le;}
}a[200000],b[200000],st[200000];
bool ok(int mid)
{
    int k=0,p=0;
    long long ans=0;
    if((m+mid-1)/mid>n)return 0;
    for(int i=0;i<m;i+=mid)
    {
        while(p<n&&b[p].le>=a[i].le)
        {
            st[k].le=b[p].i;
            st[k++].i=b[p++].j;
            push_heap(st,st+k);
        }
        ans+=st[0].le;a[i].j=st[0].i;
        if(k==0||ans>s)return 0;
        pop_heap(st,st+k);k--;
    }
    return 1;
}
int main()
{
//    freopen("2.txt","r",stdin);
    scanf("%d%d%d",&n,&m,&s);
    for(int i=0;i<m;i++)
        scanf("%d",&a[i].le),a[i].i=i;
    sort(a,a+m);
    for(int i=0;i<n;i++)
        scanf("%d",&b[i].le);
    for(int i=0;i<n;i++)
        scanf("%d",&b[i].i),b[i].j=i;
    sort(b,b+n);
    int l=1,r=m+1,mid;
    while(l<r)
    {
        mid=(l+r)>>1;
        if(ok(mid))r=mid;
        else l=mid+1;
    }
    if(r==m+1)puts("NO");
    else
    {
        puts("YES");
        ok(r);
        int las;
        for(int i=0;i<m;i++)
        {
            if(i%r==0)las=a[i].j;
            b[a[i].i].i=las;
        }
        for(int i=0;i<m;i++)
            printf("%d ",b[i].i+1);putchar(10);
    }
    return 0;
}
