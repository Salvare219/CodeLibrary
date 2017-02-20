#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;


char str[400000];
unsigned long long has[400005],l[400005];
long long k=13131;
int main()
{
    while(scanf("%s",str)==1)
    {
        int n=strlen(str);
        l[n-1]=str[n-1];
        has[n-1]=1;
        long long temp=1;
        for(int i=n-2;i>-1;i--)
        {
            temp=temp*k;
            l[i]=str[i]*temp;
            has[i]=temp;
        }
        for(int i=1;i<n;i++)
            l[i]=l[i-1]+l[i];
        n--;
        for(int i=0;i<n;i++)
            if(l[i]==(l[n]-l[n-i-1])*has[i]) printf("%d ",i+1);
        printf("%d\n",n+1);
    }
    return 0;
}
