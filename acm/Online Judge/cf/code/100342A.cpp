#include<bits/stdc++.h>
using namespace std;

int a[40005],s[200005],nt[40005],p[2][20005],st[200005],sp,s0[200005],ft;

int main()
{
    freopen("brackets.in","r",stdin);
    freopen("brackets.out","w",stdout);
    int T,n,m,i,j,x,pp;
    for(scanf("%d",&T);T--;)
    {
        scanf("%d%d",&n,&m);n*=2;m*=2;
        for(ft=m,j=i=0;i<m;i++)
        {
            scanf("%d",&a[i]);
            if(a[i]>0)
            {
                ft=min(ft,i);
                p[0][a[i]]=i;
                while(j<i)
                    nt[j++]=i;
            }
            else
                p[1][-a[i]]=i;
        }
        while(j<i)
            nt[j++]=i;
        for(sp=i=0;i<n;i++)
        {
            scanf("%d",&s[i]);
            pp=p[s[i]<0][abs(s[i])];x=m;
            if(sp<n-i)
                x=min(x,nt[pp]);
            if(sp&&p[1][st[sp-1]]>pp)
                x=min(x,p[1][st[sp-1]]);
            s0[i]=x;
            if(s[i]>0)
                st[sp++]=s[i];
            else
                sp--;
        }
        for(i=n;i--;)
            if(s0[i]<m)
            {
                s[i]=a[s0[i]];
                break;
            }
        for(sp=j=0,i++;j<i;j++)
            if(s[j]>0)
                st[sp++]=s[j];
            else
                sp--;
        for(;i<n;i++)
            if(sp>=n-i||(sp&&p[1][st[sp-1]]<ft))
                s[i]=-st[--sp];
            else
                st[sp++]=s[i]=a[ft];
        for(i=0;i<n;i++)
            printf("%d%c",s[i],i==n-1?'\n':' ');
    }
    return 0;
}
