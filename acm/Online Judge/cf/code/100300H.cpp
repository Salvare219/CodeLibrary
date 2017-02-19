#include <bits/stdc++.h>

using namespace std;

int atomicval[14] =   {13, 1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
int atomicdelta[14] = {13, 1, 3, 5, 8, 10, 30, 50, 80, 100, 300, 500, 800, 1000};
char atomichar[15] = " IVVXXLLCCDDMM";
string atomicstr[14] = {"", "I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
int went[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};

int addable[4000][26];

string caladdable(int num)
{
    string str = "";
    int n = num;
    int pos = 0;
    while (n)
    {
        pos = 0;
        for (int i=1; i<=atomicval[0]; i++)
            if (atomicval[i] <= n)
                pos = i;
        n -= atomicval[pos];
        str.append(atomicstr[pos]);
    }
    int pp = num - atomicdelta[pos];
    addable[pp][atomichar[pos]-'A'] = num;
    return str;
}

char corridor[20][20];
struct state
{
    int x, y, val;
    state(int a, int b, int c):x(a), y(b), val(c){}
};

queue<state> q;

int main()
{
    memset(addable, -1, sizeof(addable));
    for (int i=1; i<=3999; i++)
        caladdable(i);
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i=1; i<=n; i++)
        scanf("%s", &(corridor[i][1]));
    while (!q.empty()) q.pop();

    int ans = 4000;
    for (int i=1; i<=n; i++)
    {
        if(m==1)
            ans = min(addable[0][corridor[i][1]-'A'], ans);
        else
            q.push(state(i, 1, addable[0][corridor[i][1]-'A']));
    }

    while (!q.empty())
    {
        state cnt = q.front();
       //cout<<cnt.x<<" "<<cnt.y<<" "<<cnt.val<<endl;
        q.pop();
        for (int i=0; i<4; i++)
        {
            int s = cnt.x + went[i][0];
            int t = cnt.y + went[i][1];
            if (s>0 && s<=n && t>0 && t<=m)
            {
                int val = addable[cnt.val][corridor[s][t]-'A'];
                if (val==-1)
                    continue;
                if (val>= ans)
                    continue;
                if (t == m)
                    ans = val;
                else
                    q.push(state(s, t, val));
            }
        }
    }

    if (ans == 4000)
        cout<<"NO"<<endl;
    else
        cout<<caladdable(ans)<<endl;
    return  0;
}
