#include <bits/stdc++.h>
using namespace std;
#define MAXN 1011

int _wa[MAXN], _wb[MAXN], _wv[MAXN], _ws[MAXN];

int _cmp(int *r, int a, int b, int l) {
    return r[a] == r[b] && r[a + l] == r[b + l];
}
void Get_Sa(int *r, int *sa, int n, int m) {
    int i, j, p, *x = _wa, *y = _wb, *t;
    for(i = 0; i < m; i++) _ws[i] = 0;
    for(i = 0; i < n; i++) _ws[x[i] = r[i]]++;
    for(i = 1; i < m; i++) _ws[i] += _ws[i - 1];
    for(i = n - 1; i >= 0; i--) sa[--_ws[x[i]]] = i;
    for(j = 1, p = 1; p < n; j <<= 1, m = p) {
        for(p = 0, i = n - j; i < n; i++) y[p++] = i;
        for(i = 0; i < n; i++) if(sa[i] >= j) y[p++] = sa[i] - j;
        for(i = 0; i < n; i++) _wv[i] = x[y[i]];
        for(i = 0; i < m; i++) _ws[i] = 0;
        for(i = 0; i < n; i++) _ws[_wv[i]]++;
        for(i = 1; i < m; i++) _ws[i] += _ws[i - 1];
        for(i = n - 1; i >= 0; i--) sa[--_ws[_wv[i]]] = y[i];
        for(t = x, x = y, y = t, p = 1, x[sa[0]] = 0, i = 1; i < n; i++)
        x[sa[i]] = _cmp(y, sa[i - 1], sa[i], j) ? p - 1 : p++;
    }
}

int rnk[MAXN], ht[MAXN];
void Get_H(int *r, int *sa, int n) {
    int i, j, k = 0;
    for(i = 0; i <= n; i++) rnk[sa[i]] = i;
    for(i = 0; i < n; ht[rnk[i++]] = k)
    for(k ? k-- : 0, j = sa[rnk[i] - 1]; r[i + k] == r[j + k]; k++);
}

int dp[MAXN][10], Log[MAXN];

void init() {
    Log[0] = 0; int now = 0;
    for(int i = 1; i < MAXN; i++) {
        if(i > (1 << (now + 1))) Log[i] = ++now;
        else Log[i] = now;
    }
}

void RMQ(int n) {
    for(int i = 1; i <= n; i++) dp[i][0] = ht[i];
    for(int j = 1; j < 10; j++) {
        for(int i = 1; i + (1 << (j - 1)) <= n; i++) {
            dp[i][j] = min(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int lcp(int a, int b) {
    if(a > b) swap(a, b);
    a++;
    if(a == b) return ht[a];
    int k = Log[b - a + 1];
    return min(dp[a][k], dp[b - (1 << k) + 1][k]);
}

char s[MAXN];
int sa[MAXN], pr[MAXN];

int to_num(int x) {
    if(x < 10) return 1;
    else if(x < 100) return 2;
    else return 3;
}

int Min_dp[MAXN][MAXN];

int dfs(int l, int r) {
    if(l > r) return 0;
    if(l == r) return 1;
    if(Min_dp[l][r] != -1) return Min_dp[l][r];
    int L, to;
    int tmp = r - l + 1;
    for(int j = l + 1; j <= r; j++) {
        int len = lcp(rnk[l], rnk[j]);
        len = min(len, r - j + 1);
        if(len >= j - l) {
            L = len / (j - l);
            to = j + L * (j - l) - 1;
            if(j - l != 1) {
                tmp = min(tmp, to_num(L + 1) + dfs(to + 1, r) + 2 + dfs(l, j - 1));
            } else {
                tmp = min(tmp, to_num(L + 1) + 1 + dfs(to + 1, r));
            }
        }
    }
    tmp = min(tmp, 1 + dfs(l + 1, r));
    return Min_dp[l][r] = tmp;
}

int main()
{
    //freopen("1.txt","r",stdin);

    init();
    int ti=1;
    while(scanf("%s", s)) {
        int len = strlen(s);
        if(len == 1 && s[0] == '0') break;

        for(int i = 0; i < len; i++) for(int j = i; j < len; j++) Min_dp[i][j] = -1;

        for(int i = 0; i < len; i++) {
            pr[i] = s[i] - 'a' + 1;
        }
        pr[len] = 0;

        Get_Sa(pr, sa, len + 1, 30);
        Get_H(pr, sa, len);
        RMQ(len);

        printf("Case %d: %d\n",ti++, dfs(0, len - 1));
    }
    return 0;
}
