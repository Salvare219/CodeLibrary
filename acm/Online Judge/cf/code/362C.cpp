#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


int a[7000];
int bit[7000];
void updat(int x)
{
    while(x<6000) bit[x]++,x+=x&-x;
}
int query(int x)
{
    int s=0;
    while(x) s+=bit[x],x-=x&-x;
    return s;
}
int main()
{
 //   freopen("1.txt","r",stdin);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",a+i),a[i]++;
    int ans=0,mx=-0x3fffffff,how=0;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if(a[i]>a[j]) ans++;
    for(int i=0;i<n;i++)
    {
        memset(bit,0,sizeof(bit));
        int sa,te;
        for(int j=i+1;j<n;j++)
        {
            sa=0;
            if(a[i]>a[j]) sa++;
            else sa--;
            sa+=(j-i-1)-2*query(a[j]);
            sa+=2*query(a[i])-(j-i-1);
            if(mx<sa)
            {
                mx=sa;
                how=1;
            }
            else if(mx==sa) how++;
            updat(a[j]);
        }
    }
    printf("%d %d\n",ans-mx,how);
    return 0;
}
