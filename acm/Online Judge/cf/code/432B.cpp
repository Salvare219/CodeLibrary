#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int cnta[100050],cntb[100050];
int a[100050],b[100050];
int aa[100050],bb[100050];
int main()
{
 //   freopen("1.txt","r",stdin);
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        cnta[x]++;cntb[y]++;
        a[i]=x;b[i]=y;
    }
    for(int i=0;i<n;i++)
    {
        aa[i]+=n-1+cnta[b[i]];
        bb[i]+=n-1-cnta[b[i]];
    }
    for(int i=0;i<n;i++)
        printf("%d %d\n",aa[i],bb[i]);
    return 0;
}

