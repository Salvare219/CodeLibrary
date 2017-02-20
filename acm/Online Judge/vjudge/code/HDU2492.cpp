#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<queue>
using namespace std;


int bit[2][100050];
int num[20050];
int query(int x,int w)
{
    int s=0;
    while(x)
    {
        s+=bit[w][x];
        x-=x&-x;
    }
    return s;
}
void updat(int x,int v,int w)
{
    while(x<100005)
    {
        bit[w][x]+=v;
        x+=x&-x;
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        memset(bit,0,sizeof(bit));
        for(int i=0;i<n;i++)
            scanf("%d",num+i),updat(100001-num[i],1,1);
        updat(num[0],1,0);
        updat(100001-num[0],-1,1);
        long long sum=0;
        for(int i=1;i<n-1;i++)
        {
            updat(100001-num[i],-1,1);
            sum+=(long long)query(num[i],0)*query(100001-num[i],1);
            updat(num[i],1,0);
        }
        memset(bit,0,sizeof(bit));
        for(int i=(n-1)/2;i>-1;i--)
            swap(num[i],num[n-i-1]);
        for(int i=0;i<n;i++)
            updat(100001-num[i],1,1);
        updat(num[0],1,0);
        updat(100001-num[0],-1,1);
        for(int i=1;i<n;i++)
        {
            updat(100001-num[i],-1,1);
            sum+=(long long)query(num[i],0)*query(100001-num[i],1);
            updat(num[i],1,0);
        }
        printf("%I64d\n",sum);
    }
    return 0;
}
