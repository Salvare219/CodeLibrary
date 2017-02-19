#include <bits/stdc++.h>

#define maxn 30000010
using namespace std;

int x[maxn];

int head, tail;
int val[maxn];
int pos[maxn];
int a, b, c;

int main()
{
    //printf("%d\n", (sizeof(x) + sizeof(val) + sizeof(pos))/1024/1024);
    freopen("minima.in", "r", stdin);
    freopen("minima.out", "w", stdout);

    int n, m, mm;
    scanf("%d%d%d", &n, &m, &mm);
    scanf("%d%d%d", &a, &b, &c);
    for (int i=1; i<=mm; i++)
        scanf("%d", &x[i]);
    head = 0;
    tail = 0;
    long long ans = 0;
    for (int i=1; i<m; i++)
    {
        if (i > mm)
            x[i] = a*x[i-2] + b*x[i-1] + c;
        while (head!=tail && val[tail-1] > x[i])
            tail--;
        val[tail] = x[i];
        pos[tail] = i;
        tail++;
    }
    for (int i=m, j = 1; i<=n; i++, j++)
    {
        while (head!=tail && pos[head] < j)
            head ++;
        if (i > mm)
            x[i] = a*x[i-2] + b*x[i-1] + c;
        while (head!=tail && val[tail-1] > x[i])
            tail--;
        val[tail] = x[i];
        pos[tail] = i;
        tail++;
        ans = ans + (long long)val[head];
    }
    /*
    for (int i=1; i<=n; i++)
        cout<<x[i]<<" ";
    cout<<endl;
    */

    cout<<ans<<endl;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
