#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>

#define eps 1.0e-20
using namespace std;
#define inf 100000000
#define mo 10000007
typedef __int64 LL;

int n;
int box[50011];
int li[50011], o;

int sa[50011], k;

int w[50011][300];
int dp[50011];

vector <int> g[50011];

int main()
{
    //freopen("substring.in", "r", stdin);
    //freopen("substring.out", "w", stdout);
    //freopen("pro.in", "r", stdin);
    
    while(scanf("%d", &n) != EOF) {
        k = 0;
        for(int i = 1; i <= n; i++) {
            scanf("%d", &box[i]);
            sa[++k] = box[i];
        }

        sort(sa + 1, sa + 1 + k);

        int m = k;
        k = 1;
        for(int i = 2; i <= m; i++) {
            if(sa[k] != sa[i]) {
                sa[++k] = sa[i];
            }
        }

        for(int i = 1; i <= n; i++) {
            int a = lower_bound(sa + 1, sa + 1 + k, box[i]) - sa;
            box[i] = a;
        }
        
        o = 1;
        li[1] = box[1];
        for(int i = 2; i <= n; i++) {
            if(li[o] != box[i]) {
                li[++o] = box[i];
            }
        }
        
        for(int i = 1; i <= o; i++) {
            g[i].clear();
        }
        for(int i = 1; i <= o; i++) {
            g[li[i]].push_back(i);
        }

        for(int i = 1; i <= o; i++) {
            for(int j = 1; j * j <= o; j++) {
                w[i][j] = -1;
            }
        }
        int a, b, c;

        for(int i = 1; i <= o; i++) {
            w[i][1] = i;
            c = li[i];
            a = lower_bound(g[c].begin(), g[c].end(), i) - g[c].begin();
            b = 0;
            if(a != 0) b = g[c][a - 1];
            for(int j = 2; j * j <= o; j++) {
                if(a == 0) {
                    w[i][j] = w[i - 1][j - 1];
                } else {
                    if(b >= w[i - 1][j]) {
                        w[i][j] = w[i - 1][j];
                        continue;
                    }
                    if(b >= w[i - 1][j - 1]) {
                        w[i][j] = w[i - 1][j - 1];
                        continue;
                    }
                    int cc = w[i - 1][j - 1] - 1;
                    if(cc > 0 && li[cc] == li[i]) {
                        w[i][j] = w[i - 1][j + 1];
                        continue;
                    }
                    w[i][j] = w[i - 1][j - 1];
                }
            }
        }

        for(int i = 1; i <= o; i++) {
            dp[i] = i;
            for(int j = 1; j * j <= i; j++) {
                int a = w[i][j];
                if(a != -1) {
                    dp[i] = min(dp[i], dp[a - 1] + j * j);
                } else {
                    break;
                }
            }
        }

        printf("%d\n", dp[o]);
    }

    
    return 0;
} 