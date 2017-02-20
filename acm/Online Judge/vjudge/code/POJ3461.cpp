#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


char bp[1000050],str[10050];
int fail[10050];
int main()
{
    int t;fail[0]=-1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s%s",str,bp);
        int i=0,j=-1,ans=0;
        while(str[i])
        {
            while(j!=-1 && str[i]!=str[j]) j=fail[j];
            i++,j++;
            fail[i]=j;
        }
        i=j=0;
        while(bp[i])
        {
            while(j!=-1 && str[j]!=bp[i]) j=fail[j];
            i++;j++;
            if(str[j]==0) ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}