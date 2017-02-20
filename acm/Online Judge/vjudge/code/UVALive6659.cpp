#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

char s[50000];
int h[30];
int main()
{
    int t,ti=1;scanf("%d",&t);
    while(t--)
    {
        scanf("%s",s);
        int n=strlen(s),ans=0;
        for(int i=0;i<n;i++)
        {
            memset(h,0,sizeof(h));
            for(int j=i;j<n;j++)
            {
                h[s[j]-'a']++;
                int c=0;
                for(int k=0;k<26;k++)
                    if(h[k]%2) c++;
                if(c<=1)ans++;
            }
        }
        printf("Case %d: %d\n",ti++,ans);
    }
	return 0;
}
