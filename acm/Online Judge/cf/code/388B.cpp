#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

bool mat[1005][1005];
vector<int>gra[2005];
int wei[2005];
inline void add(int x,int y)
{
    gra[x].push_back(y);
    gra[y].push_back(x);
}
int main()
{
//    freopen("1.txt","r",stdin);
    long long n;scanf("%I64d",&n);
    long long temp=2;
    int cnt=2;
    int lx=cnt,ly=cnt+1;cnt+=2;
    wei[33]=cnt;
    add(cnt,lx);
    add(cnt++,ly);
    for(int j=0;j<32;j++)
    {
        add(lx,cnt);
        add(ly,cnt++);
        add(lx,cnt);
        add(ly,cnt++);
        lx=cnt-2;ly=cnt-1;
        add(cnt,lx);
        add(cnt,ly);
        wei[32-j]=cnt++;
    }
    add(lx,1);add(ly,1);
    wei[0]=cnt;
    for(int i=0;i<35;i++)
        add(cnt,cnt+1),cnt++;
    add(cnt++,1);
    if(n&1)add(0,wei[0]);
    for(int i=1;i<=33;i++)
    {
        if(n&temp)
        {
            add(0,cnt);
            for(int j=0;j<34-i;j++)
                add(cnt,cnt+1),cnt++;
            add(cnt++,wei[i]);
        }
        temp<<=1;
    }
    for(int i=0;i<cnt;i++)
        for(int j=0;j<gra[i].size();j++)
            mat[i][gra[i][j]]=1;
    printf("%d\n",cnt);
    for(int i=0;i<cnt;i++,putchar(10))
        for(int j=0;j<cnt;j++)
            putchar(mat[i][j]?'Y':'N');
    return 0;
}
