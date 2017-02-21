#include <iostream>
#include <map>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

#define mod 1000000009

int n, m;

char s[1000010];
int o;

string ax[1000010];
int cnt;

void init() {
    int len = strlen(s);
    string res = "";
    for(int i = 0; i < len; i++) {
        if(s[i] >= 'A' && s[i] <= 'Z') s[i] = s[i] - 'A' + 'a';
        if(s[i] >= 'a' && s[i] <= 'z') {
            res += s[i];
        } else {
            if(res != "") ax[++cnt] = res;
            res = "";
        }
    }
    if(res != "") ax[++cnt] = res;
}

map <string, int> to;
int tot;

map <int, bool> tra;

map <int, int> s_ans;
map <pair<int, int>, int> d_ans;

int main() {

    scanf("%d", &n);

    gets(s);

    for(int i = 1; i <= n; i++) {
        gets(s + o); 
        int len = strlen(s + o);
        o += len;
        s[o++] = ' ';
    }

    init();

    for(int i = 1; i <= cnt; i++) {
        if(to[ax[i]] == 0) {
            to[ax[i]] = ++tot;
        }
    }

    scanf("%d", &m);
    for(int i = 1; i <= m; i++) {
        scanf("%s", s);
        ax[0] = s;
        if(to.find(ax[0]) != to.end()) {
            tra[to[ax[0]]] = 1;
        }
    }

    o = 0;
    for(int i = 1; i <= cnt; i++) {
        if(tra.find(to[ax[i]]) == tra.end()) {
            ax[++o] = ax[i];
            s_ans[to[ax[i]]]++;
        }
    }

    string res = "";
    for(int i = 1; i < o; i++) {
        d_ans[make_pair(to[ax[i]], to[ax[i + 1]])]++;
    }

    scanf("%d", &m);

    string r1, r2;
    for(int i = 1; i <= m; i++) {
        scanf("%s", s); r1 = s;
        scanf("%s", s); r2 = s;
        long long sum1 = 0, sum2 = 1;
        pair <int, int> a = make_pair(to[r1], to[r2]), b = make_pair(to[r2], to[r1]);

        sum1 = d_ans[a];
        if(a != b) sum1 += d_ans[b];

        sum2 = (long long)s_ans[to[r1]] * s_ans[to[r2]];

        double ans = (double)sum1 * o * o / sum2 / (o - 1);

        printf("%.10f\n", ans);
    }

    return 0;
}