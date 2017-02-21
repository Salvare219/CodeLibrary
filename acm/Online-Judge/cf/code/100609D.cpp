#include <iostream>
#include <map>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int n;

struct Dice {
    int id, num;
}bx[1001];

int cmp(const Dice & a, const Dice & b) {
    if(a.num > b.num) return 1;
    else return 0;
}

vector <int> f_ans[1001];

int main() {
    freopen("dice.in","r",stdin);
    freopen("dice.out","w",stdout);

    scanf("%d", &n);

    for(int i = 1; i <= n; i++) {
        scanf("%d", &bx[i].num);
        bx[i].id = i;
    }

    sort(bx + 1, bx + 1 + n, cmp);

    double ans = 0;

    int now = 1;
    for(int i = 1; i <= n; i++) {
        int l = now; int r = now + bx[i].num - 1;
        now = r + 1;
        int id = bx[i].id;
        ans += (l + r) / 2.0;
        for(int j = l; j <= r; j++) {
            f_ans[id].push_back(j);
        }
    }

    printf("%.5f\n", ans);

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < f_ans[i].size(); j++) {
            printf("%d ", f_ans[i][j]);
        }
        printf("\n");
    }

    return 0;
}