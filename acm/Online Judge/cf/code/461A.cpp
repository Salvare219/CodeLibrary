#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


long long s[300050];
int main()
{
    //freopen("1.txt","r",stdin);
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%I64d",s+i);
        push_heap(s,s+i+1);
    }
    long long ans=0;
    while(n!=1)
    {
        long long a=s[0];
        pop_heap(s,s+n);n--;
        long long b=s[0];
        pop_heap(s,s+n);n--;
        ans+=a+b;
        s[n++]=a+b;
        push_heap(s,s+n);
    }
    printf("%I64d\n",ans+s[0]);
    return 0;
}
