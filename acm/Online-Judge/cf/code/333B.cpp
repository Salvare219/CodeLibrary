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


bool x[2005],y[2005];
int main()
{
 //   freopen("1.txt","r",stdin);
    int n,m;
    scanf("%d%d",&n,&m);
    int a,b;
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&a,&b);
        a--;b--;
        x[a]=1;y[b]=1;
    }
    n-=2;
    int con=0;
    for(int i=1;i<=n;i++)
        if(x[i]==0) con++;
    for(int i=1;i<=n;i++)
        if(y[i]==0) con++;
    if(n%2 && x[n/2+1]==0 && y[n/2+1]==0)  con--;
    printf("%d\n",con);
    return 0;
}
