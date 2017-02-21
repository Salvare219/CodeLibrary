#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <queue>

using namespace std;

#define inf 2000000000

int T;
long long L, R, C;
int K;

long long dp1[37][70][2][2];
long long dp2[37][70][2][2];
long long dp3[37][70][2][2];

int up[37], down[37];
int num[37];

long long dfs1(int pos, int k, int u, int d) {
    if(pos < 0) {
        k -= 32;
        if(abs(k) <= K) return 1;
        else return 0;
    }
    if(dp1[pos][k][u][d] != -1) return dp1[pos][k][u][d];
    long long res = 0;
    int mx = u ? (up[pos] & num[pos]) : num[pos];
    int mi = d ? down[pos] : 0;
    for(int i = mi, a, b; i <= mx; i++) {
        a = k + (i == 0 ? 1 : -1);
        b = a - 32;
        if(b < 0 && b + pos < -K) continue;
        if(b > 0 && b - pos > K) continue;
        res += dfs1(pos - 1, a, u & (i == up[pos]), d & (i == down[pos]));
    }
    return dp1[pos][k][u][d] = res;
}

long long dfs2(int pos, int k, int u, int d) {
    if(pos < 0) {
        k -= 32;
        if(abs(k) <= K) return 1;
        else return 0;
    }
    if(dp2[pos][k][u][d] != -1) return dp2[pos][k][u][d];
    long long res = 0;
    int mx = u ? up[pos] : 1;
    int mi = d ? down[pos] : 0;
    for(int i = mi, a, b; i <= mx; i++) {
        a = k + (i == 0 ? 1 : -1);
        b = a - 32;
        if(b < 0 && b + pos < -K) continue;
        if(b > 0 && b - pos > K) continue;
        res += dfs2(pos - 1, a, u & (i == up[pos]), d & (i == down[pos]));
    }
    return dp2[pos][k][u][d] = res;
}

long long dfs3(int pos, int k, int u, int d) {
    if(pos < 0) {
        k -= 32;
        if(abs(k) <= K) return 1;
        else return 0;
    }
    if(dp3[pos][k][u][d] != -1) return dp3[pos][k][u][d];
    long long res = 0;
    int mx = u ? up[pos] : 1;
    int mi = d ? (down[pos] | num[pos]) : num[pos];
    for(int i = mi, a, b; i <= mx; i++) {
        a = k + (i == 0 ? 1 : -1);
        b = a - 32;
        if(b < 0 && b + pos < -K) continue;
        if(b > 0 && b - pos > K) continue;
        res += dfs3(pos - 1, a, u & (i == up[pos]), d & (i == down[pos]));
    }
    return dp3[pos][k][u][d] = res;
}

int main() {

    scanf("%d", &T);
    int cas = 1;
    while(T--) {
        scanf("%lld%lld%lld%d", &L, &R, &C, &K);
        memset(num,0,sizeof(num));
        memset(up,0,sizeof(up));
        memset(down,0,sizeof(down));
        memset(dp1,-1,sizeof(dp1));
        memset(dp2,-1,sizeof(dp2));
        memset(dp3,-1,sizeof(dp3));

        int o = 0;
        long long cc = C;
        while(cc) {
            num[o++] = cc & 1;
            cc >>= 1;
        }

        o = 0;
        cc = L;
        while(cc) {
            down[o++] = cc & 1;
            cc >>= 1;
        }

        o = 0;
        cc = R;
        while(cc) {
            up[o++] = cc & 1;
            cc >>= 1;
        }

        long long ans1 = dfs1(31, 32, 1, 1);
        long long ans2;
        if(C == 0) ans2 = dfs2(31, 32, 1, 1);
        else ans2 = 0;
        long long ans3 = dfs3(31, 32, 1, 1);

        printf("Case %d: %lld %lld %lld\n", cas++, ans1, ans2, ans3);
    }

    return 0;
}