#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

int prim[200];
bool v[1005],a[105][105];
int Gauss(int equ,int var)
{
    int i,j,k,max_r,col=0;
    for(k=0;k<equ && col<var;k++,col++)
    {
        max_r=k;
        for(i=k+1;i<equ;i++)
            if(a[i][col]) max_r=i;
        if(max_r!=k)for(j=k;j<var+1;j++)swap(a[k][j],a[max_r][j]);
        if(a[k][col]==0){k--;continue;}
        for(i=k+1;i<equ;i++)
            if(a[i][col])
                for(j=col;j<var+1;j++)
                    a[i][j]^=a[k][j];
    }
    return var-k;
}
char ans[105],len=1;
int main()
{
    int t,m,k=0,x;scanf("%d%d",&t,&m);
    for(int i=2;i<1001;i++)
    {
        if(v[i]==0)prim[k++]=i;
        for(int j=0;j<k&&i*prim[j]<1001;j++)
        {
            v[prim[j]*i]=1;
            if(i%prim[j]==0)break;
        }
    }
    for(int i=0;i<m;i++)
    {
        scanf("%d",&x);
        for(int j=0;j<t;j++)
            while(x%prim[j]==0)x/=prim[j],a[j][i]^=1;
    }
    int d=Gauss(t,m);ans[0]=1;
    while(d--)
    {
        for(int i=x=0;i<len;i++)
            ans[i]<<=1,ans[i]+=x,ans[i]<10?x=0:(x=1,ans[i]-=10);
        if(x)ans[len++]=x;
    }
    ans[0]--;
    for(int i=len-1;i>-1;i--)putchar(ans[i]+'0');
    putchar(10);
    return 0;
}
