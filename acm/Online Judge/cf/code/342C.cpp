#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
using namespace std;


int main()
{
    int r,h;
    scanf("%d%d",&r,&h);
    int t=h/r*2,res=h%r;
    if(res==0) t++;
    else if(2*res>=r)
    {
        if((long long)res*res*4>=(long long)3*r*r) t+=3;
        else t+=2;
    }
    else t++;
    printf("%d\n",t);
}
