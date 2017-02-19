#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

char s[1000];
vector<int>ans;
int main()
{
//    freopen("1.txt","r",stdin);
    int t;scanf("%d",&t);
    while(t--)
    {
        scanf("%s",s);ans.clear();
        for(int i=1;i<=12;i++)
            if(12%i==0)
            {
                int d=12/i;
                for(int j=0;j<d;j++)
                {
                    bool f=1;
                    for(int z=j;z<12;z+=d)
                        if(s[z]=='O')f=0;
                    if(f)
                    {
                        ans.push_back(i);
                        break;
                    }
                }
            }
        printf("%d",ans.size());
        for(int i=0;i<ans.size();i++)
            printf(" %dx%d",ans[i],12/ans[i]);
        putchar(10);
    }
    return 0;
}
