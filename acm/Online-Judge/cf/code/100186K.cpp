#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
using namespace std;

char str[9][60];

int block[10][2]={
    0, 0,
    0, 1,
    1, 0,
    1, 4,
    4, 1,
    5, 0,
    5, 4,
    8, 1,
};

int check(int x, int y, int i)
{
    return str[x+block[i][0]][y+block[i][1]]=='x';
}

int ans[10];

int main()
{
    freopen("input.txt","r", stdin);
    freopen("output.txt", "w", stdout);

    for(int i=0; i<9; i++)
        scanf("%s", str[i]);
    for(int i=1; i<=7; i++)
    {
        int flag1 = 1, flag2=1;
        for (int j=0; j<10; j++)
        {
            if(check(0, j*6, i))
                flag2 = 0;
            else
                flag1 = 0;
        }
        if(flag1)
            ans[i] = 1;
        else if(flag2)
            ans[i] = -1;
        else
            ans[i] = 0;
       // printf("%d %d\n", flag1, flag2);
    }
    for(int i=1; i<=7; i++)
        printf("%d%c", ans[i], (i==7)?'\n':' ');

    fclose(stdin);
    fclose(stdout);
    return 0;
}
