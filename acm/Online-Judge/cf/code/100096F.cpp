#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


int a[600];
bool v[600];
const int P=13131;
unsigned long long pow_mod(unsigned long long a,int b)
{
    unsigned long long c=1;
    while(b)
    {
        if(b&1)c=c*a;
        b>>=1;
        a=a*a;
    }
    return c;
}
#include<set>
set<unsigned long long>s;
int main()
{
    freopen("numbereater.in","r",stdin);
    freopen("numbereater.out","w",stdout);
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",a+i);
    for(int i=0;i<n;i++)
    {
        memset(v,0,sizeof(v));
        unsigned long long ans=0;
        for(int j=i;j<n;j++)
        {
            if(v[a[j]]==0)
            {
                v[a[j]]=1;
                ans+=pow_mod(P,a[j]);
                s.insert(ans);
            }
        }
    }
    printf("%d\n",(int)s.size());
    return 0;
}
