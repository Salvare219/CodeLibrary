#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<queue>
using namespace std;


int main()
{
    long long n,a,b,c,d;
    long long x=31405,y=31405,y1=-31405,x1=-31405;
    long long sum=0;
    scanf("%I64d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%I64d%I64d%I64d%I64d",&a,&b,&c,&d);
        sum+=(d-b)*(c-a);
        x=min(x,a);y=min(y,b);
        y1=max(d,y1);x1=max(x1,c);
    }
    bool flag=1;
    if((y1-y)!=(x1-x)) flag=0;
    if(flag && sum==(y1-y)*(x1-x)) printf("YES\n");
    else printf("NO\n");
	return 0;
}
