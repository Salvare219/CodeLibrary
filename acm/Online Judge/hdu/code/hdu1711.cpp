#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;


int str[1000005],ori[10005];
int extend[1000005],nex[10005];
int n,m;
void extend_kmp()
{
    int i,j=-1,l,r;
    for(i=1;i<m;i++,j--)
    {
        if(j<0 || i+nex[i-l]>=r)
        {
            if(j<0) j=0,r=i;
            while(r<m && ori[j]==ori[r]) r++,j++;
            nex[i]=j;l=i;
        }
        else nex[i]=nex[i-l];
    }
    nex[0]=i;j=-1;
    for(i=0;i<n;i++,j--)
    {
        if(j<0 || i+nex[i-l]>=r)
        {
            if(j<0) j=0,r=i;
            while(r<n && j<m && ori[j]==str[r]) r++,j++;
            extend[i]=j;l=i;
        }
        else extend[i]=nex[i-l];
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
            scanf("%d",str+i);
        for(int i=0;i<m;i++)
            scanf("%d",ori+i);
        extend_kmp();
        int ans=-1;
        for(int i=0;i<n;i++)
            if(extend[i]>=m)
            {
                ans=i+1;
                break;
            }
        printf("%d\n",ans);
    }
    return 0;
}