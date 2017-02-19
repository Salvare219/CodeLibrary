#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

int n,sum;
vector<int>a[100050];
int ss[100050];
long long cal(int t)
{
    long long f=0;
    int fa=sum;
    int z=0;
    for(int i=0;i<100005;i++)
    {
        if(a[i].size()>t)
        {
            for(int j=0;j<a[i].size()-t;j++)
                fa++,f+=a[i][j];
            for(int j=a[i].size()-t;j<a[i].size();j++)
            {
                ss[z++]=a[i][j];
            }
        }
        else
        {
            for(int j=0;j<a[i].size();j++)
            {
                ss[z++]=a[i][j];
            }
        }
    }
    if(fa>t)return f;
    else
    {
        sort(ss,ss+z);
        for(int i=0;i<z;i++)
            if(fa<=t)
            {
                fa++;
                f+=ss[i];
            }
        return f;
    }
}
int main()
{
    //freopen("2.txt","r",stdin);
    scanf("%d",&n);
    int x,y;
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&x,&y);
        if(x)a[x].push_back(y);
        else sum++;
    }
    for(int i=0;i<100005;i++)
        sort(a[i].begin(),a[i].end());
    int l=0,r=n,t1,t2;
    while(r-l>5)
    {
        t1=(2*l+r)/3;
        t2=(l+2*r)/3;
        if(cal(t1)>cal(t2))l=t1;
        else r=t2;
    }
    long long h=cal(l);
    for(int i=l+1;i<=r;i++)
        h=min(cal(i),h);
    printf("%I64d\n",h);
    return 0;
}

