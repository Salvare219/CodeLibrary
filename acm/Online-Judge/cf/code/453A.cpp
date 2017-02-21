#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

double pow_mod(double a,int b)
{
    double c=1.0;
    while(b)
    {
        if(b&1)c=c*a;
        b>>=1;
        a=a*a;
    }
    return c;
}
int main()
{
    //freopen("1.txt","r",stdin);
    int n,m;scanf("%d%d",&m,&n);
    double ans=m;
    for(int i=1;i<m;i++)
        ans-=pow_mod(1.0*(m-i)/m,n);
    printf("%.10f\n",ans);
	return 0;
}

