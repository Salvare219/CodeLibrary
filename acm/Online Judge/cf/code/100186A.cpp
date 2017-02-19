#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

string triple[200][3];
string refutation[200];
int pos[200];
map<string, int> dict[3];

int main()
{
    freopen("input.txt","r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>triple[i][0]>>triple[i][1]>>triple[i][2]>>refutation[i];
        for(int j=0; j<3; j++)
            if(!dict[j][triple[i][j]])
                dict[j][triple[i][j]] = i;
        for(int j=0; j<3; j++)
            if(triple[i][j] == refutation[i])
            {
                pos[i] = j;
                break;
            }
        int ans[3]={0,0,0};
        for (int k=1; k<=i; k++)
        {
            for(int s = 0; s<3; s++)
            {
                if(dict[s][triple[k][s]] == k)
                {
                    int flag = 0;
                    for(int t = 1; t<=i&&!flag; t++)
                        if(pos[t]==s && triple[k][s] == refutation[t])
                            flag=1;
                    ans[s] +=!flag;
                }
            }
        }
        printf("%d %d %d\n", ans[0], ans[1], ans[2]);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
