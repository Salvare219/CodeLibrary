#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

char maz[2005][2005];
int n,m;
int cal(int c)
{
    int cnt=0;
    for(int i=1;i<n;i++)
    {
        if(i+i<n&&maz[i+i][c]=='U')cnt++;
        if(c-i>=0&&maz[i][c-i]=='R')cnt++;
        if(c+i<m&&maz[i][c+i]=='L')cnt++;
    }
    return cnt;
}
int main()
{
    //freopen("1.txt","r",stdin);
    int k;scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;i++)
        scanf("%s",maz[i]);
    for(int i=0;i<m;i++)
        printf("%d ",cal(i));
    return 0;
}
