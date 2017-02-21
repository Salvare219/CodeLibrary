#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<queue>
using namespace std;


int m[4][4]={0,0,0,0,0,1,2,3,0,2,3,1,0,3,1,2};
int nim_multy_pow(int x,int y)
{
    if(x<4) return m[x][y];
    int m=1;
    while((1<<m)<=x) m<<=1;
    m=1<<(m>>1);
    int d=nim_multy_pow(x/m,y/m);
    return (m*(d^nim_multy_pow(x/m,y%m)))^nim_multy_pow(m>>1,d);
}
int nim_multy(int x,int y)
{
    if(x<y) swap(x,y);
    if(x<4) return m[x][y];
    int m=1;
    while((1<<m)<=x) m<<=1;
    m=1<<(m>>1);
    int c=nim_multy(x/m,y/m);
    return m*(c^nim_multy(x/m,y%m)^nim_multy(x%m,y/m))^nim_multy(x%m,y%m)^nim_multy_pow(m>>1,c);
}
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        int x,y,z,sum=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d%d%d",&x,&y,&z);
            sum^=nim_multy(x,nim_multy(y,z));
        }
        if(sum) printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}
