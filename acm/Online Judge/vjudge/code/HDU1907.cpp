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
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,sum=0,temp;
        bool anti=1;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&temp);
            if(temp>1) anti=0;
            sum^=temp;
        }
        if(sum) sum=1;
        if(anti^sum) printf("John\n");
        else printf("Brother\n");
    }
}
