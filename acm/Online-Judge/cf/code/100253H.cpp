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

int n, m;
char s[5010];
int to[5010];

int o;

int degree[5010];

vector <int> g[5010];

char ans[5010];

int main() {
    //freopen("pro.in","r",stdin);
    scanf("%d", &n);
    scanf("%s", s);
    m = strlen(s);
    to[0] = 0;
    for(int i = 0; i < strlen(s); i++) {
        if(s[i] == '=') {
            to[i + 1] = o;
        } else {
            o++;
            to[i + 1] = o;
        }
    }

    for(int i = 0; i < strlen(s); i++) {
        if(s[i] == '<') {
            g[to[i + 1]].push_back(to[i]);
            degree[to[i]]++;
        } else if(s[i] == '>') {
            g[to[i]].push_back(to[i + 1]);
            degree[to[i + 1]]++;
        }
    }

    int sum = 0;
    queue <int> q;

    for(int i = 0; i <= o; i++) {
        if(degree[i] == 0) {
            ans[i] = char(n + 'a' - 1);
            sum++;
            q.push(i);
        }
    }

    bool can = 1;

    while(!q.empty()) {
        int a = q.front(); q.pop();
        for(int i = 0; i < g[a].size(); i++) {
            int b = g[a][i];
            degree[b]--;
            if(degree[b] == 0) {
                if(ans[a] == 'a') {can = 0; break;}
                ans[b] = ans[a] - 1;
                sum++;
                q.push(b);
            }
        }
        if(!can) break;
    }

    if(!can || sum != o + 1) {
        printf("-1\n");
        return 0;
    }

    for(int i = 0; i <= m; i++) {
        printf("%c",ans[to[i]]);
    }
    printf("\n");
    return 0;

}
