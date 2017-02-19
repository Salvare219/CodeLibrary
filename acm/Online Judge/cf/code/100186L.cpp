#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include <functional>
using namespace std;

int num[2000];

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt", "w",stdout);

    int n,m;
    scanf("%d%d", &n,&m);
    memset(num, -1, sizeof(num));
    for (int i=1; i<=n; i++)
        scanf("%d", &num[i]);
    sort(num+1, num+1+n);//,greater<int>());
    printf("%d\n", num[m+1]);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
