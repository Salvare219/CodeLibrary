#include<bits/stdc++.h>
using namespace std;


int prim[1050],k;
bool is_prim(int s)
{
    for(int i=2;i*i<=s;i++)
        if(s%i==0)
            return 0;
    return 1;
}
int main()
{
    int n;scanf("%d",&n);
    for(int i=2;i<=1100;i++)
        if(is_prim(i))
            prim[k++]=i;
    vector<int>ans;
    for(int i=0;prim[i]<=n;i++)
    {
        int z=prim[i];
        while(z<=n)
            ans.push_back(z),z*=prim[i];
    }
    printf("%d\n",ans.size());
    for(int i=0;i<ans.size();i++)
        printf("%d ",ans[i]);
    return 0;
}

