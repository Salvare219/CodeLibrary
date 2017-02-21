#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

int bit[5055][5055];
void updat(int k,int x,int v)
{
    while(x<5001) bit[k][x]=max(bit[k][x],v),x+=x&-x;
}
int query(int k,int x)
{
    int s=0;
    while(x) s=max(s,bit[k][x]),x-=x&-x;
    return s;
}
int n,m;
char ss[50000];
int fu[50000];
int main()
{
//    freopen("1.txt","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",ss);
        int las=1;
        for(int j=1;j<=m;j++)
            if(ss[j-1]=='0')
                updat(i,las,j-1),las=m;
            else
                las=min(las,j);
        if(ss[m-1]=='1') updat(i,las,m);
    }
    int ans=0,cnt=0;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
            fu[j]=max(0,query(j,i)-i+1);
        sort(fu+1,fu+n+1);
        for(int i=1;i<=n;i++)
            ans=max(ans,i*fu[n-i+1]);
    }
    printf("%d\n",ans);
    return 0;
}
