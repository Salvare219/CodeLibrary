#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


char maz[20][20];
int a[4][4]={
1,2,5,6,
3,4,7,8,
15,16,11,12,
17,18,13,14};
int main()
{
 //   freopen("1.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(maz,0,sizeof(maz));
        int as[2],k=0;
        for(int i=0;i<8;i++)
            scanf("%s",maz[i]);
        int x,y;
        for(int i=0;i<8;i++)
            for(int j=0;j<8;j++)
                if(maz[i][j]=='K') as[k++]=a[i%4][j%4];
        if(as[0]==as[1])
        {
            bool f=0;
            for(int i=0;i<8;i++)
                for(int j=0;j<8;j++)
                {
                    x=i%4;y=j%4;
                    if(a[x][y]%10==as[0]%10)
                        if(maz[i][j]!='#') f=1;
                }
            puts(f?"YES":"NO");

        }
        else puts("NO");
    }
    return 0;
}
