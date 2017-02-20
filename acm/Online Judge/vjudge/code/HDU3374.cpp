#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;


char str[1000005];
int nex[1000005];
int get_min()
{
   int len=strlen(str),i=0,j=1,k=0,t;
   while(i<len && j<len && k<len)
   {
       t=str[(i+k)%len]-str[(j+k)%len];
       if(t)
       {
           if(t>0) i=i+k+1;
           else j=j+k+1;
           if(i==j) j++;
           k=0;
       }
       else k++;
   }
   return min(i,j);
}
int get_max()
{
   int len=strlen(str),i=0,j=1,k=0,t;
   while(i<len && j<len && k<len)
   {
       t=str[(i+k)%len]-str[(j+k)%len];
       if(t)
       {
           if(t<0) i=i+k+1;
           else j=j+k+1;
           if(i==j) j++;
           k=0;
       }
       else k++;
   }
   return min(i,j);
}
int main()
{
    nex[0]=-1;
    while(scanf("%s",str)==1)
    {
        int i=0,j=-1,ans;
        while(str[i])
        {
            while(j!=-1 && str[i]!=str[j]) j=nex[j];
            i++;j++;
            nex[i]=j;
        }
        ans=i-nex[i];
        if(i%ans==0) ans=i/ans;
        else ans=1;
        printf("%d %d %d %d\n",get_min()+1,ans,get_max()+1,ans);
    }
    return 0;
}