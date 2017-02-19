#include<bits/stdc++.h>

using namespace std;

#define MAXN 200010
#define MAXM 20100
#define INF 1e15

int w, h, n;

struct Node {
    int x, y;
}bx[20], rob, tmp;

bool sigl[1 << 18];

void init() {
    for(int i = 0; i < 18; i++) {
        sigl[1 << i] = 1;
    }
}

double dp[1 << 18][18];

double cal1(Node a, Node b) {
    long long c = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
    return sqrt((double)c);
}

double cal2(Node a, Node b) {
    tmp.x = a.x; tmp.y = -a.y;
    double res = cal1(tmp, b);

    tmp.x = -a.x; tmp.y = a.y;
    res = min(res, cal1(tmp, b));

    tmp.x = a.x; tmp.y = 2 * h - a.y;
    res = min(res, cal1(tmp, b));

    tmp.x = 2 * w - a.x; tmp.y= a.y;
    res = min(res, cal1(tmp, b));

    return res;
}

int cal3(Node a) {
    int res = a.x;
    res = min(res, a.y);
    res = min(res, h - a.y);
    res = min(res, w - a.x);
    return res;
}

int main()
{
    freopen("kitchen.in","r",stdin);
    freopen("kitchen.out","w",stdout);
    //freopen("pro.in","r",stdin);

    init();

    scanf("%d%d", &w, &h);
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d%d", &bx[i].x, &bx[i].y);
    }

    scanf("%d%d", &rob.x, &rob.y);

    for(int i = 0; i < (1 << n); i++) for(int j = 0; j < n; j++) dp[i][j] = INF;

    for(int i = 0; i < (1 << n); i++) {
        if(sigl[i]) {
            for(int j = 0; j < n; j++) {
                if(i & (1 << j)) dp[i][j] = cal1(rob, bx[j]);
            }
        } else {
            for(int j = 0; j < n; j++) {
                if(i & (1 << j)) {
                    for(int k = 0; k < n; k++) {
                        if((i & (1 << k)) && j != k) {
                            dp[i][j] = min(dp[i][j], dp[i ^ (1 << j)][k] + cal2(bx[k], bx[j]));
                        }
                    }
                }
            }
        }
    }

    double ans = INF;
    for(int i = 0; i < n; i++) {
        ans = min(ans, dp[(1 << n) - 1][i] + cal3(bx[i]));
    }
    printf("%.10f\n", ans);

    return 0;
}