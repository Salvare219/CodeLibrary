#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


char s[120000],p[120000];
int has[30],no[30];
bool ok()
{
    int sum=0;
    for(int i=0;i<26;i++)
        if(has[i]>no[i]) return 0;
        else sum+=no[i]-has[i];
    if(has[29]==sum) return 1;
    else return 0;
}
int main()
{
 //   freopen("1.txt","r",stdin);
    scanf("%s%s",s,p);
    int i;
    int a=strlen(s),b=strlen(p);
    if(a<b) printf("0\n");
    else
    {
        for(i=0;p[i];i++)
        {
            if(s[i]=='?') has[29]++;
            else has[s[i]-'a']++;
            no[p[i]-'a']++;
        }
        int ans=0;
        if(ok()) ans++;
        for(;s[i];i++)
        {
            if(s[i]=='?') has[29]++;
            else has[s[i]-'a']++;
            if(s[i-b]=='?') has[29]--;
            else has[s[i-b]-'a']--;
            if(ok()) ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}


