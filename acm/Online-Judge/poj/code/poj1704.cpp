#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;



int num[1005];
int main()
{
 //   freopen("1.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",num+i);
        num[n]=0;
        if(n%2) n++;
        sort(num,num+n);
        int sum=0;
        for(int i=0;i<n;i+=2)
            sum^=num[i+1]-num[i]-1;
        if(sum) printf("Georgia will win\n");
        else printf("Bob will win\n");
    }
    return 0;
}
