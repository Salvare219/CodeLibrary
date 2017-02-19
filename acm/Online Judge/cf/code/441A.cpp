#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

vector<int>ans;
int main()
{
    //freopen("1.txt","r",stdin);
    int n,t;scanf("%d%d",&n,&t);
    for(int i=0;i<n;i++)
    {
        int k=0;
        scanf("%d",&k);
        int f=0;
        for(int j=0;j<k;j++)
        {
            int c;
            scanf("%d",&c);
            if(t>c)
            {
                f=1;
            }
        }
        if(f)ans.push_back(i+1);
    }
    sort(ans.begin(),ans.end());
    printf("%d\n",ans.size());
    for(int i=0;i<ans.size();i++)
        printf("%d ",ans[i]);
    return 0;
}
