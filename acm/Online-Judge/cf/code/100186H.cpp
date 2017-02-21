#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


struct Point
{
    long long x,y;
    Point(long long a=0.0,long long b=0.0){x=a;y=b;}
    Point operator+(const Point&a)const{return Point(x+a.x,y+a.y);}
    Point operator-(const Point&a)const{return Point(x-a.x,y-a.y);}
    Point operator*(const long long&a)const{return Point(x*a,y*a);}
    Point operator/(const long long&a)const{return Point(x/a,y/a);}
    long long operator*(const Point&a)const{return x*a.y-y*a.x;}
    long long operator%(const Point&a)const{return x*a.x+y*a.y;}
};
char s[50][50];
inline bool cross(Point p0,Point p1,Point p2,Point p3) //判断线段p0p1,p2p3是否相交 端点相交不算
{
    return ((p1-p0)*(p2-p0))*((p1-p0)*(p3-p0))<0 && ((p3-p2)*(p0-p2))*((p3-p2)*(p1-p2))<0;
}
bool v[10][10];
int find(int x,int y,int x1,int y1)
{
    memset(v,0,sizeof(v));
    Point p1=Point(x,y),p2=Point(x1,y1);
    for(int i=1;i<=5;i++)
        for(int j=0;j<5;j++)
        {
            Point p3,p4;
            p3=Point(2*i,2*j);
            p4=Point(2*i,2*j+2);
            if(cross(p1,p2,p3,p4)==1)
                v[i][j]=1;
            p3=Point(2*i,2*j+2);
            p4=Point(2*i+2,2*j+2);
            if(cross(p1,p2,p3,p4)==1)
                v[i][j]=1;
            p3=Point(2*i+2,2*j+2);
            p4=Point(2*i+2,2*j);
            if(cross(p1,p2,p3,p4)==1)
                v[i][j]=1;
            p3=Point(2*i+2,2*j);
            p4=Point(2*i,2*j);
            if(cross(p1,p2,p3,p4)==1)
                v[i][j]=1;
            p3=Point(2*i,2*j);
            p4=Point(2*i+2,2*j+2);
            if(cross(p1,p2,p3,p4)==1)
                v[i][j]=1;
            p3=Point(2*i+2,2*j);
            p4=Point(2*i,2*j+2);
            if(cross(p1,p2,p3,p4)==1)
                v[i][j]=1;

            p3=Point(2*i+1,2*j);
            p4=Point(2*i+2,2*j+1);
            if(cross(p1,p2,p3,p4)==1)
                v[i][j]=1;
            p3=Point(2*i+2,2*j+1);
            p4=Point(2*i+1,2*j+2);
            if(cross(p1,p2,p3,p4)==1)
                v[i][j]=1;
            p3=Point(2*i+1,2*j+2);
            p4=Point(2*i,2*j+1);
            if(cross(p1,p2,p3,p4)==1)
                v[i][j]=1;
            p3=Point(2*i,2*j+1);
            p4=Point(2*i+1,2*j);
            if(cross(p1,p2,p3,p4)==1)
                v[i][j]=1;
        }
    int ans=0;
    for(int i=1;i<=5;i++)
        for(int j=0;j<5;j++)
            if(v[i][j]==1)
            {
                if(s[i][j]=='A')ans++;
                else if(s[i][j]=='P')return 0;
            }
    return ans;
}
int main()
{
    freopen("input.txt","r", stdin);
    freopen("output.txt", "w", stdout);
    for(int i=1;i<=5;i++)
        scanf("%s",s[i]);
    int ans=0;
    int a=0,b=0,c=-1,d=-1;
    for(int j=0;j<5;j++)
        for(int x=0;x<7;x++)
            for(int y=0;y<5;y++)
                if(s[x][y]=='A')
                {
                    if(c==-1)
                    {
                        c=x;
                        d=y;
                    }
                    int cnt=find(1,2*j+1,2*x+1,2*y+1);
                    if(ans<cnt)
                    {
                        ans=cnt;
                        a=0;b=j;
                        c=x;d=y;
                    }
                    cnt=find(13,2*j+1,2*x+1,2*y+1);
                    if(ans<cnt)
                    {
                        ans=cnt;
                        a=6;b=j;
                        c=x;d=y;
                    }
                }
    printf("%d\n",ans);
    printf("%d %d\n",a+1,b+1);
    printf("%d %d\n",c+1,d+1);
    return 0;
}