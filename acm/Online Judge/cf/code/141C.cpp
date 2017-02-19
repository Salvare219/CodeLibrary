#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

struct p
{
    char na[30];
    int ss;
    int a;
    bool operator<(p aa)const{return a<aa.a;}
}s[3005],hi[3005];
bool ins(int sz,int w,int da)
{
    if(sz<w) return 0;
    for(int i=sz;i>w;i--)
        hi[i].a=hi[i-1].a,hi[i].ss=hi[i-1].ss;
    hi[w].a=da;hi[w].ss=sz;
    return 1;
}
int main()
{
//    freopen("1.txt","r",stdin);
    int n,k;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%s%d",s[i].na,&s[i].a);
    sort(s,s+n);
    int now=1000000000,las=1;
    hi[0].a=now;hi[0].ss=0;
    for(int i=1;i<n;i++)
        if(s[i].a==s[i-1].a)
        {
            if(ins(i,las,now)==0)
            {
                printf("-1\n");
                return 0;
            }
        }
        else
        {
            las=s[i].a;now--;
            if(ins(i,las,now)==0)
            {
                printf("-1\n");
                return 0;
            }
        }
    for(int i=0;i<n;i++)
        printf("%s %d\n",s[hi[i].ss].na,hi[i].a);
    putchar(10);
    return 0;
}


