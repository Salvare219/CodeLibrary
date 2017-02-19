#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

char a[1005][1005];
pair<int,int> r[1005][1005];
unsigned s[1005][1005];
const int tx[]={0,1},ty[]={1,0};
int n,m,ex[26],ey[26],sn;
pair<int,int> ans[2005];

inline void go(int x,int y,int t)
{
    unsigned s0=s[x][y];
    if(s0==-1)
        return;
    for(int i=0;i<2;i++)
    {
        int x1=x+tx[i],y1=y+ty[i];
        if(x1>=n||y1>=m)
            continue;
        unsigned s1=0;
        if(a[x1][y1]>='a'&&a[x1][y1]<='z')
            s1=a[x][y]==a[x1][y1]?s0+1:1;
        if(s1<=t&&s1<s[x1][y1])
        {
            s[x1][y1]=s1;
            r[x1][y1]=make_pair(x,y);
        }
    }
}

inline bool judge(int t)
{
    memset(s,-1,sizeof(s));
    int i,j,k;
    s[0][0]=0;
    for(i=0;i<n+m;i++)
        for(k=min(i,n-1),j=max(0,i-m+1);j<=k;j++)
            go(j,i-j,t);
    return s[n-1][m-1]!=-1;
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int i,j;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
    {
        scanf("%s",a[i]);
        for(j=0;j<m;j++)
            if(a[i][j]>='a'&&a[i][j]<='z')
                ex[a[i][j]-'a']=i,ey[a[i][j]-'a']=j;
    }
    //
    int s = 0, t = n+m;
    while (s<t)
    {
        int h = (s+t)/2;
        if (judge(h))
            t = h;
        else
            s = h+1;
    }
    judge(s);
    i=n-1,j=m-1;
    ans[sn++]=make_pair(i,j);
    while(i+j)
    {
        ans[sn]=r[i][j];
        i=ans[sn].first;
        j=ans[sn].second;
        sn++;
    }
    printf("%d\n",s);
    for(i=sn;i--;)
        printf("%d %d\n",ans[i].first+1,ans[i].second+1);
    return 0;
}
