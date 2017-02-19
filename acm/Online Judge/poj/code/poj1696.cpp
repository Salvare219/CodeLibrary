#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;


struct Point
{int x,y,i;}po[60];
int xmult(Point p0,Point p1,Point p2)
{return (p1.x-p0.x)*(p2.y-p0.y)-(p1.y-p0.y)*(p2.x-p0.x);}
int sdis(Point a,Point b)
{return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);}
int temp;
bool cmp(Point a,Point b)
{
    temp=xmult(po[0],a,b);
    if(temp>0 || (temp==0 && sdis(po[0],a)>sdis(po[0],b))) return 1;
    else return 0;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d%d%d",&po[i].i,&po[i].x,&po[i].y);
            if(po[0].y>po[i].y || (po[0].y==po[i].y && po[0].x>po[i].x)) swap(po[0],po[i]);
        }
        printf("%d",n);
        for(int i=0;i<n;i++)
        {
            printf(" %d",po[i].i);
            swap(po[0],po[i]);
            sort(po+i+1,po+n,cmp);
        }
        putchar(10);
    }
    return 0;
}
