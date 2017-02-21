#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
int n,m,dx,dy,x,y,i,j,a[1000500],b[1000500],rez;
int main()
{
    scanf("%d%d%d%d",&n,&m,&dx,&dy);
    x = y = a[0] = 0;
    for (i = 0; i < n; i++)
    {
        x = (x+dx)%n;
        y = (y+dy)%n;
        a[x] = y;
    }
    for (i = 0; i < m; i++)
    {
        scanf("%d%d",&x,&y);
        b[(y-a[x]+n)%n]++;
    }
    int max1 = -1;
    for (i = 0; i < n; i++)
        if (b[i] > max1)
        {
            max1 = b[i];
            rez = i;
        }
    printf("0 %d\n",rez);
    return 0;
}