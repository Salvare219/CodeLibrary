#include <iostream>
#include <map>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;

int n;

int main() {
    freopen("ate.in","r",stdin);
    freopen("ate.out","w",stdout);

    scanf("%d", &n);

    int a = n - 1;
    int b = n - 99;

    a = min(a, 99);
    b = max(b, 0);

    if(a >= b) {
        int ans = a - b + 1;
        printf("%d\n", ans);
    } else {
        printf("%d\n", 0);
    }

    return 0;
}