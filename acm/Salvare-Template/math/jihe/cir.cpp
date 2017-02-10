#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

const double eps=1e-9;
int sgn(double x)
{
    return fabs(x)<eps?0:(x>0.0?1:-1);
}
struct p
{
    double x,y,r;
}po[50050];
int n;
pair<double,int>pa[50050],pb[50050];
#include<set>
struct sp
{
    int i;
    sp(int k=0){i=k;}
    bool operator<(const sp&a)const{return sgn(po[i].y-po[a.i].y)?po[i].y<po[a.i].y:po[i].x<po[a.i].x;}
};
inline bool cross(p a,p b,double mid)
{
    return sgn(sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y))-a.r-b.r-mid*2)<0;
}
set<sp>::iterator it,itt;
set<sp>st;
inline bool ok(double mid)
{
    int p=0,a,b;
    st.clear();
    for(int i=0;i<=n;i++)
    {
        while(p<n&&pb[p].first+mid<pa[i].first-mid)
        {
            it=itt=st.find(sp(pb[p++].second));
            itt++;
            if(it!=st.begin()&&itt!=st.end())
            {
                a=(--it)->i;
                b=itt->i;
                if(cross(po[a],po[b],mid))return 1;
            }
            st.erase(--itt);
        }
        st.insert(sp(b=pa[i].second));
        it=itt=st.find(sp(b));
        if(it!=st.begin())
        {
            a=(--it)->i;
            if(cross(po[a],po[b],mid))return 1;
        }
        itt++;
        if(itt!=st.end())
        {
            a=itt->i;
            if(cross(po[a],po[b],mid))return 1;
        }
    }
    return 0;
}
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%lf%lf%lf",&po[i].x,&po[i].y,&po[i].r);
        for(int i=0;i<n;i++)
        {
            pa[i]=make_pair(po[i].x-po[i].r,i);
            pb[i]=make_pair(po[i].x+po[i].r,i);
        }
        sort(pa,pa+n);sort(pb,pb+n);
        pa[n]=make_pair(1e10,n);
        pb[n]=make_pair(1e10,n);
        double l=0,r=1e5,mid;
        while(r-l>1e-7)
        {
            mid=(l+r)/2;
            if(ok(mid))r=mid;
            else l=mid;
        }
        printf("%.6f\n",r*2);
    }
    return 0;
}
