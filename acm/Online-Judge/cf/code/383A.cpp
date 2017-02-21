#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

int bit[200050];
int n;
void updat(int x,int v)
{
    while(x<=n) bit[x]+=v,x+=x&-x;
}
int query(int x)
{
    int s=0;
    while(x) s+=bit[x],x-=x&-x;
    return s;
}
int main()
{
//    freopen("1.txt","r",stdin);
    scanf("%d",&n);int x;
    long long ans=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        if(x)updat(i+1,1);
        else ans+=query(i+1);
    }
    printf("%I64d\n",ans);
    return 0;
}

