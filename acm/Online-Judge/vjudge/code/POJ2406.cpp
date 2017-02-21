#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
using namespace std;



int nex[1000005];
char ori[1000005];
int main()
{
    nex[0]=-1;
    while(scanf("%s",ori))
    {
        if(ori[0]=='.') break;
        int i=0,j=-1;
        while(ori[i])
        {
            while(j!=-1 && ori[i]!=ori[j]) j=nex[j];
            i++;j++;
            nex[i]=j;
        }
        int ans=i-nex[i];
        if(i%ans==0) ans=i/ans;
        else ans=1;
        printf("%d\n",ans);
    }
    return 0;
}