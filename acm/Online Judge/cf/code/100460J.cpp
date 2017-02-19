#include <bits/stdc++.h>

using namespace std;

void changeCandle()
{
    puts("S");
    fflush(stdout);
}
void previousRoom()
{
    puts("L");
    fflush(stdout);
}
void nextRoom()
{
    puts("R");
    fflush(stdout);
}

int checklen(int cnt)
{
    for (int i=1; i<=cnt; i++)
    {
        nextRoom();
        int candle;
        scanf("%d", &candle);
        if (!candle)
            changeCandle();
    }
    changeCandle();
    int flag = 0;
    for (int i=1; i<=cnt; i++)
    {
        previousRoom();
        int candle;
        scanf("%d", &candle);
        if (!candle)
        {
            flag = i;
            printf("%d\n", flag);
            fflush(stdout);
            return flag;
        }
    }
    return flag;
}

int main()
{
    int candle;
    scanf("%d", &candle);
    if (!candle)
    {
        changeCandle();
    }
    int len = 1;
    while (!checklen(len))
    {
        len*=2;
    }
    return 0;
}
