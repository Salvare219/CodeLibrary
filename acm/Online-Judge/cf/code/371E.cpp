#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

struct p
{
    long long x;
    int i;
}l[400050];
long long pre[400050],ppre[400050];
bool cmp(struct p a,struct p b)
{return a.x>b.x;}
bool cmp1(struct p a,struct p b)
{return a.x<b.x;}
int main()
{
//    freopen("1.txt","r",stdin);
    int n,k;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%I64d",&l[i].x),l[i].i=i;
    scanf("%d",&k);
    sort(l,l+n,cmp1);
    long long sum=l[0].x;
    for(int i=1;i<k;i++)
    {
        pre[i]=pre[i-1]+i*l[i].x-sum;
        sum+=l[i].x;
    }
    for(int i=k;i<n;i++)
    {
        sum-=l[i-k].x;
        pre[i]=pre[i-1]+(k-1)*l[i].x-2*sum+(k-1)*l[i-k].x;
        sum+=l[i].x;
    }
    long long ans=pre[k-1];
    int f=0;
    for(int i=k;i<n;i++)
        if(ans>pre[i])
        {
            ans=pre[i];
            f=i-k+1;
        }

    for(int i=0;i<k;i++)
        printf("%d ",l[f+i].i+1);
    return 0;
}
