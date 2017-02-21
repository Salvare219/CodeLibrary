#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;


char ori[10005],str[1000005];
int nex[10005];
int main()
{
    int t;
    scanf("%d",&t);
    nex[0]=-1;
    while(t--)
    {
        scanf("%s%s",ori,str);
        int i=0,j=-1;
        while(ori[i])
        {
            while(j!=-1 && ori[i]!=ori[j]) j=nex[j];
            i++;j++;
            if(ori[j]==ori[i]) nex[i]=nex[j];
            else nex[i]=j;
        }
        int ans=0;
        i=0,j=0;
        while(str[i])
        {
            while(j!=-1 && str[i]!=ori[j] )
                j=nex[j];
            ++i,++j;
            if(ori[j]==0) ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}