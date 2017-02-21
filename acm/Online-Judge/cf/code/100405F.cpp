#include <bits/stdc++.h>

using namespace std;

int daysmiss(int year, int month, int day)
{
    int ans = year/100-1-year/400;
    //printf("%d\n", year);
    if (year%100==0&&year%400)
    {
        if (month==1||(month==2&&day<29))
        {
            ans--;
            //puts("YES");
        }
    }
    return ans;
}

int monthday[13]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int ansyear, ansmonth, ansday;
int leapyear(int year)
{
    if (year%4==0&&year%100)
        return 1;
    if (year%400==0)
        return 1;
    return 0;
}

int nextday(int year, int month, int day)
{
    ansyear = year;
    ansmonth = month;
    ansday = day+1;

    int temp = monthday[month];
    if (month == 2 && leapyear(year))
    {
        temp++;
    }
    //printf("%d\n", temp);

    if (ansday>temp)
    {
        ansday=1;
        ansmonth++;
        if (ansmonth>12)
        {
            ansmonth=1;
            ansyear++;
        }
    }
    return 0;
}

int main()
{
    //int year, month, day;
    while (scanf("%d-%d-%d", &ansyear, &ansmonth, &ansday)==3)
    {
        int temp = daysmiss(ansyear, ansmonth, ansday);
        //printf("%d\n", temp);
        for (int i=1; i<=temp; i++)
            nextday(ansyear, ansmonth, ansday);
        printf("%d-%d%d-%d%d\n", ansyear, ansmonth/10,ansmonth%10, ansday/10, ansday%10);
    }
    return 0;
}
