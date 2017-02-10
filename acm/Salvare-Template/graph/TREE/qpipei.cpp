#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int N = 100;


int G[N][N];
int cnt_node;

int  dist[N];
bool vst[N];
int rec[N],cr;
int M[N];
int P[N];

const int inf = 0x3f3f3f3f;

bool spfa(int u)
{
    rec[cr++]=u;
    if(vst[u]) return true;
    vst[u]=true;
    int v;
    for(v=0;v<cnt_node;v++)
    {
        if(v!=u&&M[u]!=v&&!vst[v])
        {
            int w=M[v];
            if(dist[w]>dist[u]+G[u][v]-G[v][w])
            {
                dist[w]=dist[u]+G[u][v]-G[v][w];
                if(spfa(w))
                {
                    return true;
                }
            }
        }
    }
    cr--;
    vst[u]=false;
    return false;
}

int match()
{
    int i;
    for(i=0;i<cnt_node;i++) P[i]=i;
    for(i=0;i<cnt_node;i+=2) M[i]=i+1,M[i+1]=i;
    int cnt=0;
    while(1)
    {
        //memset(dist,0,sizeof(dist));
        for (int i = 0; i < cnt_node; i++)
            dist[i] = inf;
        cr=0;
        int i;
        bool fd=false;
        memset(vst,0,sizeof(vst));
        for(i=0;i<cnt_node;i++)
        {
            if(spfa(P[i]))
            {
                fd=true;
                int j;
                int nx=M[rec[cr-1]];
                for(j=cr-2;rec[j]!=rec[cr-1];j--)
                {
                    M[nx]=rec[j];
                    int tmp=nx;
                    nx=M[rec[j]];
                    M[rec[j]]=tmp;
                }
                M[nx]=rec[j];
                M[rec[j]]=nx;
                break;
            }
        }
        if(!fd)
        {
            cnt++;
            if(cnt>=3) break;
        //	random_shuffle(P,P+cnt_node);
            for(i=0;i<cnt_node;i++)
            {
                swap(P[i],P[i+rand()%(cnt_node-i)]);
            }
        }
    }
    int sum=0;
    for(i=0;i<cnt_node;i++)
    {
        int v=M[i];
        if(i<v)
        {
            sum+=G[i][v];
        }
    }
    return sum;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        int n, m, K;
        scanf("%d%d%d", &n, &m, &K);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                G[i][j] = inf;
                if (i == j) G[i][j] = 0;
            }
        }
        for (int i = 0; i < m; i++) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            u--; v--;
            G[u][v] = G[v][u] = min(G[u][v], w);
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (G[i][j] > G[i][k] + G[k][j]) {
                        G[i][j] = G[i][k] + G[k][j];
                    }
                }
            }
        }
        cnt_node = K;
        printf("Case %d: ", cas);
        if (K % 2 == 1) {
            printf("Impossible\n");
        } else {
            printf("%d\n", match());
        }
    }
    return 0;
}