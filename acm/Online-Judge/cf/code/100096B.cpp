#include<bits/stdc++.h>
using namespace std;

queue<pair<int,int> > q;
int a[30],s[100005][30],n,z,mx;

inline void add(int x,int y,int d)
{
    if(x<0||x>mx)
        return;
    if(x==z||a[y]==z)
    {
        printf("%d\n",d);
        exit(0);
    }
    if(!s[x][y])
    {
        s[x][y]=d+1;
        q.push(make_pair(x,y));
    }
}

int main()
{
    freopen("cylinders.in","r",stdin);
    freopen("cylinders.out","w",stdout);
    int i;
    for(scanf("%d",&n),i=0;i<n;i++)
        scanf("%d",a+i);
    mx=a[n-1];
    scanf("%d",&z);
    s[0][0]=1;
    q.push(make_pair(0,0));
    while(!q.empty())
    {
        int x=q.front().first,y=q.front().second;
        int d=s[x][y];
        y=a[y];
        q.pop();
        for(i=0;i<n;i++)
        {
            add(x,i,d);
            add(y,i,d);
            add(x+y-a[i],i,d);
        }
    }
    puts("IMPOSSIBLE");
    return 0;
}
