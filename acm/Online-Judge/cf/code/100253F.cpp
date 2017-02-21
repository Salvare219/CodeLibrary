#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
using namespace std;
#define eps 1e-20
#define mo 1000000009

struct node {
    int ti;
    double pi;
    int st, en;
    int id;
    bool operator < (const node & a) const {
        if(a.en < en) return 1;
        else return 0;
    }
}box[300001], tmp;

int n, m;
int haha[300001];

priority_queue <node> q;

int cmp(const node & a, const node & b) {
    if(a.en < b.en) return 1;
    else if(a.en == b.en) {
        if(a.st < b.st) return 1;
        else return 0;
    }
    return 0;
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%d%lf", &box[i].ti, &box[i].pi);
        box[i].id = i;
    }
    for(int i = 1; i <= min(n, m); i++) {
        box[i].st = 0;
        box[i].en = box[i].ti;
        q.push(box[i]);
    }

    if(m < n) {
        for(int i = m + 1; i <= n; i++) {
            tmp = q.top(); q.pop();
            box[i].st = tmp.en;
            box[i].en = tmp.en + box[i].ti;
            q.push(box[i]);
        }
    }
    int maxn = 0;
    for(int i = 1; i <= n; i++) {
        maxn = max(maxn, box[i].en);
        haha[i] = maxn;
    }
    //sort(box + 1, box + 1 + n, cmp);
    double ans = 0;
    double tj = 1;
    for(int i = 1; i <= n; i++) {
        if(i != n) {
            ans += tj * haha[box[i].id] * (1 - box[i].pi);
            tj *= box[i].pi;
        } else {
            ans += tj * haha[box[i].id];
        }
    }
    printf("%.10f\n", ans);
    return 0;

}
