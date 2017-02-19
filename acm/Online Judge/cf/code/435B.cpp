#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int s[20];
int len;
long long cal()
{
    long long c=0;
    for(int i=0;i<len;i++)
        c=c*10+s[i];
    return c;
}
int main()
{
    //freopen("1.txt","r",stdin);
    long long x;
    int d;
    scanf("%I64d%d",&x,&d);
    while(x)
    {
        s[len++]=x%10;
        x/=10;
    }
    for(int i=0;i<len/2;i++)swap(s[i],s[len-i-1]);
    for(int i=0;i<len;i++)
    {
        int f=i,c=-1;
        for(int j=i;j<=i+d&&j<len;j++)
            if(s[j]>c)c=s[j],f=j;
        d-=f-i;
        for(int j=f;j>i;j--)
            swap(s[j],s[j-1]);
    }
    printf("%I64d\n",cal());
    return 0;
}
