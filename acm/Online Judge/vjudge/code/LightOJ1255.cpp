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


char str[1000005],pal[1000005];
int fail[1000005];
int main()
{
    int ti=1,t;
    fail[0]=-1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s%s",str,pal);
        int i=0,j=-1;
        while(pal[i])
        {
            while(j!=-1 && pal[i]!=pal[j]) j=fail[j];
            i++;j++;
            fail[i]=j;
        }
        i=j=0;
        int ans=0;
        while(str[i])
        {
            while(j!=-1 && str[i]!=pal[j]) j=fail[j];
            i++;j++;
            if(pal[j]==0) ans++;
        }
        printf("Case %d: %d\n",ti++,ans);
    }
    return 0;
}
