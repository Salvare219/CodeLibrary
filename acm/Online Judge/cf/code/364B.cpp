#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

#include<queue>
int a[60];
bool v[500006];
int main()
{
//    freopen("1.txt","r",stdin);
    int n,d;
    scanf("%d%d",&n,&d);
    for(int i=0;i<n;i++) scanf("%d",a+i);
    sort(a,a+n);
    int sum=0,f=0;
    for(int i=0;i<n;i++) if(sum+d>=a[i]) sum+=a[i],f=i;
    f++;v[0]=1;
    for(int i=0;i<n;i++)
        for(int j=sum;j>-1;j--)
            if(v[j]) v[j+a[i]]=1;
    int now=0,p=0,to=0,ans=0;
    while(now<sum)
    {
        while(p<=now+d)
        {
            if(v[p]) to=p;
            p++;
        }
        now=to;ans++;
    }
    printf("%d %d\n",sum,ans);
    return 0;
}
