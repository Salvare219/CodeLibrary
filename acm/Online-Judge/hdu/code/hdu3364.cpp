#include<cstdio>
#include<algorithm>
using namespace std;

int a[50][50];
int op[2000][2],sa;
bool o[2000];
int Gauss(int equ,int var)
{
    int i,j,k;
    int max_r;
    int col=0;
    for(k=0;k<equ && col<var;k++,col++)
    {
        max_r=k;
        for(i=k+1;i<equ;i++)
            if(a[i][col])
            {
                max_r=i;
                break;
            }
        if(max_r!=k)
        {
            op[sa][0]=max_r;op[sa][1]=k;
            o[sa++]=0;
            for(j=k;j<var;j++) swap(a[k][j],a[max_r][j]);
        }
        if(a[k][col]==0)
        {
            k--;
            continue;
        }
        for(i=k+1;i<equ;i++)
            if(a[i][col]!=0)
            {
                op[sa][0]=i;op[sa][1]=k;
                o[sa++]=1;
                for(j=col;j<var+1;j++)
                    a[i][j]^=a[k][j];
            }
    }
    return k;
}
int main()
{
    int t,ti=1;
    scanf("%d",&t);
    while(t--)
    {
        printf("Case %d:\n",ti++);
        int n,m,x,y,q;
        scanf("%d%d",&n,&m);
        memset(a,0,sizeof(a));
        for(int i=0;i<m;i++)
        {
            scanf("%d",&x);
            for(int j=0;j<x;j++)
                scanf("%d",&y),a[y-1][i]=1;
        }
        scanf("%d",&q);
        sa=0;
        int fa=Gauss(n,m);
        long long as=1ll<<(m-fa);
        while(q--)
        {
            for(int i=0;i<n;i++)
                scanf("%d",&a[i][m]);
            for(int i=0;i<sa;i++)
                if(o[i]) a[op[i][0]][m]^=a[op[i][1]][m];
                else swap(a[op[i][0]][m],a[op[i][1]][m]);
            int ans=0;
            for(int i=fa;i<n;i++)
                if(a[i][m]!=0)
                {
                    ans=-1;
                    break;
                }
            if(ans==-1) printf("0\n");
            else printf("%I64d\n",as);
        }
    }
    return 0;
}
