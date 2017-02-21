#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
using namespace std;

#include<bitset>
vector<int>gi[1505],go[1505];
bitset<1505>to[1505],se;
char s[2000];
int main()
{
    freopen("triatrip.in","r",stdin);
    freopen("triatrip.out","w",stdout);
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%s",s);
        for(int j=0;j<n;j++)
            if(s[j]=='+')
            {
                go[i].push_back(j);
                gi[j].push_back(i);
                to[i][j]=true;
            }
    }
    long long ans=0;
    for(int i=0;i<n;i++)
    {
        se.reset();
        for(int j=0;j<(int)gi[i].size();j++)
            se[gi[i][j]]=true;
        for(int j=0;j<(int)go[i].size();j++)
            ans+=(to[go[i][j]]&se).count();
    }
    printf("%I64d\n",ans/3);
    return 0;
}
