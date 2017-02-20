#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

int w[100050],l[100050],p[100050];
struct p
{
    int x,y;
    bool operator<(p a)const{return x>a.x;}
}st[100050];
int main()
{
    int t,ti=1;scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d%d%d",w+i,l+i,p+i);
        int k=0,sum=0,cos=0,ans=0x7fffffff;
        for(int i=n-1;i>-1;i--)
        {
            cos+=(st[k].y=p[i]);
            st[k++].x=l[i]+sum;
            push_heap(st,st+k);
            sum+=w[i];
            while(k&&st[0].x<sum)cos-=st[0].y,pop_heap(st,st+(k--));
            ans=min(ans,cos);
        }
        printf("Case %d: Need to use %d mana points.\n",ti++,ans);
    }
    return 0;
}
