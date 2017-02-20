#include<bits/stdc++.h>
using namespace std;



char s[60000],f[60000];
int fail[60000],fail1[60000];
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        scanf("%s%s",s,f);
        int i=0,j=-1;
        fail[0]=-1;
        while(f[i])
        {
            while(j!=-1 && f[i]!=f[j]) j=fail[j];
            i++;j++;
            fail[i]=j;
        }
        i=0;j=0;
        int ans=0;
        while(s[i])
        {
            while(j!=-1 && s[i]!=f[j]) j=fail[j];
            i++;j++;
        }
        while(j!=-1)ans++,j=fail[j];
        printf("%d\n",ans);
    }
    return 0;
}
