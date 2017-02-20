#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

double x[]={3.830127018922193,
-3.601321235851749,
0.466045194906253,
10.411264148588986,
12.490381056766580};
double y[]={3.366025403784439,
10.057331467373021,
19.192786043799030,
18.147501411122495,
8.366025403784439};
int ans[]={2,-3,2,-5};
int main()
{
//    freopen("1.txt","r",stdin);
    int n;scanf("%d",&n);
    int m=1+4*n;
    printf("%d\n",m);
    double dx=x[2]-x[0],dy=y[2]-y[0];
    for(int i=0;i<5;i++)
        printf("%.10f %.10f\n",x[i],y[i]);
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<4;j++)
            printf("%.10f %.10f\n",x[j+1]+dx*i,y[j+1]+dy*i);
    }
    int sp=3,cnt=6;
    printf("1 2 3 4 5\n");
    for(int i=1;i<n;i++,putchar(10))
    {
        printf("%d",sp);sp+=4;
        for(int j=0;j<4;j++)
            printf(" %d",cnt++);
    }
    printf("1");sp=3;
    for(int i=1;i<=n;i++)
        printf(" %d",sp),sp+=4;
    sp-=4;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<4;j++)
            sp+=ans[j],printf(" %d",sp);
    }
    printf(" 5 2 4 1\n");
	return 0;
}
