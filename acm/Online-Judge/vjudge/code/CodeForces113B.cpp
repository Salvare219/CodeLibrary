#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

#include<tr1/unordered_set>
using namespace tr1;
unordered_set<unsigned long long>sa;

vector<int>ss,tt;
unsigned long long hash1[2005];
unsigned long long po[2005];
const unsigned long long seed=13131;
int l,n,m;
char s[2005],a[2005],b[2005];
inline unsigned long long cal(int ll,int rr)
{
    ll++;rr++;
    return (hash1[rr]-hash1[ll-1])*po[l-rr];
}
int main()
{
    scanf("%s%s%s",s,a,b);
    l=strlen(s);
    n=strlen(a);
    m=strlen(b);
    for(int i=0;i<l;i++)
    {
        int c=1;
        for(int j=0;j<n;j++)
            if(s[i+j]!=a[j])
            {
                c=0;
                break;
            }
        if(c)ss.push_back(i);
    }
    for(int i=0;i<l;i++)
    {
        int c=1;
        for(int j=0;j<m;j++)
            if(s[i+j]!=b[j])
            {
                c=0;
                break;
            }
        if(c)tt.push_back(i+m-1);
    }
    hash1[0]=0;po[0]=1;
    unsigned long long pp=1;
    for(int i=1;i<=l;i++)
    {
        hash1[i]=hash1[i-1]+pp*(s[i-1]-'0');
        pp*=seed;
        po[i]=pp;
    }
    int fa=max(n,m);
    for(int i=0;i<ss.size();i++)
        for(int j=0;j<tt.size();j++)
            if(tt[j]-ss[i]+1>=fa)sa.insert(cal(ss[i],tt[j]));
    printf("%d\n",sa.size());
	return 0;
}
