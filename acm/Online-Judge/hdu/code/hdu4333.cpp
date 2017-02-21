#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

char str[200005],ori[200005];
int fail[200005],extend[200005];
int fail1[200005];
void extend_kmp()
{
    int i,j=-1,l,r;
    for(i=1;ori[i];i++,j--)
    {
        if(j<0 || i+fail[i-l]>=r)
        {
            if(j<0) j=0,r=i;
            while(ori[r] && ori[j]==ori[r]) r++,j++;
            fail[i]=j;l=i;
        }
        else fail[i]=fail[i-l];
    }
    fail[0]=i;j=-1;
    for(i=0;str[i];i++,j--)
    {
        if(j<0 || i+fail[i-l]>=r)
        {
            if(j<0) j=0,r=i;
            while(str[r] && ori[j] && ori[j]==str[r]) r++,j++;
            extend[i]=j;l=i;
        }
        else extend[i]=fail[i-l];
    }
}
int main()
{
    int t,ti=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",ori);
        int i,j;
        for(i=0;ori[i];i++) str[i]=ori[i];
        for(j=0;ori[j];j++) str[i+j]=ori[j];
        str[i+j]=0;
        extend_kmp();
        int l=0,e=0,g=0,z;
        for(i=0;i<j;i++)
        {
            if(extend[i]>=j) e++;
            else
            {
                if(str[extend[i]+i]>ori[extend[i]]) g++;
                else l++;
            }
        }
        fail1[0]=-1;i=0;j=-1;
        while(ori[i])
        {
            while(j!=-1 && ori[i]!=ori[j]) j=fail1[j];
            i++;j++;
            fail1[i]=j;
        }
        z=i-fail1[i];
        if(i%z==0) z=i/z;
        else z=1;
        printf("Case %d: %d %d %d\n",ti++,l/z,e/z,g/z);
    }
    return 0;
}
