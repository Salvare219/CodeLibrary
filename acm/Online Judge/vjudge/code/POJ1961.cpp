#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;



int nex[1000005];
char ori[1000005];
int main()
{
    int n,ti=1;
    nex[0]=-1;
    while(scanf("%d",&n))
    {
        if(n==0) break;
        scanf("%s",ori);
        int i=0,j=-1;
        while(ori[i])
        {
            while(j!=-1 && ori[i]!=ori[j]) j=nex[j];
            i++;j++;
            nex[i]=j;
        }
        int ans;
        printf("Test case #%d\n",ti++);
        for(i=2;i<=n;i++)
        {
            ans=i-nex[i];
            if(i%ans==0) ans=i/ans;
            else ans=1;
            if(ans>1) printf("%d %d\n",i,ans);
        }
        putchar(10);
    }
    return 0;
}