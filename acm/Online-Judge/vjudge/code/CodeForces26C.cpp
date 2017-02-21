#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

char maz[200][200];
void pus(int n,int m,int a,int b,int c)
{
    for(int i=0;i<n+5;i++)
        for(int j=0;j<m+5;j++)
            maz[i][j]=(i+j)%26+'a';
    int x=0,y=0;
    for(int i=0;i<c;i++)
    {
        maz[x][y+1]=maz[x+1][y]=maz[x+1][y+1]=maz[x][y];
        y+=2;
        if(y>=m)y=0,x+=2;
        if(x>=n)return;
    }
    for(int i=0;i<a/2;i++)
    {
        maz[x][y+1]=maz[x][y];
        maz[x+1][y+1]=maz[x+1][y];
        y+=2;
        if(y>=m)y=0,x+=2;
        if(x>=n)return;
    }
    for(int i=0;i<b/2;i++)
    {
        maz[x+1][y]=maz[x][y];
        maz[x+1][y+1]=maz[x][y+1];
        y+=2;
        if(y>=m)y=0,x+=2;
        if(x>=n)return;
    }
}
int main()
{
    int n,m,a,b,c;
    scanf("%d%d%d%d%d",&n,&m,&a,&b,&c);
    int aa=0,bb=0,cc=0;
    if(n%2)aa=m/2;
    if(m%2)bb=n/2;
    if(n%2&&m%2)puts("IMPOSSIBLE");
    else
    {
        cc=((n/2))*((m/2));
        if(n%2)
        {
            if(aa>a)puts("IMPOSSIBLE");
            else
            {
                n--;a-=aa;
                if(cc>c+(a/2)+(b/2))puts("IMPOSSIBLE");
                else
                {
                    pus(n,m,a,b,c);
                    for(int i=0;i<m;i+=2)
                        maz[n][i+1]=maz[n][i];
                    for(int i=0;i<n+1;i++,putchar(10))
                        for(int j=0;j<m;j++)
                            putchar(maz[i][j]);
                    putchar(10);
                }
            }
        }
        else if(m%2)
        {
            if(bb>b)puts("IMPOSSIBLE");
            else
            {
                m--;b-=bb;
                if(cc>c+(a/2)+(b/2))puts("IMPOSSIBLE");
                else
                {
                    pus(n,m,a,b,c);
                    for(int i=0;i<n;i+=2)
                        maz[i+1][m]=maz[i][m];
                    for(int i=0;i<n;i++,putchar(10))
                        for(int j=0;j<m+1;j++)
                            putchar(maz[i][j]);
                    putchar(10);
                }
            }
        }
        else
        {
            if(cc>c+(a/2)+(b/2))puts("IMPOSSIBLE");
            else
            {
                pus(n,m,a,b,c);
                for(int i=0;i<n;i++,putchar(10))
                    for(int j=0;j<m;j++)
                        putchar(maz[i][j]);
                putchar(10);
            }
        }
    }
    return 0;
}
