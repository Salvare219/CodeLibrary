#include<bits/stdc++.h>
using namespace std;


struct Point
{
    double x,y;
    Point(){}
    Point(double a,double b){x=a;y=b;}
    double operator/(const Point&a)const{return sqrt((a.x-x)*(a.x-x)+(a.y-y)*(a.y-y));}
}p[50];
int s[50];
double dp[35][6050];
char c[100];
double ans[6050];
int main()
{
    int n,ti=1;
    while(scanf("%d",&n)&&n)
    {
        for(int i=1;i<=n;i++)
            scanf("%lf%lf%d",&p[i].x,&p[i].y,s+i);
        for(int i=0;i<=n;i++)
            for(int j=0;j<10005;j++)
                dp[i][j]=1e40;
        p[0]=Point(0,0);
        dp[0][0]=0;
        for(int i=1;i<=n;i++)
            for(int j=0;j<i;j++)
                for(int z=0;z+s[i]<=6000;z++)
                    dp[i][z+s[i]]=min(dp[i][z+s[i]],dp[j][z]+p[j]/p[i]);
        for(int i=0;i<=6000;i++)
            ans[i]=1e40;
        for(int i=0;i<=6000;i++)
            for(int j=0;j<=n;j++)
                ans[i]=min(ans[i],dp[j][i]+p[j]/p[0]);
        int x;
        printf("Race %d\n",ti++);
        while(scanf("%s%d",c,&x))
        {
            if(c[0]=='#')break;
            int f=0;
            for(int i=0;i<=6000;i++)
                if(ans[i]<=x)
                    f=max(f,i);
            printf("%s: %d\n",c,f);
        }
    }
	return 0;
}
