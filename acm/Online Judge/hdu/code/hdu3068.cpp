#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;


char str[220005],temp[110005];
int pal[220005];
int main()
{
//    freopen("1.txt","r",stdin);
    while(scanf("%s",temp)==1)
    {
        int k=0;
        for(int i=0;temp[i];k++)
            if(k%2) str[k]=temp[i++];
            else str[k]='$';
        if(str[k-1]!='$') str[k++]='$';
        str[k]='#';
        int mx=0,ans=0;;
        for(int i=0;i<k;i++)
        {
            if(pal[mx]+mx>i) pal[i]=min(pal[mx]+mx-i,pal[2*mx-i]);
            else pal[i]=1;
            while(str[i+pal[i]]==str[i-pal[i]]) pal[i]++;
            if(pal[i]>ans) ans=pal[i];
            if(pal[i]+i>mx) mx=i;
        }
        printf("%d\n",ans-1);
    }
    return 0;
}