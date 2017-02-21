#include <iostream>
#include <map>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

#define MAXN 18
#define MAXM 100000
#define INF 1000000000

int n, m;

int dp[1 << 18][18];
pair<int, int> fr[1 << 18][18];

int dp2[1 << 18];
int tp[1 << 18];

int dp3[1 << 18];
int fm[1 << 18];

vector <int> road[1 << 18];

struct Edge {
    int y, nxt, val;
}e[MAXM];

int lst[MAXN], o;

int mp[18][18];

void add(int x, int y, int val) {
    e[o].y = y; e[o].nxt = lst[x]; e[o].val = val; lst[x] = o++;
}

void find_road(int x) {
    int st = x; int v = tp[x];
    while(st != 0) {
        road[x].push_back(v);
        int a = st;
        st = fr[st][v].first; v = fr[a][v].second;
    }
}

int dis[18];
int lot[18], ot;
int sta[18];
int fp[18];

queue <int> q;

void solve(int x) {
    ot = 0;
    for(int i = 0; i < n; i++) {
        if(x & (1 << i)) {
            lot[ot] = i;
            sta[ot++] = dp[x][i];
        }
    }
    /*
    for(int i = 0; i < ot; i++) {
        if(sta[i] == INF) continue;
        for(int j = 0; j < ot; j++) dis[j] = INF;
        dis[i] = 0;
        q.push(i);
        while(!q.empty()) {
            int a = q.front(); q.pop();
            int u = lot[a];
            for(int j = 0; j < ot; j++) {
                int v = lot[j];
                if(dis[j] > dis[a] + mp[u][v]) {
                    dis[j] = dis[a] + mp[u][v];
                    fp[j] = a;
                    q.push(j);
                }
            }
        }

        for(int j = 0; j < ot; j++) {
            if(i != j) {
                if(dp[x][lot[j]] > sta[i] + dis[j]) {
                    dp[x][lot[j]] = sta[i] + dis[j];
                    fr[x][lot[j]] = make_pair(x, lot[fp[j]]);
                }
            }
        }
    }*/

    for(int i = 0; i < ot; i++) {
        if(sta[i] == INF) continue;
        q.push(i);
        while(!q.empty()) {
            int a = q.front(); q.pop();
            int u = lot[a];
            for(int j = 0; j < ot; j++) {
                int v = lot[j];
                if(dp[x][v] > dp[x][u] + mp[u][v]) {
                    dp[x][v] = dp[x][u] + mp[u][v];
                    fr[x][v] = make_pair(x, u);
                    q.push(j);
                }
            }
        }
    }
}

int main() {
   
    freopen("immediate.in","r",stdin);
    freopen("immediate.out","w",stdout);

    scanf("%d%d", &n, &m);

    memset(lst,-1,sizeof(lst));
    o = 0;

    fr[1][1] = make_pair(0, 0);

    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) mp[i][j] = INF;
    for(int i = 0; i < n; i++) mp[i][i] = 0;

    for(int i = 1, a, b, c; i <= m; i++) {
        scanf("%d%d%d", &a, &b, &c);
        a--; b--;
        mp[a][b] = mp[b][a] = c;
        add(a, b, c);
        add(b, a, c);
    }

    for(int i = 0; i < (1 << n); i++) {
        dp2[i] = INF; dp3[i] = INF;
        for(int j = 0; j < n; j++) dp[i][j] = INF;
    }

    dp[1][0] = 0;
    for(int i = 1; i < (1 << n); i++) {
        solve(i);

        for(int j = 0; j < n; j++) {
            if(dp2[i] > dp[i][j]) {
                dp2[i] = dp[i][j];
                tp[i] = j;
            }
        }

        dp3[i] = dp2[i];
        fm[i] = i;

        for(int j = 0; j < n; j++) {
            if(dp[i][j] != INF) {
                for(int p = lst[j]; ~p; p = e[p].nxt) {
                    int v = e[p].y;
                    if(!(i & (1 << v))) {
                        if(dp[i | (1 << v)][v] > dp[i][j] + e[p].val) {
                            dp[i | (1 << v)][v] = dp[i][j] + e[p].val;
                            fr[i | (1 << v)][v] = make_pair(i, j);
                        }    
                    }
                }
            }
        }    
    }

    for(int i = 1; i < (1 << n); i++) {
        find_road(i);
    }

    for(int i = (1 << n) - 1; i >= 1; i--) {
        if(dp3[i] != INF) {
            for(int j = 0; j < n; j++) {
                if(i & (1 << j)) {
                    if(dp3[i ^ (1 << j)] > dp3[i]) {
                        dp3[i ^ (1 << j)] = dp3[i];
                        fm[i ^ (1 << j)] = fm[i];
                    }
                }
            }
        }
    }

    int ans = INF;

    int bi, bj;
    for(int i = 1; i < (1 << n); i++) {
        int j = (~i) & ((1 << n) - 1);
        if(ans > max(dp2[i], dp3[j])) {
            ans = max(dp2[i], dp3[j]);
            bi = i; bj = j;
        }
    }

    printf("%d\n", ans);

    printf("%d", road[bi].size() - 1);
    for(int i = road[bi].size() - 1; i >= 0; i--) {
        printf(" %d", road[bi][i] + 1);
    }
    printf("\n");
    bj = fm[bj];

    printf("%d", road[bj].size() - 1);
    for(int i = road[bj].size() - 1; i >= 0; i--) {
        printf(" %d", road[bj][i] + 1);
    }
    printf("\n");

    return 0;
}