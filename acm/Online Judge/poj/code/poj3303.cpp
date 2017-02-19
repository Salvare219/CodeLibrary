#include <cstdio>
#include <cstring>

#define SIZE_U 9
#define SIZE_N 13

typedef struct {
    int lt,rt;
}SInterval;
typedef struct {
    int to;
    int next;
}SEdge;

SInterval inter[SIZE_N];
SEdge eg[SIZE_N*SIZE_N];
int head[SIZE_N];
int match[SIZE_N];
int orhall[SIZE_N][SIZE_U];
int idx;
bool used[SIZE_N][SIZE_U];

void addEdge(int fr,int to)
{
    eg[idx].to = to;
    eg[idx].next = head[fr];
    head[fr] = idx ++;
}

bool dfsMatch(int x)
{
    int hall,tp;
    int i,j;

    for(i = 1;i <= orhall[x][0];i ++) {
        hall = orhall[x][i];
        if(match[x] == hall || used[x][hall]) {continue;}
        used[x][hall] = 1;
        tp = match[x];
        match[x] = hall;
        //printf("%d %d\n",x,hall);
        for(j = head[x];j != -1;j = eg[j].next) {
            if(used[eg[j].to][hall] || (match[eg[j].to] == hall && !dfsMatch(eg[j].to))) {
               break;
            }
        }
        if(j != -1) {
            match[x] = tp;
        }
        else {return 1;}
        used[x][hall] = 0;
    }
    return 0;
}

bool getAns(int n)
{
    int i;

    memset(match, -1, sizeof(match));
    for(i = 1;i <= n;i ++) {
        //printf("III: %d\n",i);
        memset(used, 0, sizeof(used));
        if(!dfsMatch(i)) {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int t;
    int n,i,k,j;
    bool isFulfill;

    scanf("%d",&t);
    while(t --) {
        scanf("%d",&n);
        memset(head, -1, sizeof(head));
        idx = 0;
        for(i = 1;i <= n;i ++) {
            scanf("%d%d",&inter[i].lt,&inter[i].rt);
            for(k = 1;k < i;k ++) {
                if(!(inter[i].lt > inter[k].rt || inter[i].rt < inter[k].lt)) {
                    addEdge(i, k);
                    addEdge(k, i);
                }
            }
            scanf("%d",&orhall[i][0]);
            for(j = 1;j <= orhall[i][0];j ++) {
                scanf("%d",&orhall[i][j]);
                if(j != 1 && orhall[i][j] == orhall[i][j-1]) {
                    j --;
                    orhall[i][0] --;
                }
            }
        }
        isFulfill = getAns(n);
        if(isFulfill) {
            puts("YES");
        }
        else {
            puts("NO");
        }
    }
    return 0;
}