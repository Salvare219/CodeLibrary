#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

struct p
{
    int x,y;
    bool operator<(const struct p&a)const
    {
        return x==a.x?y<a.y:x<a.x;
    }
}po[100005];
vector<int>px[100005],py[100005];
bool ok(int x,int y)
{
    if(x>100001||y>100001)return 0;
    if(px[x].size()==0||py[y].size()==0)return 0;
    int l=0,r=px[x].size()-1,mid;
    if(px[x][r]<y)return 0;
    while(r>l)
    {
        mid=(l+r)>>1;
        if(px[x][mid]>=y)r=mid;
        else l=mid+1;
    }
    if(px[x][r]==y)return 1;
    else return 0;
}
int main()
{
//    freopen("1.txt","r",stdin);
    int n,x,y;scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&x,&y);
        po[i].x=x;po[i].y=y;
        px[x].push_back(y);
        py[y].push_back(x);
    }
    sort(po,po+n);
    for(int i=0;i<100001;i++)
    {
        sort(px[i].begin(),px[i].end());
        sort(py[i].begin(),py[i].end());
    }
    int te,cnt=0;
    for(int i=0;i<n;i++)
    {
        x=po[i].x;y=po[i].y;
        if(px[x].size()>py[y].size())
        {
            for(int j=0;j<py[y].size();j++)
                if(py[y][j]>x)
                {
                    te=py[y][j]-x;
                    if(ok(x,y+te)&&ok(x+te,y+te))cnt++;
                }
        }
        else
        {
            for(int j=0;j<px[x].size();j++)
                if(px[x][j]>y)
                {
                    te=px[x][j]-y;
                    if(ok(x+te,y)&&ok(x+te,y+te))cnt++;
                }
        }
    }
    printf("%d\n",cnt);
    return 0;
}
