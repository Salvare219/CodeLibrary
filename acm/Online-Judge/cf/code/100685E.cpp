#include <iostream>
#include <map>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

#define eps 1e-8

int n;
double bx[10010];

struct Node {
    double val;
    int id[2];
    int cnt;
}p[10010], np[10010];

int o1, o2;

int cmp(const Node & a, const Node & b) {
    if(fabs(a.val - b.val) < eps) {
        if(a.cnt < b.cnt) return 1;
        else return 0;
    } else if(a.val > b.val + eps) return 1;
    else return 0;
}

vector <int> ans;

int main() {
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) {
        scanf("%lf", &bx[i]);
    }

    int is = 0;
    for(int i = 1; i <= n; i++) {
        if(bx[i] > 0) {
            p[++o1].val = bx[i];
            p[o1].cnt = 1;
            p[o1].id[0] = i;
        } else if(bx[i] < 0) {
            np[++o2].val = bx[i];
            np[o2].cnt = 1;
            np[o2].id[0] = i;
        } else {
            is = i;
        }
    }

    sort(np + 1, np + 1 + o2, cmp);

    for(int i = o2; i > 1; i -= 2) {
        double a = np[i].val * np[i - 1].val;
        p[++o1].val = a;
        p[o1].cnt = 2;
        p[o1].id[0] = np[i].id[0];
        p[o1].id[1] = np[i - 1].id[0];
    }

    sort(p + 1, p + 1 + o1, cmp);

    for(int i = 1; i <= o1; i++) {
        if(p[i].val > 1 + eps) {
            for(int j = 0; j < p[i].cnt; j++) ans.push_back(p[i].id[j]);
        }
    }

    if(ans.size() == 0) {
        if(o1 != 0) {
            for(int j = 0; j < p[1].cnt; j++) {
                ans.push_back(p[1].id[j]);
            }
        } else if(is) ans.push_back(is);
        else ans.push_back(np[1].id[0]);
    }

    printf("%d\n", ans.size());

    sort(ans.begin(), ans.end());

    for(int i = 0; i < ans.size(); i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");

    return 0;
}