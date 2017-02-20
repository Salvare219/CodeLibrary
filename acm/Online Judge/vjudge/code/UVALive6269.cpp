#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

bool gra[20][20];
int ok[20][20];
int ba[20][20];
int nk[4],nb[4];
int wei[10];
int ti[100][4];
void add(int x,int y)
{
    ok[x][y]=wei[x]&wei[y];
    ba[x][y]=wei[x]^wei[y];
    gra[x][y]=1;
}
int main()
{

    wei[0]=1+2+16+64+4+32;wei[1]=2+16;
    wei[2]=1+2+8+32+64;wei[3]=2+16+1+8+64;
    wei[4]=2+16+4+8;wei[5]=1+4+8+16+64;
    wei[6]=1+4+8+16+64+32;wei[7]=1+2+16;
    wei[8]=1+2+4+8+16+32+64;wei[9]=1+2+4+8+16+64;

    add(0,0);add(0,1);add(0,7);
    add(1,1);add(2,2);add(3,1);
    add(3,3);add(3,7);add(4,1);
    add(4,4);add(5,5);add(6,5);
    add(6,6);add(7,1);add(7,7);
    add(9,1);add(9,3);add(9,4);
    add(9,5);add(9,7);add(9,9);
    for(int i=0;i<10;i++)add(8,i);
    int n;
    while(~scanf("%d",&n))
    {
        int x,y;
        for(int i=0;i<n;i++)
        {
            scanf("%d:%d",&x,&y);
            ti[i][0]=x/10;
            ti[i][1]=x%10;
            ti[i][2]=y/10;
            ti[i][3]=y%10;
        }
        bool f=1;
        for(int i=0;i<24;i++)
            for(int j=0;j<60;j++)
            {
                int x=i,y=j;
                bool ca=1;
                memset(nk,0,sizeof(nb));
                memset(nb,0,sizeof(nb));
                for(int k=0;k<n;k++)
                {
                    if(gra[x/10][ti[k][0]]&&gra[x%10][ti[k][1]]&&gra[y/10][ti[k][2]]&&gra[y%10][ti[k][3]])
                    {
                        nk[0]|=ok[x/10][ti[k][0]];
                        nk[1]|=ok[x%10][ti[k][1]];
                        nk[2]|=ok[y/10][ti[k][2]];
                        nk[3]|=ok[y%10][ti[k][3]];
                        nb[0]|=ba[x/10][ti[k][0]];
                        nb[1]|=ba[x%10][ti[k][1]];
                        nb[2]|=ba[y/10][ti[k][2]];
                        nb[3]|=ba[y%10][ti[k][3]];
                    }
                    else
                    {
                        ca=0;
                        break;
                    }
                    y++;
                    if(y>=60)y=0,x++;
                    if(x>=24)x=0;
                }
                for(int k=0;k<4;k++)
                {
                    if(nb[k]&nk[k])ca=0;
                }
                if(ca)
                {
                    if(f)printf("%02d:%02d",i,j);
                    else printf(" %02d:%02d",i,j);
                    f=0;
                }
            }
        if(f)puts("none");
        else putchar(10);
    }
    return 0;
}
