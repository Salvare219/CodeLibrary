#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;



int main()
{
 //   freopen("1.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,temp,sum=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&temp);
            if(temp%4==0) sum^=temp-1;
            else if(temp%4<3) sum^=temp;
            else sum^=temp+1;
        }
        if(sum) printf("Alice\n");
        else printf("Bob\n");
    }
    return 0;
}

