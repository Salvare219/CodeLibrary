#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;


char str[15][80];
int fail[80];
char lib[80];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int i,j;
        for(i=0;i<n;i++)
            scanf("%s",str[i]);
        int ans=0,pos=0,temp;
        for(int k=0;str[0][k];k++)
        {
            i=k;
            fail[k]=k-1;
            j=k-1;
            while(str[0][i])
            {
                while(j!=k-1 && str[0][i]!=str[0][j]) j=fail[j];
                i++;j++;
                fail[i]=j;
            }
            int an=99999;
            for(int c=1;c<n;c++)
            {
                i=0;j=k;
                temp=0;
                while(str[c][i])
                {
                    while(j!=k-1 && str[c][i]!=str[0][j]) j=fail[j];
                    i++;j++;
                    if(j-k>temp) temp=j-k;
                }
                an=min(an,temp);
                if(an==0) break;
            }
            if(an>ans)
            {
                ans=an,pos=k;
                for(i=k;i<k+an;i++)
                    lib[i-k]=str[0][i];
                lib[an]=0;
            }
            else if(an==ans)
            {
                char ch=str[0][k+an];
                str[0][k+an]=0;
                if(strcmp(str[0]+k,lib)<0) strcpy(lib,str[0]+k);
                str[0][k+an]=ch;
            }
        }
        if(ans>2) printf("%s\n",lib);
        else printf("no significant commonalities\n");
    }
    return 0;
}