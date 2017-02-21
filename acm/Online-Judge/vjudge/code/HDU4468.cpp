#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

char s[100005],r[1000005];
int fail[100005];
int main()
{
    int ti=1;
    while(scanf("%s",r)==1)
    {
        int i=0,j=0,k=-1,len=1,p=0;
        fail[0]=-1;
        s[0]=r[0];s[1]=0;
        while(r[i])
        {
            while(j!=-1&&r[i]!=s[j]) j=fail[j];
            i++;j++;
            if(j==len)p=i;
            if(j==0)
            {
                while(p<i)
                {
                    s[len++]=r[p];
                    while(k!=-1&&s[k]!=r[p])k=fail[k];
                    k++;p++;
                    fail[len]=k;
                }
                fail[len]=0;s[len]=0;
            }
        }
        printf("Case %d: %d\n",ti++,i-p+len);
    }
    return 0;
}
