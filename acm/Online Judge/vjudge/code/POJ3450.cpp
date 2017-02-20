#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;


char str[4005][205];
int nex[205];
char lib[205];
int main()
{
    int n;
    while(scanf("%d",&n))
    {
        if(n==0) break;
        int i,j;
        for(i=0;i<n;i++)
            scanf("%s",str[i]);
        int ans=0,pos=0,temp;
        for(int k=0;str[0][k];k++)
        {
            i=k;
            nex[k]=k-1;
            j=k-1;
            while(str[0][i])
            {
                while(j!=k-1 && str[0][i]!=str[0][j]) j=nex[j];
                i++;j++;
                nex[i]=j;
            }
            int an=99999;
            for(int c=1;c<n;c++)
            {
                i=0;j=k;
                temp=0;
                while(str[c][i])
                {
                    while(j!=k-1 && str[c][i]!=str[0][j]) j=nex[j];
                    i++;j++;
                    if(j-k>temp) temp=j-k;
                }
                an=min(an,temp);
                if(an==0) break;
            }
            if(an>ans)
            {
                ans=an;pos=k;
                char ch=str[0][k+an];
                str[0][k+an]=0;
                strcpy(lib,str[0]+k);
                str[0][k+an]=ch;
            }
            else if(an==ans)
            {
                char ch=str[0][k+an];
                str[0][k+an]=0;
                if(strcmp(str[0]+k,lib)<0) strcpy(lib,str[0]+k);
                str[0][k+an]=ch;
            }
        }
        if(ans) printf("%s\n",lib);
        else printf("IDENTITY LOST\n");
    }
    return 0;
}