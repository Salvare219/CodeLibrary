#include <stdio.h>
#include <set>
#include <string>
#include <string.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <vector>
using namespace std;

#define INF 200000000
#define tl(x) (x << 1)
#define tr(x) (x << 1 | 1)
#define MAXN 500100



typedef unsigned long long ULL;

int n, m;

ULL sed = 13131;

ULL fr[MAXN], ra[MAXN], fox[MAXN];

ULL Fr[MAXN], Ra[MAXN];

char s[MAXN];

void upd1(int pos, ULL a) {
    while(pos <= n) {
        Fr[pos] += a;
        pos += pos & -pos;
    }
}

void upd2(int pos, ULL a) {
    while(pos <= n) {
        Ra[pos] += a;
        pos += pos & -pos;
    }
}

ULL qry1(int pos) {
    ULL res = 0;
    while(pos > 0) {
        res += Fr[pos];
        pos -= pos & -pos;
    }
    return res;
}

ULL qry2(int pos) {
    ULL res = 0;
    while(pos > 0) {
        res += Ra[pos];
        pos -= pos & -pos;
    }
    return res;
}

char tra[3], tmp;

void solve1(int x) {
    int l = 1, r = min(x - 1, n - x), mid, ll, rr, ans = 1;
    ULL a1, a2;
    while(l <= r) {
        mid = l + r >> 1;
        ll = x - mid; rr = x + mid;
        a1 = qry1(x - 1) - qry1(ll - 1);
        a2 = qry2(n - x) - qry2(n - rr);

        if(n - rr + 1 > ll) {
            a1 *= fox[n - rr + 1 - ll];
        } else a2 *= fox[ll - n + rr - 1];

        if(a1 == a2) {
            ans = mid * 2 + 1;
            l = mid + 1;
        } else r = mid - 1;
    }
    printf("%d\n", ans);
}

void solve2(int x) {
    int l = 1, r = min(x, n - x), mid, ll, rr, ans = -1;
    ULL a1, a2;
    while(l <= r) {
        mid = l + r >> 1;
        ll = x - mid + 1; rr = x + mid;

        a1 = qry1(x) - qry1(ll - 1);
        a2 = qry2(n - x) - qry2(n - rr);

        if(n - rr + 1 > ll) {
            a1 *= fox[n - rr + 1 - ll];
        } else a2 *= fox[ll - n + rr - 1];

        if(a1 == a2) {
            ans = mid * 2;
            l = mid + 1;
        } else r = mid - 1;

    }

    printf("%d\n", ans); 
}

int main()
{
    //freopen("pro.in","r",stdin);

    scanf("%s%d", s + 1, &m);

    n = strlen(s + 1);

    fox[0] = 1;
    for(int i = 1; i <= n; i++) {
        fox[i] = fox[i - 1] * sed;
    }

    for(int i = 1; i <= n; i++) {
        int a = s[i] - 'a' + 1;
        upd1(i, a * fox[i]);
        upd2(n - i + 1, a * fox[n - i + 1]);
    }

    while(m--) {
        int a, b;
        scanf("%d", &a);
        if(a == 1) {
            scanf("%d%s", &b, tra);
            int a = s[b] - 'a' + 1;
            upd1(b, - a * fox[b]);
            upd2(n - b + 1, - a * fox[n - b + 1]);

            s[b] = tra[0];
            a = s[b] - 'a' + 1;
            upd1(b, a * fox[b]);
            upd2(n - b + 1, a * fox[n - b + 1]);
        } else if(a == 2) {
            scanf("%d", &b);
            solve1(b);
        } else if(a == 3) {
            scanf("%d", &b);
            solve2(b);
        }
    }

    return 0;
}
