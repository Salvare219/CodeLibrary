#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
#include<cstdio>
using namespace std; 
#define INF 12345678 
#define EPS 1e-8 
#define MAXN 110 
struct point 
{
    double x,y; 
    bool mark; 
    point(){}
    point(double x0,double y0): x(x0),y(y0),mark(1){} 
};
vector<point> p;
int n; 
double a[MAXN],b[MAXN],c[MAXN]; 
point operator -(const point &A,const point &B) 
{
    return point(A.x-B.x,A.y-B.y); 
}
double cross(point p1,point p2) 
{
    return p1.x*p2.y-p1.y*p2.x; 
}
int dblcmp(double x) 
{
    if(fabs(x)<EPS) return 0; 
    return (x>0) ? 1:-1; 
}
point find_intersection(point p1,point p2,point p3,point p4)
{
    double s1=fabs(cross(p3-p1,p2-p1)); 
    double s2=fabs(cross(p4-p1,p2-p1)); 
    return point((p3.x*s2+p4.x*s1)/(s1+s2),(p3.y*s2+p4.y*s1)/(s1+s2)); 
}
void update(double A,double B,double C) 
{
    int i; 
    point temp;
    for(i=0;i<p.size();i++) 
    {
        if(dblcmp(A*p[i].x+B*p[i].y+C)>0) p[i].mark=1; 
        else p[i].mark=0; 
    }
    p.push_back(p[0]); 
    for(i=0;i<p.size()-1;i++) 
    {
        if(p[i].mark^p[i+1].mark==1) 
        {
            if(A!=0) 
                temp=find_intersection(point(-C/A,0),point(-(B+C)/A,1),p[i],p[i+1]); 
            else if(B!=0) 
                temp=find_intersection(point(0,-C/B),point(1,-(A+C)/B),p[i],p[i+1]); 
            p.insert(p.begin()+i+1,temp); 
            i++;
        }
    }
    p.pop_back();
    for(i=0;i<p.size();i++) 
        if(p[i].mark==0) 
            p.erase(p.begin()+i), i--;
}

bool solve(int v) 
{
    int i; 
    for(i=1;i<=n;i++) 
    if(i!=v) 
    {
        update(1/a[i]-1/a[v],1/b[i]-1/b[v],1/c[i]-1/c[v]); 
        if(p.size()==0) return 0; 
    }
    return 1; 
}
int main() 
{
    scanf("%d",&n); 
    int i; 
    for(i=1;i<=n;i++) scanf("%lf%lf%lf",a+i,b+i,c+i); 
    for(i=1;i<=n;i++) 
    {
        p.clear();
        p.push_back(point(INF,INF));
        p.push_back(point(INF,0)); 
        p.push_back(point(0,0)); 
        p.push_back(point(0,INF)); 
        if(solve(i)) printf("Yes\n"); 
        else printf("No\n"); 
    }
    return 0; 
}