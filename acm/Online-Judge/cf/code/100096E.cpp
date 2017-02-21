#include <bits/stdc++.h>

using namespace std;

queue<int> room[1010];
queue<int> cntque, nextque;

class patient
{
    public:
    int t, id;
    bool operator <(const patient &a)const
    {
        if (t==a.t)
            return id>a.id;
        return t>a.t;
    }
    patient(int a, int b): t(a), id(b){}
};

priority_queue<patient> arrival;
queue<int> examination[1010];
queue<int> examing;
vector<int> toenter;

int n, m;
int unfinished;

int main()
{
    freopen("medical.in", "r" , stdin);
    freopen("medical.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i=1; i<=n; i++)
    {
        int x;
        scanf("%d", &x);
        arrival.push(patient(x, i));
        int k;
        scanf("%d", &k);
        for (int j=1; j<=k; j++)
        {
            int y;
            scanf("%d", &y);
            examination[i].push(y);
        }
    }

    unfinished = n;
    int cnt = 0;
    while (unfinished)
    {
        toenter.clear();
        while (!examing.empty())
        {
            int x = examing.front();
            examing.pop();
            if (examination[x].empty())
                unfinished --;
            else
                toenter.push_back(x);
        }
        while (!arrival.empty() && arrival.top().t<=cnt)
        {
            int x = arrival.top().id;
            arrival.pop();
            toenter.push_back(x);
        }
        sort(toenter.begin(), toenter.end());
        for (vector<int>::iterator ite = toenter.begin(); ite<toenter.end(); ite++)
        {
            int x = *ite;
            int r = examination[x].front();
            examination[x].pop();

            room[r].push(x);
            if (room[r].size()==1)
            {
                cntque.push(r);
            }
        }

        while (!cntque.empty())
        {
            int r = cntque.front();
            cntque.pop();

            examing.push(room[r].front());
            room[r].pop();

            if(!room[r].empty())
                nextque.push(r);
        }
        while (!nextque.empty())
        {
            cntque.push(nextque.front());
            nextque.pop();
        }
        cnt++;
    }
    printf("%d\n", cnt-1);

    fclose(stdin);
    fclose(stdout);
    return 0;
}
