#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int prim[60000],k;
bool vis[100055];
void cal()
{
    for(int i=2;i<100005;i++)
    {
        if(vis[i]==0) prim[k++]=i;
        for(int j=0;j<k && prim[j]*i<100005;j++)
        {
            vis[prim[j]*i]=1;
            if(i%prim[j]==0) break;
        }
    }
}
int a[7000],b[7000];
int gd[7000];
#include<set>
set<int>st;
int main()
{
//    freopen("1.txt","r",stdin);
    cal();
    int n,m,x;scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%d",a+i);
    for(int i=0;i<m;i++)
        scanf("%d",b+i),st.insert(b[i]);
    int sum=0;
    for(int i=0;i<n;i++)
    {
        int sb=a[i],con;
        for(int j=0;j<k;j++)
        {
            con=0;
            while(sb%prim[j]==0)
            {
                con++;
                sb/=prim[j];
            }
            if(con)
            {
                if(st.find(prim[j])!=st.end())sum-=con;
                else sum+=con;
            }
        }
        if(sb!=1)
        {
            if(st.find(sb)!=st.end())sum--;
            else sum++;
        }
    }
    int ans=sum,now=a[0];
    gd[0]=a[0];
    for(int i=1;i<n;i++)
        gd[i]=__gcd(gd[i-1],a[i]);
    int div=1;
    for(int i=n-1;i>-1;i--)
    {
        int sb=gd[i]/div;
        int te=0,con;
        for(int j=0;j<k;j++)
        {
            con=0;
            while(sb%prim[j]==0)
            {
                con++;
                sb/=prim[j];
            }
            if(con)
            {
                if(st.find(prim[j])!=st.end())te-=con;
                else te+=con;
            }
        }
        if(sb!=1)
        {
            if(st.find(sb)!=st.end())te--;
            else te++;
        }
        te*=i+1;
        if(te<0)
        {
            ans-=te;
            div=gd[i];
        }
    }
    printf("%d\n",ans);
    return 0;
}