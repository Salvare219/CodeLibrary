#include <bits/stdc++.h>

#define maxn 400010
using namespace std;

inline int lowbit(int a)
{
    return a&(-a);
}

int update(int tree[],int a,int b,int n)
{
    while (a<=n)
    {
        tree[a]+=b;
        a+=lowbit(a);
    }
    return 0;
}

int ask(int tree[],int a)
{
    int resu=0;
    while (a>0)
    {
        resu+=tree[a];
        a-=lowbit(a);
    }
    return resu;
}

int tree[400100];
int num[100100];
vector<int> appear;
map<int, int> dict;
int head, tail;
vector<int> ans;


int main()
{
    freopen("mtf.in", "r", stdin);
    freopen("mtf.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i=1; i<=n; i++)
    {
        scanf("%d", &num[i]);
        appear.push_back(num[i]);
    }
    appear.push_back(0);
    sort(appear.begin(), appear.end());
    appear.erase(unique(appear.begin(), appear.end()), appear.end());
    head = 100010;
    tail = 100010;

    memset(tree, 0, sizeof(tree));
    for (int i=1; i<(int)appear.size(); i++)
    {
        if (appear[i] - 1 != appear[i-1])
        {
            update(tree, tail, appear[i] - appear[i-1] - 1, maxn);
            tail++;
        }
        update(tree, tail, 1, maxn);
        dict[appear[i]] = tail;
        tail++;
    }

    for (int i=1; i<=n; i++)
    {
        int cnt = dict[num[i]];
        ans.push_back(ask(tree, cnt));
        update(tree, cnt, -1, maxn);

        head--;
        dict[num[i]] = head;
        update(tree, head, 1, maxn);
    }
    for (int i=0; i<n; i++)
        printf("%d%c", ans[i], (i==n-1)?'\n':' ');

    fclose(stdin);
    fclose(stdout);
    return 0;
}
