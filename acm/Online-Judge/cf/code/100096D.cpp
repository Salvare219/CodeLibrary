#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


int b[100050],e[100050];
int s[100050];
int sa[200050];

int in[200050];
int c[200050];
vector<int>p[200050];

void uni(int l,int r,int s)
{
    if(p[l].size()>p[r].size())
    {
        for(int i=0;i<p[r].size();i++)
        {
            c[p[r][i]]^=s;
            in[p[r][i]]=l;
            p[l].push_back(p[r][i]);
        }
    }
    else
    {
        for(int i=0;i<p[l].size();i++)
        {
            c[p[l][i]]^=s;
            in[p[l][i]]=r;
            p[r].push_back(p[l][i]);
        }
    }
}
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n,k=0;scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d%d",b+i,e+i,s+i);
        sa[k++]=b[i]-1;
        sa[k++]=e[i];
    }
    sort(sa,sa+k);
    k=unique(sa,sa+k)-sa;
    for(int i=0;i<k;i++)
    {
        in[i]=i;
        c[i]=0;
        p[i].push_back(i);
    }
    for(int i=0;i<n;i++)
    {
        int l=lower_bound(sa,sa+k,b[i]-1)-sa,r=lower_bound(sa,sa+k,e[i])-sa;
        if(in[l]!=in[r])
        {
            uni(in[l],in[r],(c[r]^c[l])^s[i]);
        }
        else
        {
            int sum=c[l]^c[r];
            if(sum!=s[i])
            {
                printf("%d\n",i);
                return 0;
            }
        }
    }
    printf("%d\n",n);
    return 0;
}
