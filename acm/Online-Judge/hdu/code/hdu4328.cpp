#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


int n,m;
char s[1005];
bool maz[1005][1005];
int H[1005][1005];
int L[1005][1005];
int R[1005][1005];
int cal(int a)
{
    for(int i=0;i<n;i++)
    {
        int x=-1;
        for(int j=0;j<m;j++)
        {
            if(maz[i][j]==a)x=j;
            L[i][j]=x;
        }
        x=m;
        for(int j=m-1;j>-1;j--)
        {
            if(maz[i][j]==a)x=j;
            R[i][j]=x;
        }
    }
    int ans=0;
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            if(maz[j][i]!=a)
            {
                H[j][i]=j?H[j-1][i]:-1;
                if(j&&maz[j-1][i]!=a)
                {
                    L[j][i]=max(L[j][i],L[j-1][i]);
                    R[j][i]=min(R[j][i],R[j-1][i]);
                }
                ans=max(ans,(j-H[j][i])+(R[j][i]-L[j][i]-1));
            }
            else H[j][i]=j;
    return 2*ans;
}
int main()
{
    int t,ti=1;scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
        {
            scanf("%s",s);
            for(int j=0;j<m;j++)
                maz[i][j]=s[j]=='B';
        }
        int ans=0;
        ans=max(ans,cal(0));
        ans=max(ans,cal(1));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if((i+j)&1)maz[i][j]^=1;
        ans=max(ans,cal(0));
        ans=max(ans,cal(1));
        printf("Case #%d: %d\n",ti++,ans);
    }
    return 0;
}
