#include <iostream>
#include <map>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

int n, m, k;

struct Human {
    int score, trait, id;
}bx[10010];

int to[10010];

vector <int> tp[1024][1024];

int cmp(const Human & a, const Human & b) {
    if(a.score > b.score) return 1;
    else return 0;
}

int main() {

    scanf("%d%d", &n, &k);

    for(int i = 0, a; i < n; i++) {
        scanf("%d", &bx[i].score);
        bx[i].trait = 0;
        bx[i].id = i;
        scanf("%d", &a);
        for(int j = 1, b; j <= a; j++) {
            scanf("%d", &b); b--;
            bx[i].trait |= (1 << b);
        }
    }

    sort(bx, bx + n, cmp);

    for(int i = 0; i < n; i++) to[bx[i].id] = i;

    for(int i = 0; i < (1 << k); i++) {
        for(int j = 0, a, b; j < n; j++) {
            a = i & bx[j].trait;
            tp[i][a].push_back(bx[j].score);
        }
    }

    scanf("%d", &m);

    while(m--) {
        int x, t;
        scanf("%d%d", &x, &t); x--;
        int res = 0;
        for(int i = 1, a; i <= t; i++) {
            scanf("%d", &a);
            a--; res |= (1 << a);
        }
        int a = to[x], b = res & bx[a].trait;
        int l = 0, r = tp[res][b].size() - 1, mid, ans;
        int sta = bx[a].score;
        while(l <= r) {
            mid = l + r >> 1;
            if(tp[res][b][mid] <= sta) {
                ans = mid; r = mid - 1;
            } else l = mid + 1;
        }
        printf("%d\n", ans + 1);
    }

    return 0;
}