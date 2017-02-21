#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;



int fib[50];
int main()
{
 //   freopen("1.txt","r",stdin);
    fib[0]=fib[1]=1;
    for(int i=2;i<40;i++)
        fib[i]=fib[i-1]+fib[i-2];
    int n;
    while(scanf("%d",&n)==1)
    {
        bool flag=1;
        for(int i=0;i<40;i++)
            if(fib[i]==n) flag=0;
        if(flag)
        {
            int ans;
            for(int i=39;i>0;i--)
            {
                if(fib[i]==n)
                {
                    ans=fib[i];
                    break;
                }
                n%=fib[i];
            }
            printf("%d\n",ans);
        }
        else printf("lose\n");
    }
    return 0;
}