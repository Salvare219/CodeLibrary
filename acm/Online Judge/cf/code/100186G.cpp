#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
using namespace std;

class point
{
    public:
    int val, pos;
    bool operator < (const point& p) const
    {
        if(val==p.val)
            return pos<p.pos;
        return val<p.val;
    }
}num[300010];

int main()
{
    freopen("input.txt","r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d", &num[i].val);
        num[i].pos = i;
    }
    sort(num+1, num+1+n);
    int ans, anss=1, anst=2;
    for(int i=2; i<=n; i++)
    {
        if((num[i].val^num[i-1].val)<ans)
        {
            ans = num[i].val^num[i-1].val;
            anss = num[i].pos;
            anst = num[i-1].pos;
        }
    }
    if (anss>anst)
        swap(anss, anst);
    printf("%d %d\n", anss, anst);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
