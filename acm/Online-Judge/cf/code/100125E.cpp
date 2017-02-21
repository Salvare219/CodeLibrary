#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

int a[100050],b[100050];
int main()
{
    //freopen("1.txt","r",stdin);
    freopen("electricity.in","r",stdin);
    freopen("electricity.out","w",stdout);
    int n,m;scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%d",a+i);
    for(int i=0;i<m;i++)
        scanf("%d",b+i);
    sort(a,a+n);
    sort(b,b+m);
    int p=m-1,sum=1;
    for(int i=n-1;i>-1;i--)
    {
        int c=a[i];
        while(0<=p&&c)
        {
            sum+=b[p];
            c--;
            p--;
        }
        sum--;
        if(p==-1)break;
    }
    printf("%d\n",sum);
    return 0;
}

