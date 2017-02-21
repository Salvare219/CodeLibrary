#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


struct p
{
    int x,y;
    bool operator<(const p&a)const
    {
        return x!=a.x?x<a.x:y<a.y;
    }
}po[1000000];
#include<set>
set<pair<int,int> >s;
int main()
{
    int n,m,k;scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<k;i++)
        scanf("%d%d",&po[i].x,&po[i].y);
    int cnt=0;
    for(int i=1;i<=n;i++)
        po[k].x=i,po[k++].y=m+1;
    for(int i=1;i<=m;i++)
        po[k].x=n+1,po[k++].y=i;
    sort(po,po+k);
    for(int i=0;i<k;)
    {
        int p=i,las=0;
        while(i<k&&po[p].x==po[i].x)
        {
            if(po[i].y-las>2)cnt++;
            if(po[i].y-las==2)s.insert(make_pair(po[i].y-1,po[i].x));
            las=po[i++].y;
        }
    }
    for(int i=0;i<k;i++)swap(po[i].x,po[i].y);
    sort(po,po+k);
    for(int i=0;i<k;)
    {
        int p=i,las=0;
        while(i<k&&po[p].x==po[i].x)
        {
            if(po[i].y-las>2)cnt++;
            if(po[i].y-las==2)
            {
                if(s.find(make_pair(po[i].x,po[i].y-1))!=s.end())cnt++;
            }
            las=po[i++].y;
        }
    }

    printf("%d\n",cnt);
	return 0;
}