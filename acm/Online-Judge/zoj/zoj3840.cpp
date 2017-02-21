#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <queue>

using namespace std;

#define inf 2000000000
#define mo 100000007

int n, k;

struct Edge {
    int y, nxt, val;
}e[200101];

int lst[100101], o;

void add(int x, int y, int val) {
    e[o].y = y; e[o].nxt = lst[x]; e[o].val = val; lst[x] = o++;
}

long long C[12][12];

void init() {
    C[0][0] = C[1][0] = C[1][1] = 1;
    for(int i = 2; i <= 10; i++) {
        C[i][0] = C[i][i] = 1;
        for(int j = 1; j < i; j++) {
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
            C[i][j] %= mo;
        }
    }
}

long long son[100101][12];
long long far[100101][12];

void dfs1(int x, int fa) {
    for(int p = 0; p <= k; p++) son[x][p] = 0;
    for(int i = lst[x]; ~i; i = e[i].nxt) {
        int v = e[i].y; 
        long long w = e[i].val;
        long long wp = 1;
        if(v == fa) continue;
        dfs1(v, x);
        for(int p = 0; p <= k; p++) {
            wp = 1;
            for(int j = 0; j <= p; j++) {
                long long a = (son[v][p - j] * wp) % mo;
                son[x][p] += (a * C[p][j]) % mo;
                son[x][p] %= mo;
                wp *= w;
                wp %= mo;
            }
        }
        wp = 1;
        for(int p = 0; p <= k; p++) {
            son[x][p] += wp;
            son[x][p] %= mo;
            wp *= w;
            wp %= mo;
        }
    }
}


void dfs2(int x, int fa) {
    long long pp[11] = {};
    long long cost[11] = {};
    for(int i = 0; i <= k; i++) pp[i] = (far[x][i] + son[x][i]) % mo;


    for(int i = lst[x]; ~i; i = e[i].nxt) {
        int v = e[i].y;
        long long w = e[i].val, wp = 1;
        if(v == fa) continue;
        for(int p = 0; p <= k; p++) {
            far[v][p] = wp;
            wp *= w;
            wp %= mo;
        }
        for(int p = 0; p <= k; p++) cost[p] = pp[p];

        for(int p = 0; p <= k; p++) {
            wp = 1;
            for(int j = 0; j <= p; j++) {
                long long a = (son[v][p - j] * wp) % mo;
                cost[p] -= (a * C[p][j]) % mo;
                cost[p] %= mo;
                wp *= w;
                wp %= mo;
            }
        }
        wp = 1;
        for(int p = 0; p <= k; p++) {
            cost[p] -= wp;
            cost[p] %= mo;
            wp *= w;
            wp %= mo;
        }

        for(int p = 0; p <= k; p++) {
            wp = 1;
            for(int j = 0; j <= p; j++) {
                long long a = (cost[p - j] * wp) % mo;
                far[v][p] += (a * C[p][j]) % mo;
                far[v][p] %= mo;
                wp *= w;
                wp %= mo;
            }
        }
        dfs2(v, x);
    }
}

int main() {
    //freopen("pro.in","r",stdin);

    init();

    while(scanf("%d%d", &n, &k) != EOF) {
        for(int i = 1; i <= n; i++) lst[i] = -1;
        o = 0;
        for(int i = 1, a, b, c; i < n; i++) {
            scanf("%d%d%d", &a, &b, &c);
            a++; b++;
            add(a, b, c);
            add(b, a, c);
        }

        dfs1(1, 0);

        dfs2(1, 0);

        long long ans = ((far[1][k] + son[1][k]) % mo + mo) % mo;
        for(int i = 2; i <= n; i++) {
            ans = min(ans, ((far[i][k] + son[i][k]) % mo + mo) % mo);
        }

        //if(ans < 0) while(1);

        printf("%lld\n", ans);
    }

    return 0;
}