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


int num[100005][2];
int index[100005],ans[100005];
int bit[131075];
int n;
bool cmp(int a,int b)
{
    if(num[a][0]==num[b][0]) return num[a][1]>num[b][1];
    return num[a][0]<num[b][0];
}
void updat(int x,int v)
{
    while(x<131074)
    {
        bit[x]+=v;
        x+=x&-x;
    }
}
int query(int x)
{
    int s=0;
    while(x)
    {
        s+=bit[x];
        x-=x&-x;
    }
    return bit[131072]-s;
}
int main()
{
    while(scanf("%d",&n))
    {
        if(n==0) break;
        memset(bit,0,sizeof(bit));
        for(int i=0;i<n;i++)
            scanf("%d%d",&num[i][0],&num[i][1]),index[i]=i;
        sort(index,index+n,cmp);
        for(int i=0;i<n;i++)
        {
            if(i && num[index[i]][0]==num[index[i-1]][0] && num[index[i]][1]==num[index[i-1]][1])
                ans[index[i]]=ans[index[i-1]];
            else ans[index[i]]=query(num[index[i]][1]);
            updat(num[index[i]][1]+1,1);
        }
        for(int i=0;i<n;i++)
            if(i) printf(" %d",ans[i]);
            else printf("%d",ans[0]);
        putchar(10);
    }
    return 0;
}
