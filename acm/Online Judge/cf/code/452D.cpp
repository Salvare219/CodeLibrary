#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

int a[1050];
int b[1050];
int c[1050];
bool cmp(const int &a,const int &b)
{
    return a>b;
}
int main()
{
    //freopen("1.txt","r",stdin);
    int k,n1,n2,n3,t1,t2,t3;
    scanf("%d%d%d%d%d%d%d",&k,&n1,&n2,&n3,&t1,&t2,&t3);
    for(int i=0;i<k;i++)
    {
        int t=c[0];
        t=max(t-t2,b[0]);
        t=max(t-t1,a[0]);
        pop_heap(a,a+n1,cmp);
        pop_heap(b,b+n2,cmp);
        pop_heap(c,c+n3,cmp);
        a[n1-1]=t+t1;
        b[n2-1]=t+t1+t2;
        c[n3-1]=t+t1+t2+t3;
        push_heap(a,a+n1,cmp);
        push_heap(b,b+n2,cmp);
        push_heap(c,c+n3,cmp);
    }
    int ans=0;
    for(int i=0;i<n1;i++)
        ans=max(ans,a[i]);
    for(int i=0;i<n2;i++)
        ans=max(ans,b[i]);
    for(int i=0;i<n3;i++)
        ans=max(ans,c[i]);
    printf("%d\n",ans);
}


