#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;


int f[55555];
int a[200][200];
int how[200];
#include<set>
int main()
{
 //   freopen("1.txt","r",stdin);
    int n,x;
    scanf("%d",&n);
    for(int i=0;i<2*n;i++)
        scanf("%d",&x),a[x][how[x]++]=i;
    set<int> s1,s2;
    for(int i=10;i<100;i++)
        if(how[i]>=2)
        {
            f[a[i][how[i]-1]]=1;
            f[a[i][how[i]-2]]=2;
            s1.insert(i);s2.insert(i);
            how[i]-=2;
        }
    int c=0,d=0;
    for(int i=10;i<100;i++)
        if(how[i]==1)
        {
            if(s1.find(i)==s1.end())
            {
                how[i]=0;
                if(c>d) f[a[i][0]]=2,d++;
                else f[a[i][0]]=1,c++;
            }
        }
    printf("%d\n",(c+s1.size())*(d+s2.size()));
    for(int i=10;i<100;i++)
        if(how[i])
        {
            for(int j=0;j<how[i];j++)
            {
                if(c>d) f[a[i][j]]=2,d++;
                else f[a[i][j]]=1,c++;
            }
        }
    for(int i=0;i<2*n;i++)
        printf("%d ",f[i]);
    putchar(10);
    return 0;
}
