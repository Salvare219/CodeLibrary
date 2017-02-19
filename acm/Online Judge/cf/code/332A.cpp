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


char str[999999];
int main()
{
 //   freopen("1.txt","r",stdin);
    int n;
    scanf("%d%s",&n,str);
    int now=0,ans=0;
    int fa=0,fb=0;
    for(int i=0;str[i];i++)
    {
        if(now==0)
        {
            if(fa>=3) ans++,fa++,fb=0;
            else if(fb>=3) ans++,fb++,fa=0;
            else
            {
                if(str[i+1]=='a') fa++,fb=0;
                else fb++,fa=0;
            }
        }
        else
        {
            if(str[i]=='a') fa++,fb=0;
            else fb++,fa=0;
        }
        now=(now+1)%n;
    }
    printf("%d\n",ans);
    return 0;
}
