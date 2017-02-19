#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <queue>

using namespace std;

#define inf 2000000000

int T, n, m, w;
char bx[30][30];

struct Trie {
    int nxt[26];
    int fail;
    bool cnt;
}tp[20100];
int cnt;

void init(int a) {
    tp[a].cnt = tp[a].fail = 0;
    for(int i = 0; i < 26; i++) tp[a].nxt[i] = 0;
}

void insert(char * s) {
    int p = 0;
    while(*s) {
        int a = (*s) - 'A';
        if(!tp[p].nxt[a]) {
            tp[p].nxt[a] = ++cnt;
            init(cnt);
        }
        p = tp[p].nxt[a];
        s++;
    }
    tp[p].cnt = 1;
}
queue <int> q;
void build_ac() {
    q.push(0);
    int son, p;
    while(!q.empty()) {
        int a = q.front(); q.pop();
        for(int i = 0; i < 26; i++) {
            if(tp[a].nxt[i]) {
                son = tp[a].nxt[i];
                p = tp[a].fail;
                if(!a) tp[son].fail = 0;
                else {
                    tp[son].fail = tp[p].nxt[i];
                    tp[son].cnt |= tp[tp[p].nxt[i]].cnt;
                }
                q.push(son);
            } else {
                p = tp[a].fail;
                if(!a) tp[a].nxt[i] = 0;
                else tp[a].nxt[i] = tp[p].nxt[i];
            }
        }
    }
}

char tra[1000];

int xt[4] = {0,0,1,-1};
int yt[4] = {1,-1,0,0};

int dis[22][22][20101];

int spfa(int x, int y, int k) {
    queue<pair<int,int> >q;
    q.push(make_pair(x*100+y,k));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            for(int z=0;z<=cnt;z++)
                dis[i][j][z]=1<<28;
    dis[x][y][k]=0;
    while(!q.empty())
    {
        x=q.front().first/100;
        y=q.front().first%100;
        k=q.front().second;q.pop();
        if(bx[x][y] >= 'A' && bx[x][y] <= 'Z') {
            if(dis[x][y][tp[k].nxt[bx[x][y] - 'A']]>dis[x][y][k])
                dis[x][y][tp[k].nxt[bx[x][y] - 'A']]=dis[x][y][k],q.push(make_pair(x*100+y,tp[k].nxt[bx[x][y] - 'A']));
        }
        for(int i = 0; i < 4; i++) {
            int xx = x + xt[i]; int yy = y + yt[i];
            if(xx >= 1 && xx <= n && yy >= 1 && yy <= m) {
                if(bx[xx][yy] != '#') {
                    if(bx[xx][yy] >= 'A' && bx[xx][yy] <= 'Z') {
                        if(dis[xx][yy][tp[k].nxt[bx[xx][yy] - 'A']]>dis[x][y][k]+1)
                            dis[xx][yy][tp[k].nxt[bx[xx][yy] - 'A']]=dis[x][y][k]+1,q.push(make_pair(xx*100+yy,tp[k].nxt[bx[xx][yy] - 'A']));
                    } else {
                        if(dis[xx][yy][k]>dis[x][y][k]+1)
                            dis[xx][yy][k]=dis[x][y][k]+1,q.push(make_pair(xx*100+yy,k));
                    }
                }
            }
        }
    }
    int ans=1<<28;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            for(int z=0;z<=cnt;z++)
                if(tp[z].cnt==1)
                    ans=min(ans,dis[i][j][z]);
    return ans;
}

int main() {

    scanf("%d", &T);

    while(T--) {
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i++) {
            scanf("%s", bx[i] + 1);
        }
        scanf("%d", &w);
        cnt = 0;
        init(0);
        while(w--) {
            scanf("%s", tra);
            insert(tra);
        }

        build_ac();

        int st, en;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(bx[i][j] == '@') {
                    st = i; en = j;
                    break;
                }
            }
        }

        int ans = spfa(st, en, 0);
        if(ans >= (1<<28)) {
            printf("%d\n", -1);
        } else {
            printf("%d\n", ans);
        }
    }

    return 0;
}