#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

int h[100050],st[100050],m[100050],sa[100050];
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        for(int i=0;i<n;i++)
            scanf("%d",h+i);
        int f=1;
        st[0]=1000005;m[0]=0;
        for(int i=0;i<n;i++)
        {
            while(f&&st[f-1]<=h[i])f--,m[f-1]=min(m[f],m[f-1]);
            sa[i]=m[f-1];
            st[f]=h[i];m[f++]=h[i];
        }
        f=1;
        for(int i=n-1;i>-1;i--)
        {
            while(f&&st[f-1]<=h[i])f--,m[f-1]=min(m[f],m[f-1]);
            sa[i]=max(sa[i],m[f-1]);
            st[f]=h[i];m[f++]=h[i];
        }
        bool l=0;
        for(int i=1;i<n-1;i++)
            if(h[i]>h[i+1]&&h[i]>h[i-1]&&h[i]-sa[i]>=150000)
            {
                if(l)printf(" %d",i+1);
                else printf("%d",i+1),l=1;
            }
        putchar(10);
    }
	return 0;
}
