#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


char temp[1050],str[2050];
int pal[2050];
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
        int mx=0,f;
        for(int i=0;i<k;i++)
        {
            if(pal[mx]+mx>i) pal[i]=min(pal[mx]+mx-i,pal[2*mx-i]);
            else pal[i]=1;
            while(str[i+pal[i]]==str[i-pal[i]]) pal[i]++;
            if(pal[i]+i>mx) mx=i;
        }
        mx=0;
        for(int i=0;i<k;i++)
            if(pal[i]>mx) mx=pal[i],f=i;
        for(int i=f-pal[f]+1;i<f+pal[f];i++)
            if(str[i]!='$') putchar(str[i]);
        putchar(10);
    }
    return 0;
}
