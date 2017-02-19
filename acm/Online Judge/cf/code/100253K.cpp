#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

int p[400500];
int d1[400500];
int d2[400500];
int main()
{
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",p+i);
    int st=0,ed=0,mx=0x3fffffff,f=0;
    int sb;
    int ans=1;
    d1[0]=0;
    for(int i=0;i<n;i++)
    {
        if(st!=-1)
        {
            if(i-st+1<=p[i])f=i,sb=1;
            else st=-1;
        }
        if(ed!=-1)
        {
            mx=min(mx,p[i]+i-1);
            if(i<=mx)f=i,sb=2;
            else ed=-1;
        }
        if(st==-1&&ed==-1)
        {
            if(ans!=0)
            {
                d2[ans-1]=f;
                if(sb==1);
                else swap(d1[ans-1],d2[ans-1]);
            }
            st=i;
            ed=i;
            f=i;
            mx=p[i]+i-1;
            d1[ans++]=st;
        }
    }
    if(st!=-1||ed!=-1)
    {
        d2[ans-1]=f;
        if(sb==1);
        else swap(d1[ans-1],d2[ans-1]);
    }
    printf("%d\n",ans);
    for(int i=0;i<ans;i++)
        printf("%d %d\n",d1[i]+1,d2[i]+1);
    return 0;
}
