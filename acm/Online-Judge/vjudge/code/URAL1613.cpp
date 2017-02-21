#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
using namespace std;

pair<int,int>a[70070],c;
inline int Int()
{
	int a=0;char c=getchar();
	while(c<'0')c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+c-'0',c=getchar();
	return a;
}
int main()
{
    int n=Int(),x,y,z;
    for(int i=0;i<n;i++)
        a[i]=make_pair(Int(),i);
    sort(a,a+n);
    int m=Int();
    while(m--)
    {
        x=Int();y=Int();z=Int();
        c=*lower_bound(a,a+n,make_pair(z,x-1));
        if(c.first!=z)putchar('0');
        else putchar(c.second<y?'1':'0');
    }
    putchar(10);
	return 0;
}
