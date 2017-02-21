#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

char s[10000];
bool v[5000];
void r1(int &x,int &y,int t,int n,int m)
{
    int x1,y1;
    if(t==0);
    else if(t==1)
    {
        x1=y;
        y1=(n-1)-x;
        x=x1;y=y1;
    }
    else if(t==2)
    {
        x1=y;
        y1=(n-1)-x;
        x=x1;y=y1;
        swap(n,m);
        x1=y;
        y1=(n-1)-x;
        x=x1;y=y1;
    }
    else
    {
        x1=y;
        y1=(n-1)-x;
        x=x1;y=y1;
        swap(n,m);
        x1=y;
        y1=(n-1)-x;
        x=x1;y=y1;
        swap(n,m);
        x1=y;
        y1=(n-1)-x;
        x=x1;y=y1;
    }
}
void r2(int &x,int &y,int t,int n,int m)
{
    if(t==1)y=(m-1)-y;
}
int main()
{
//    freopen("1.txt","r",stdin);
    int n,m,x,y,z,p;scanf("%d%d%d%d%d%d",&n,&m,&x,&y,&z,&p);
    x%=4;y%=2;z%=4;
    while(p--)
    {
        int x1,y1,nn=n,mm=m;
        scanf("%d%d",&x1,&y1);x1--;y1--;
        r1(x1,y1,x,nn,mm);
        if(x%2)swap(nn,mm);
        r2(x1,y1,y,nn,mm);
        r1(x1,y1,(4-z)%4,nn,mm);
        x1++;y1++;
        printf("%d %d\n",x1,y1);
    }
    return 0;
}
