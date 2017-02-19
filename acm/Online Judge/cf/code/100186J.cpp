#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


int d[100050];
int e[100050];
int z[300050];
bool v[100050];
const int c=700;
int main()
{
    //freopen("1.txt","r",stdin);
    freopen("input.txt","r", stdin);
    freopen("output.txt", "w", stdout);
    int n,m;scanf("%d%d",&n,&m);
    int f=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",d+i);
    }
    sort(d,d+n);
    n=unique(d,d+n)-d;
    for(int i=0;i<n;i++)
    {
        e[i]=m/d[i]*d[i];
        for(int a=-1;a<=1;a++)
            if(e[i]+a>=1&&e[i]+a<=m)
                z[f++]=e[i]+a;
    }
    sort(z,z+f);
    f=unique(z,z+f)-z;
    int sum=0,dd;
    dd=min(c,f);
    for(int i=0;i<dd;i++)
    {
        int t=z[f-i-1];
        memset(v,0,sizeof(v));
        int now=t;
        for(int j=0;j<n;j++)
        {
            int a=now/d[j],b=(now+d[j]-1)/d[j];
            v[a]=v[b]=1;
        }
        int ans=0;
        for(int i=0;i<=m;i++)
            ans+=v[i];
        sum=max(ans,sum);
    }
    printf("%d\n",sum);
    return 0;
}
