#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

char maz[555][555];
int main()
{
//    freopen("1.txt","r",stdin);
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%s",maz[i]);
    int a=0,b=0,c=maz[0][0],d=maz[0][1];
    for(int i=0;i<n;i++)
    {
        if(maz[i][i]==c)a++;
        if(maz[i][n-i-1]==c)a++;
        maz[i][i]=0;
        maz[i][n-i-1]=0;
    }
    a--;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(maz[i][j]==d)b++;
    if(c!=d)
    {
        if(a==n+n-1&&b==n*n-n-n+1)puts("YES");
        else puts("NO");
    }
    else puts("NO");
    return 0;
}
