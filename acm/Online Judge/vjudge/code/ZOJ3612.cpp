#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

struct bit_tree
{
    int bit[10050],s;
    inline void updat(int x,int v)
    {
        while(x<10005) bit[x]+=v,x+=x&-x;
    }
    inline int query(int x)
    {
        s=0;
        while(x) s+=bit[x],x-=x&-x;
        return s;
    }
    inline int find(int x)
    {
        int cnt=0,ans=0,p=1<<15;
        while(p)
        {
            ans|=p;
            if(ans>10001||cnt+bit[ans]>=x)ans^=p;
            else cnt+=bit[ans];p>>=1;
        }
        return ans+1;
    }
}b;
int sa[10050];
int num[10050],cnt[10050];
char s[100];
int q[10050],ty[10050];
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        int n,x;scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%s%d",s,&x);
            sa[i]=num[i]=x;
            ty[i]=s[0]=='r';
        }
        sort(sa,sa+n);
        memset(b.bit,0,sizeof(b.bit));
        memset(cnt,0,sizeof(cnt));
        int k=unique(sa,sa+n)-sa,sum=0;
        for(int i=0;i<n;i++)
            if(ty[i]==0)
            {
                int ind=lower_bound(sa,sa+k,num[i])-sa+1;
                b.updat(ind,1);
                sum++;cnt[ind]++;
                if(sum&1)printf("%d\n",sa[b.find(sum/2+1)-1]);
                else
                {
                    long long c=1ll*sa[b.find(sum/2)-1]+sa[b.find(sum/2+1)-1];
                    if(c&1)printf("%.1f\n",c/2.0);
                    else printf("%lld\n",c/2);
                }
            }
            else
            {
                int ind=lower_bound(sa,sa+k,num[i])-sa+1;
                if(cnt[ind]==0)puts("Wrong!");
                else
                {
                    b.updat(ind,-1);
                    sum--;cnt[ind]--;
                    if(sum==0)puts("Empty!");
                    else
                    {
                        if(sum&1)printf("%d\n",sa[b.find(sum/2+1)-1]);
                        else
                        {
                            long long c=1ll*sa[b.find(sum/2)-1]+sa[b.find(sum/2+1)-1];
                            if(c&1)printf("%.1f\n",c/2.0);
                            else printf("%lld\n",c/2);
                        }
                    }
                }
            }
    }
    return 0;
}
