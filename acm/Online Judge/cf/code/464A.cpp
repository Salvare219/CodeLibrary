#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;


char s[42142],ans[24141];
int n,p;
bool ok(int f,int c)
{
    for(int i=c;i<=p-1;i++)
    {
        if(f>0&&i==s[f-1])continue;
        if(f>1&&i==s[f-2])continue;
        s[f]=i;return 1;
    }
    return 0;
}
int main()
{
    //freopen("1.txt","r",stdin);
    scanf("%d%d%s",&n,&p,s);
    for(int i=0;i<n;i++)
        s[i]-='a';
    for(int i=n-1;i>-1;i--)
    {
        int f=0;
        if(ok(i,s[i]+1))
        {
            f=0;
            for(int j=i+1;j<n;j++)
                if(!ok(j,0))
                {
                    f=1;
                    break;
                }
            if(f==0)
            {
                for(int i=0;i<n;i++)
                    printf("%c",s[i]+'a');
                return 0;
            }
        }
    }
    printf("NO\n");
    return 0;
}
