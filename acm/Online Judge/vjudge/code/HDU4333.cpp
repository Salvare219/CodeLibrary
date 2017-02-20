#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;


char str[200005];
int nex[2000005];
int main()
{
    int t,ti=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",str);
        int i,j=-1,l,r,len=strlen(str);
        for(i=0;i<len;i++) str[len+i]=str[i];
        str[len*=2]=0;
        for(i=1;i<len;i++,j--)
        {
            if(j<0 || i+nex[i-l]>=r)
            {
                if(j<0) j=0,r=i;
                while(str[r] && str[j]==str[r]) r++,j++;
                nex[i]=j;l=i;
            }
            else nex[i]=nex[i-l];
        }
        nex[0]=len;
        int e=0,s=0,g=0;
        for(i=1;i+nex[i]<len;i++);
        if(len%(len-nex[i])==0) l=i;
        else l=len/2;
        len/=2;
        for(i=0;i<l;i++)
            if(nex[i]>=len) e++;
            else if(str[nex[i]]<str[i+nex[i]]) g++;
            else s++;
        printf("Case %d: %d %d %d\n",ti++,s,e,g);
    }
    return 0;
}