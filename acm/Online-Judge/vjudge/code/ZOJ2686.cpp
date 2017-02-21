#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;



int num[500];
int main()
{
//    freopen("1.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",num+i);
        int l=0,r=0;
        for(int i=0;num[i];i++) r++;
        for(int i=n-1;num[i];i--) l++;
        if(r%2 || l%2) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}

