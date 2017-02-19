#include <bits/stdc++.h>
using namespace std;


int a[100050];
int s1[100050];
int s2[100050];
vector<pair<int,int> >ans;
int ok(int x,int y,int z)
{
    if(s1[y]-s1[x-1]>=z)return 1;
    if(s2[y]-s2[x-1]>=z)return 2;
    return 0;
}
int main()
{
    //freopen("1.txt","r",stdin);
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",a+i);
        if(a[i]==1)
        {
            s1[i]=s1[i-1]+1;
            s2[i]=s2[i-1];
        }
        else
        {
            s1[i]=s1[i-1];
            s2[i]=s2[i-1]+1;
        }
    }
    for(int i=1;i<=n;i++)
    {
        int pos=1,f=0;
        int c1=0,c2=0;
        int z=-1;
        while(pos<=n)
        {
            int l=pos,r=n,mid;
            if(ok(pos,n,i)==0)
            {
                f=1;
                break;
            }
            while(l<r)
            {
                mid=(l+r)/2;
                if(ok(pos,mid,i))r=mid;
                else l=mid+1;
            }
            if(ok(pos,r,i)==1)c1++,z=1;
            else c2++,z=2;
            pos=r+1;
        }
        if(f==0)
        {
            if(c1!=c2)
            {
                if((c1>c2&&z==1)||(c1<c2&&z==2))
                {
                    ans.push_back(make_pair(max(c1,c2),i));
                }

            }
        }
    }
    sort(ans.begin(),ans.end());
    printf("%d\n",ans.size());
    for(int i=0;i<ans.size();i++)
        printf("%d %d\n",ans[i].first,ans[i].second);
    return 0;
}
