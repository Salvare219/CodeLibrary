#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
using namespace std;

char s[4400];
int main()
{
    freopen("input.txt","r", stdin);
    freopen("output.txt", "w", stdout);
    int n,m;scanf("%d%d",&n,&m);
    int x=0,y=0,cnt=0;
    scanf("%s",s);
    for(int i=0;i<m;i++)
    {
        if(s[i]=='0')x++;
        else y++;
        cnt++;
        int f=0;
        if(x+(m-i-1)>=n)f+=1;
        if(y+(m-i-1)>=n)f+=2;
        if(f!=3)
        {
            if(x+(m-i-1)==n&&y+(m-i-1)==n)
            {
                cnt++;
                break;
            }
            if(x+(m-i-1)==n)
            {
                break;
            }
            if(y+(m-i-1)==n)
            {
                break;
            }
        }
        if(x==n-1||y==n-1)
        {
            if(m==2*n-1)cnt++;
            break;
        }
    }
    printf("%d\n",cnt);
    return 0;
}
