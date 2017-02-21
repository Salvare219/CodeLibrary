#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
using namespace std;


#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
using namespace std;

#define eps 1e-8
#define LL long long
#define mod 1000000007
#define mxn 100005
#define mxe 310010

int dcmp( double x ) {
    return (x > eps) - (x < -eps);
}

struct point {
    double x, y;
    int id;
    struct Edge *e;
    bool operator < (const point & p) const {
        return dcmp(x - p.x) != 0 ? x < p.x : dcmp(y - p.y) < 0;
    }
    bool operator == (const point & p) const {
        return dcmp(x - p.x) == 0 && dcmp(y - p.y) == 0;
    }
    void input( int i ) {
        id = i;
        scanf( "%lf%lf", &x, &y );
    }
}pnt[mxn];

double cross(point & o, point & a, point & b) {
    return (a.x - o.x) * (b.y - o.y) - (b.x - o.x) * (a.y - o.y);
}

double dot(point & o, point & a, point & b) {
    return (a.x - o.x) * (b.x - o.x) + (a.y - o.y) * (b.y - o.y);
}

double dis( point a, point b ) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

struct Edge {
    point *o, *d;
    Edge *on, *op, *dn, *dp;
};

#define Op(e,p)    ((e)->o==p?(e)->d:(e)->o)
#define Next(e,p)  ((e)->o==p?(e)->on:(e)->dn)
#define Prev(e,p)  ((e)->o==p?(e)->op:(e)->dp)
struct Delaunay {
    void solve(point * ps, int n) {
        edge_num = 0;
        rubb = NULL;

        for(int i = 0; i < n; i ++) ps[i].e = NULL;
        Edge* l_cw, *r_ccw;
        divide(ps, 0, n, l_cw, r_ccw);
    }
    Edge es[mxe], * rubb;
    int edge_num;
    Edge *make_edge(point &u, point &v) {
        Edge * e;
        if(rubb==NULL) {
            e = es + edge_num++;
        } else {
            e = rubb;
            rubb = rubb->dn;
        }
        e->on=e->op=e->dn=e->dp=e;
        e->o=&u;    e->d=&v;
        if (u.e==NULL) u.e=e;
        if (v.e==NULL) v.e=e;
        return e;
    }

    void delete_edge(Edge *e) {
        point *u=e->o, *v=e->d;
        if (u->e==e) u->e=e->on;
        if (v->e==e) v->e=e->dn;
        Prev(e->on, u) = e->op;
        Next(e->op, u) = e->on;
        Prev(e->dn, v) = e->dp;
        Next(e->dp, v) = e->dn;
        e->dn = rubb;
        rubb = e;
    }

    void splice(Edge *a, Edge *b, point *v) {
        Edge *n;
        n=Next(a, v);    Next(a, v)=b;
        Prev(n, v) = b;
        Next(b, v)=n;    Prev(b, v)=a;
    }

    Edge *join(Edge *a, point *u, Edge *b, point *v, int s) {
        Edge *e = make_edge(*u, *v);
        if (s == 0) {
            splice(Prev(a,u), e, u);
            splice(b, e, v);
        } else {
            splice(a, e, u);
            splice(Prev(b, v), e, v);
        }
        return e;
    }

    void lower_tangent(Edge * & l, Edge * & r, point * & s, point * & u){
        point *dl=Op(l,s), *dr=Op(r,u);
        while(1) {
            if (dcmp(cross((*s),(*dl),(*u))) > 0) {
                l=Prev(l,dl);    s=dl;    dl=Op(l,s);
            } else if (dcmp(cross((*u),(*dr),(*s))) < 0) {
                r=Next(r,dr);    u=dr;    dr=Op(r,u);
            } else break;
        }
    }

    void merge(Edge *r_cw_l, point *s, Edge *l_ccw_r, point *u, Edge **l_tangent){
        Edge *b, *lc, *rc;
        point *dlc, *drc;
        double crc, clc;

        lower_tangent(r_cw_l, l_ccw_r, s, u);
        b = join(r_cw_l, s, l_ccw_r, u, 1);

        *l_tangent = b;

        do{
            lc=Next(b,s); rc=Prev(b,u); dlc=Op(lc,s); drc=Op(rc,u);

            double cplc = cross(*dlc, *s, *u);
            double cprc = cross(*drc, *s, *u);

            bool alc = dcmp(cplc)>0, arc = dcmp(cprc)>0;
            if (!alc && !arc) break;
            if (alc){
                clc = dot(*dlc, *s, *u) / cplc;
                do{
                    Edge * next = Next(lc, s);
                    point & dest = * Op(next, s);
                    double cpn = cross(dest, *s, *u);
                    if(dcmp(cpn)<=0)    break;

                    double cn = dot(dest, *s, *u) / cpn;
                    if (dcmp(cn-clc)>0) break;
                    delete_edge(lc);
                    lc = next;
                    clc = cn;
                } while(1);
            }
            if (arc) {
                crc = (double)dot(*drc, *s, *u) / cprc;
                do{
                    Edge * prev = Prev(rc, u);
                    point & dest = * Op(prev, u);
                    double cpp = cross(dest, *s, *u);
                    if(dcmp(cpp) <= 0)    break;

                    double cp = dot(dest, *s, *u) / cpp;
                    if (dcmp(cp - crc) > 0) break;
                    delete_edge(rc);
                    rc = prev;
                    crc = cp;
                } while (1);
            }
            dlc = Op(lc, s); drc = Op(rc, u);
            if (!alc || (alc && arc && dcmp(crc - clc) < 0)){
                b = join(b, s, rc, drc, 1);
                u = drc;
            } else {
                b = join(lc, dlc, b, u, 1);
                s = dlc;
            }
        } while(1);
    }

    void divide(point *p, int l, int r, Edge * & l_ccw, Edge * & r_cw) {
        int n=r-l;
        Edge *l_ccw_l, *r_cw_l, *l_ccw_r, *r_cw_r, *l_tangent, *c;
        if (n == 2) {
            l_ccw = r_cw = make_edge(p[l], p[l+1]);
        }
        else if (n == 3) {
            Edge * a = make_edge(p[l], p[l+1]), *b = make_edge(p[l+1], p[l+2]);
            splice(a,b,&p[l+1]);
            double c_p = cross(p[l], p[l+1], p[l+2]);
            if (dcmp(c_p)>0) {
                c = join(a, &p[l], b, &p[l+2], 1); l_ccw = a; r_cw = b;
            }
            else if (dcmp(c_p) < 0) {
                c = join(a, &p[l], b, &p[l+2], 0); l_ccw = c; r_cw = c;
            }
            else {
                l_ccw = a; r_cw = b;
            }
        }
        else if (n > 3) {
            int split = (l + r) / 2;
            divide(p, l, split, l_ccw_l, r_cw_l);
            divide(p, split, r, l_ccw_r, r_cw_r);
            merge(r_cw_l, &p[split-1], l_ccw_r, &p[split], &l_tangent);
            if(l_tangent->o == &p[l]) l_ccw_l = l_tangent;
            if(l_tangent->d == &p[r-1]) r_cw_r = l_tangent;
            l_ccw = l_ccw_l; r_cw = r_cw_r;
        }
    }
} de;

struct Kedge {
    int u, v;
    double d;
    bool operator < (const Kedge &b) const {
        return d < b.d;
    }
}ke[mxe];

int first[mxn], vv[mxe], nxt[mxe], e;
double cost[mxe];

void add( int u, int v, double c ) {
    vv[e] = v; cost[e] = c; nxt[e] = first[u]; first[u] = e++;
}

void addEdge( int &i, int u, int v, double d ) {
    ke[i].u = u; ke[i].v = v; ke[i].d = d;
    ++i;
}

void getEdge( int &k, int n ) {
    k = 0;
    Edge *st, *cur;
    point *u, *v;
    for( int i = 0; i < n; ++i ) {
        u = &pnt[i];
        st = cur = u->e;
        do {
            v = Op(cur, u);
            if( u < v )
                addEdge(k, u->id, v->id, dis(*u, *v));
        }while((cur = Next(cur, u)) != st);
    }
}

int fa[mxn];

int find( int x ) {
    return x == fa[x] ? fa[x] : fa[x] = find(fa[x]);
}
vector<pair<int,int> >ans;
void Kruskal( int m, int n ) {
    memset( first, -1, sizeof(first) ); e = 0;
    sort(ke, ke + m);
    for( int i = 0; i < m; ++i ) {
        int fu = find(ke[i].u);
        int fv = find(ke[i].v);
        if( fu == fv ) continue;
        ans.push_back(make_pair(ke[i].u,ke[i].v));
        fa[fu] = fv;
        add( ke[i].u, ke[i].v, ke[i].d );
        add( ke[i].v, ke[i].u, ke[i].d );
    }
}

int main()
{
    int n, m, u, v, k;
    scanf( "%d", &n );
    if(n==1);
    else
    {
        for( int i = 0; i < n; ++i ) pnt[i].input(i + 1);
        sort(pnt, pnt + n);
        int s;scanf("%d",&s);
        for( int i = 1; i <= n; ++i ) fa[i] = i;
        for(int i=0;i<s;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            fa[find(x)]=find(y);
        }
        de.solve(pnt, n);
        getEdge(k, n);
        Kruskal(k, n);
        for(int i=0;i<ans.size();i++)
            printf("%d %d\n",ans[i].first,ans[i].second);
    }
    return 0;
}
