#include<bits/stdc++.h>
using namespace std;


bool v[200000050];
char cg[5][2][20];
int main()
{
    freopen("beavers.in","r",stdin);
    freopen("beavers.out","w",stdout);
    for(int i=0;i<5;i++)
        for(int j=0;j<2;j++)
            scanf("%s",cg[i][j]);
    int now=100000005,st=0;
    for(int i=0;i<100000000;i++)
    {
        int x=st,y=v[now];
        v[now]=cg[x][y][0]-'0';
        if(cg[x][y][1]=='L')now--;
        else now++;
        if(cg[x][y][2]=='H')
        {
            puts("happy beaver");
            return 0;
        }
        st=cg[x][y][2]-'A';
    }
    puts("unhappy beaver");
    return 0;
}
