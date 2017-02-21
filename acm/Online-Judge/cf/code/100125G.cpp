#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

#include<map>
struct p
{
    int x,y;
    bool operator<(const p&a)const
    {
        return x!=a.x?x<a.x:y<a.y;
    }
}po[100050];
bool v[100050];
vector<int>a,b;
int n;
map<long long,int>mx,my,tx,ty;
int dx1,dx2,dxx,dy1,dy2,dyy;

const int inf=1000000000;
int gcd(int a,int b)
{
    while(a&&b)a>b?a%=b:b%=a;
    return a+b;
}
int cal(int a1,int a2)
{
    mx.clear();my.clear();
    for(int i=0;i<n;i++)
    {
        mx[po[i].x]=i+1;
        my[po[i].y]=i+1;
    }
    long long dx=po[a2].x-po[a1].x;
    int st=a1,ed;
    dx1=po[a1].x;

    for(int j=0;j<n;j++)v[j]=0;

    for(int j=0;j<n;j++)
        if(mx[po[st].x+dx*j])
        {
            v[mx[po[st].x+dx*j]-1]=1;
            dx2=po[st].x+dx*j;
        }
        else break;

    if(dx1>dx2)swap(dx1,dx2);
    dxx=abs(dx);

    long long dy=-1;
    int las=-inf,f1=n-1,f2=0;
    for(int j=0;j<n;j++)
        if(v[j]==0)
        {
            f1=min(f1,j);
            f2=max(f2,j);
            if(las!=-inf)
            {
                int z=po[j].y-las;
                if(dy==-1)dy=z;
                else dy=gcd(dy,z);
            }
            las=po[j].y;
        }
    if(f1>f2)
    {
        dy1=inf;dy2=-inf;
        for(int j=0;j<n;j++)
        {
            dy1=min(dy1,po[j].y);
            dy2=max(dy2,po[j].y);
        }
        dyy=abs(dy1-dy2);
        dxx=abs(dx);
        return 1;
    }
    else if(f1==f2)
    {
        dy1=inf;dy2=-inf;
        for(int j=0;j<n;j++)
        {
            dy1=min(dy1,po[j].y);
            dy2=max(dy2,po[j].y);
        }
        dxx=abs(dx);
        if(abs(po[f1].y-dy1)>abs(dy2-po[f2].y))
        {
            dy2=po[f1].y;
            dyy=abs(po[f1].y-dy1);
        }
        else
        {
            dy1=po[f2].y;
            dyy=abs(dy2-po[f2].y);
        }
        return 1;
    }
    else
    {
        if(po[0].y>po[1].y)dy=-dy;
        
        for(int j=0;j<n;j++)
            if(my[po[f1].y+dy*j])
            {
                v[my[po[f1].y+dy*j]-1]=1;
                dy2=po[f1].y+dy*j;
            }
            else break;
        int f=1;
        for(int j=0;j<n;j++)
            if(v[j]==0)
            {
                f=0;
                break;
            }
        if(f)
        {
            dy1=po[f1].y;
            if(dy1>dy2)swap(dy1,dy2);
            dxx=abs(dx);
            dyy=abs(dy);
            return 1;
        }
        else return 0;
    }
    return 1;
}
int main()
{
    //freopen("1.txt","r",stdin);
    freopen("grid.in","r",stdin);
    freopen("grid.out","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&po[i].x,&po[i].y);
    }
    sort(po,po+n);
    int px=1,py=1;
    for(int i=0;i<n;i++)
    {
        if(po[i].x!=po[0].x)px=0;
        if(po[i].y!=po[0].y)py=0;
    }

    if(px)
    {
        printf("%d %d %d %d %d %d\n",po[0].x-1,po[0].x+1,2,po[0].y,po[n-1].y,po[1].y-po[0].y);
        return 0;
    }
    else if(py)
    {
        printf("%d %d %d %d %d %d\n",po[0].x,po[n-1].x,po[1].x-po[0].x,po[0].y-1,po[0].y+1,2);
        return 0;
    }
    else
    {
        int lim=8;
        for(int i=0;i<lim;i++)
        {
            a.clear();b.clear();
            for(int j=0;j<3;j++)
                if((1<<j)&i)a.push_back(j);
                else b.push_back(j);
            if(a.size()>=2)
            {
                if(cal(a[0],a[1]))
                {
                    printf("%d %d %d %d %d %d\n",dx1,dx2,dxx,dy1,dy2,dyy);

                    //putchar('C');

                    return 0;
                }
            }
            else
            {
                for(int i=0;i<n;i++)
                    swap(po[i].x,po[i].y);
                if(cal(b[0],b[1]))
                {
                    printf("%d %d %d %d %d %d\n",dy1,dy2,dyy,dx1,dx2,dxx);

                    //putchar('B');

                    return 0;
                }
                for(int i=0;i<n;i++)
                    swap(po[i].x,po[i].y);
            }
        }
    }
    return 0;
}

