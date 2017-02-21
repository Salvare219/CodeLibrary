#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

pair<int,pair<int,int> >a[2000000];
int main()
{
    //freopen("1.txt","r",stdin);
    int n,yn=0,ym=1<<30,x,sum=0;scanf("%d",&n);
    int k=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);sum+=x;
        int d=i%2?-1:1;
        for(int j=0;j<x;j++)
        {
            yn+=d;
            if(d==1)a[k]=make_pair(-yn,make_pair(k,1));
            else a[k]=make_pair(-yn-1,make_pair(k,0));
            k++;
            ym=min(ym,yn);
        }
    }
    sort(a,a+k);a[k]=make_pair(ym-5,make_pair(0,0));
    for(int i=0;i<k;i++)
    {
        int p=i,las=a[i].first;
        for(int j=0;j<sum;j++)
        {
            if(j==a[p].second.first&&a[p].first==las)
                putchar(a[p].second.second?'/':'\\'),p++;
            else putchar(' ');
        }
        putchar(10);
        i=p-1;
    }
    return 0;
}
