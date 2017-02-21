#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


struct Point
{
    long long x,y;
    int i;
    Point(long long a=0,long long b=0){x=a;y=b;}
    Point operator-(const Point&a)const{return Point(x-a.x,y-a.y);}
    Point operator+(const Point&a)const{return Point(x+a.x,y+a.y);}
    Point operator*(const long long&a)const{return Point(x*a,y*a);}
    long long operator*(const Point&a)const{return x*a.y-y*a.x;}
    Point operator/(const long long&a)const{return Point(x/a,y/a);}

    bool operator<(const Point&a)const
    {
        return x!=a.x?x<a.x:y<a.y;
    }
}po[200];
bool dp[101][101][101];
int pre[101][101][101][3];
int up[101][101];
int dw[101][101];
bool ing[101][101];
int lup[101];
int ldw[101];
bool ling[101];
int las[105];
int main()
{
    //freopen("1.txt","r",stdin);
    freopen("division.in","r",stdin);
    freopen("division.out","w",stdout);
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%I64d%I64d",&po[i].x,&po[i].y);
        po[i].i=i+1;
    }
    sort(po,po+n);
    memset(pre,-1,sizeof(pre));
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if(i!=j&&po[j].x>po[i].x)
            {
                int a=0,b=0;
                int f=0;
                for(int k=0;k<n;k++)
                    if(i!=k&&j!=k)
                    {
                        if(po[k].x>po[i].x&&po[j].x>=po[k].x)
                        {
                            long long z=(po[j]-po[i])*(po[k]-po[i]);
                            if(z==0)
                            {
                                f=1;
                                break;
                            }
                            else if(z>0)
                            {
                                a++;
                            }
                            else
                            {
                                b++;
                            }
                        }
                    }
                if(f==0)
                {
                    ing[i][j]=1;
                    up[i][j]=a;
                    dw[i][j]=b;
                }
            }
    for(int i=0;i<n;i++)
    {
        int a=0,b=0;
        int f=0;
        for(int j=0;j<n;j++)
            if(po[i].x<po[j].x&&i!=j)
            {
                if(po[j].y==po[i].y)
                {
                    f=1;
                    break;
                }
                else if(po[j].y>po[i].y)
                {
                    a++;
                }
                else
                {
                    b++;
                }
            }
        if(f==0)
        {
            lup[i]=a;
            ldw[i]=b;
            ling[i]=1;
        }
    }

    for(int i=0;i<n;i++)
    {
        int a=0,b=0;
        int f=0;
        for(int j=0;j<n;j++)
            if(po[i].x>=po[j].x&&i!=j)
            {
                if(po[j].y==po[i].y)
                {
                    f=1;
                    break;
                }
                else if(po[j].y>po[i].y)
                {
                    a++;
                }
                else
                {
                    b++;
                }
            }
        if(f==0)
        {
            dp[i][a][b]=1;
        }
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            for(int k=0;k<n;k++)
                if(dp[i][j][k])
                {
                    for(int z=i+1;z<n;z++)
                        if(ing[i][z])
                        {
                            int a=j+up[i][z];
                            int b=k+dw[i][z];
                            dp[z][a][b]=1;
                            pre[z][a][b][0]=i;
                            pre[z][a][b][1]=j;
                            pre[z][a][b][2]=k;
                        }
                }
    int ans=5000,x,y,z;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            for(int k=0;k<n;k++)
                if(dp[i][j][k]&&ling[i])
                {
                    int a=j+lup[i];
                    int c=k+ldw[i];
                    int b=n-a-c;
                    int aa=max(a,max(b,c));
                    int cc=min(a,min(b,c));
                    if(aa-cc<ans)
                    {
                        ans=aa-cc;
                        x=i;y=j;z=k;
                    }
                }
    int cnt=0;
    while(x!=-1)
    {
        las[cnt++]=x;
        int a=pre[x][y][z][0];
        int b=pre[x][y][z][1];
        int c=pre[x][y][z][2];
        x=a;
        y=b;
        z=c;
    }
    printf("%d\n",cnt);
    for(int i=0;i<cnt;i++)
        printf("%d%c",po[las[cnt-i-1]].i,i==cnt-1?10:' ');
    return 0;
}
