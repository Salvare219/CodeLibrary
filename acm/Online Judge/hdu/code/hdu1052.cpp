#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

short int a[1000],b[1000];
inline short int Int()
{
    short int a=0;char c=getchar();
    while(c<'0')c=getchar();
    while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+c-'0',c=getchar();
    return a;
}
int main()
{
    short int n,i,p1,p2,t1,t2,ans;
    while(n=Int())
    {
        for(i=0;i<n;i++)a[i]=Int();
        for(i=0;i<n;i++)b[i]=Int();
        sort(a,a+n);sort(b,b+n);
        p1=t1=ans=0;p2=t2=n-1;
        for(i=0;i<n;i++)
            if(a[t1]>b[p1])ans++,p1++,t1++;
            else if(a[t1]<b[p1])p2--,ans--,t1++;
            else
            {
                if(a[t2]>b[p2])p2--,t2--,ans++;
                else b[p2--]>a[t1++]?ans--:0;
            }
        printf("%d\n",ans*200);
    }
    return 0;
}
