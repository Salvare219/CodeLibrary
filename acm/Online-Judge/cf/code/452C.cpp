#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    int n,m;scanf("%d%d",&n,&m);
    if(n==1&&m==1)printf("1.0000000000");
    else
    {
        double c=1.0/n;
        double c1=1.0*(n-1)*m*(m-1);
        double mu=1.0*n*m*(n*m-1);
        printf("%.10f\n",c+c1/mu);
    }
    return 0;
}


