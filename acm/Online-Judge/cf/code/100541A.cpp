#include <stdio.h>
#include <set>
#include <string>
#include <string.h>
#include <iostream>
#include <cmath>
using namespace std;

#define tl(x) (x << 1)
#define tr(x) (x << 1 | 1)
#define MAXN 1000111

int T, n, w;

int p[111];

int main()
{

    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &n, &w);
        for(int i = 1; i <= n; i++) {
            scanf("%d", &p[i]);
        }
        int mx = 0; int buy, sell;
        for(int i = 1; i <= n; i++) {
            for(int j = i + 1; j <= n; j++) {
                if(mx < p[j] - p[i]) {
                    mx = p[j] - p[i];
                    buy = p[i]; sell = p[j];
                }
            }
        }
        if(mx == 0) {
            printf("%d\n", 0);
        } else {
            int a = w / buy * mx;
            printf("%d\n", a);
        }
    }
    
    return 0;
}