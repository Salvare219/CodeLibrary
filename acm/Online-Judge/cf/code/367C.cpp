#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

int q[100050];
int po(int x)
{
    if(x&1)return x*(x-1)/2+1;
    else return (x-1)*x/2+x/2;
}
int main()
{
 //   freopen("1.txt","r",stdin);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
        scanf("%*d%d",q+i);
    sort(q,q+m);
    int i;
    for(i=1;po(i)<=n;i++);
    i--;
    long long sum=0;
    for(int j=0;j<i&&m-1-j>=0;j++)
        sum+=q[m-1-j];
    printf("%I64d\n",sum);
    return 0;
}
