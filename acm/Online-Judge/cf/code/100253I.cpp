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
    int val;
    int id;  
}ty1[5001], ty2[5001], ty3[5001];

struct hammer {
    int val;
    int bl;  
}h1[5001], h2[5001];
int n, A, B;
int n1, n2, n3;

int g1, g2, g3;

int cmp(const node & a, const node & b) {
    if(a.val < b.val) return 1;
    else return 0;
}

int cnp(const hammer & a, const hammer & b) {
    if(a.val < b.val) return 1;
    else return 0;
}

int main() {
    scanf("%d%d%d", &n, &A, &B);
    for(int i = 1, a, b; i <= n; i++) {
        scanf("%d%d", &a, &b);
        if(a == 1) {
            n1++; ty1[n1].val = b;
            ty1[n1].id = i;
        } else if(a == 2) {
            n2++; ty2[n2].val = b;
            ty2[n2].id = i;
        } else if(a == 3) {
            n3++; ty3[n3].val = b;
            ty3[n3].id = i;
        }
    }
    sort(ty1 + 1, ty1 + 1 + n1, cmp);
    sort(ty2 + 1, ty2 + 1 + n2, cmp);
    sort(ty3 + 1, ty3 + 1 + n3, cmp);
    int ha = 0, hb = 0;
    for(int i = 1; i <= n1; i++) {
        if(ha < A) {
            ha++;
            h1[ha].val = ty1[i].val;
            h1[ha].bl = 1;
        } else break;
    }
    for(int i = 1; i <= n2; i++) {
        if(hb < B) {
            hb++;
            h2[hb].val = ty2[i].val;
            h2[hb].bl = 2;
        } else break;
    }
    g1 = ha; g2 = hb;
    int now = 1;
    while(ha < A && now <= n3) {
        ha++;
        h1[ha].val = ty3[now++].val;
        h1[ha].bl = 3;
    }
    while(hb < B && now <= n3) {
        hb++;
        h2[hb].val = ty3[now++].val;
        h2[hb].bl = 3;
    }
    sort(h1 + 1, h1 + 1 + ha, cnp);
    sort(h2 + 1, h2 + 1 + hb, cnp);
    while(now <= n3) {
        if(h1[ha].val > h2[hb].val) {
            if(ty3[now].val >= h1[ha].val) break;
            h1[ha].val = ty3[now++].val;
            if(h1[ha].bl == 1)
                g1--;
            h1[ha].bl = 3;
            sort(h1 + 1, h1 + 1 + ha, cnp);
        } else {
            if(ty3[now].val >= h2[hb].val) break;
            h2[hb].val = ty3[now++].val;
            if(h2[hb].bl == 2)
                g2--;
            h2[hb].bl = 3;
            sort(h2 + 1, h2 + 1 + hb, cnp);
        }
    }
    int sum = 0;
    for(int i = 1; i <= ha; i++) {
        sum += h1[i].val;
    }
    for(int i = 1; i <= hb; i++) {
        sum += h2[i].val;
    }
    printf("%d %d\n", ha + hb, sum);
    int o = 1;
    for(int i = 1; i <= g1; i++) {
        printf("%d %d\n", ty1[i].id, i);
    }
    for(int i = g1 + 1; i <= ha; i++) {
        printf("%d %d\n", ty3[o++].id, i);
    }
    for(int i = 1; i <= g2; i++) {
        printf("%d %d\n", ty2[i].id, i + A);
    }
    for(int i = g2 + 1; i <= hb; i++) {
        printf("%d %d\n", ty3[o++].id, i + A);
    }
    return 0;

}