#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

long long gcd(long long a, long long b)
{
    if (b==0)
        return a;
    return gcd(b, a%b);
}

pair<long long, long long> simplify(pair<long long, long long> p)
{
    if (p.first < 0 && p.second < 0)
    {
        p.first = - p.first;
        p.second = - p.second;
    }
    long long temp = gcd(p.first, p.second);
    return make_pair(p.first/temp, p.second/temp);
}

pair<long long,long long>po[10050],pt[10050],tp[10050];
int main()
{
    //freopen("1.txt","r",stdin);
    int n,m;
    long long x,y;
    scanf("%d%d",&n,&m);

    if(m==1)
    {
        for(int i=0;i<n;i++)
            puts("YES");
    }
    else
    {
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<m;j++)
            {
                scanf("%I64d%I64d",&x,&y);
                pt[j]=make_pair(x,y);
            }
            sort(pt,pt+m);
            x=pt[0].first;
            y=pt[0].second;
            for(int j=0;j<m;j++)
            {
                pt[j].first-=x;
                pt[j].second-=y;
            }
            if(i==0)
            {
                for(int j=0;j<m;j++)
                {
                    po[j]=pt[j];
                }
            }
            else
            {
                pair<long long, long long> zoom;
                for (int j=0; j<m; j++)
                    if (pt[j].first != 0)
                        zoom = simplify(make_pair(po[j].first, pt[j].first));
                    else if (pt[j].second != 0)
                        zoom = simplify(make_pair(po[j].second, pt[j].second));

                int f = 1;
                for (int j=0; j<m; j++)
                {
                    if (!((pt[j].first == 0 && po[j].first == 0) || (pt[j].first != 0 && po[j].first * pt[j].first >= 0 && zoom == simplify(make_pair(po[j].first, pt[j].first) ))) ) 
                        f = 0;
                    if (!((pt[j].second == 0 && po[j].second == 0) || (pt[j].second != 0 && po[j].second * pt[j].second >= 0 && zoom == simplify(make_pair(po[j].second, pt[j].second)))))
                        f = 0;
                }

                if(f)
                    puts("YES");
                else
                    puts("NO");
            }
        }
    }
    return 0;
}

