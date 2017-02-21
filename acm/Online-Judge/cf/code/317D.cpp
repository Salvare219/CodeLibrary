#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<queue>
using namespace std;


int sg[]={0, 1, 2, 1, 4, 3, 2, 1, 5, 6, 2, 1, 8, 7, 5, 9, 8, 7, 3, 4, 7, 4, 2, 1, 10, 9, 3, 6, 11, 12};
int main()
{
    int n;
    int sum=1,i;
    scanf("%d",&n);
    if(n==1) printf("Vasya\n");
    else
    {
        int con=0,lim=sqrt(n)+1;
        bool vis[100000]={0};
        for(i=2;i<=lim;i++)
        {
            if(vis[i]) continue;
            long long fa=i;
            int ti=0;
            while(n>=fa)
            {
                ti++;
                if(fa>lim) con++;
                else vis[fa]=1;
                fa*=i;
            }
            sum^=sg[ti];
        }
        con=(n-lim-con)%2;
        sum^=con;
        if(sum) printf("Vasya\n");
        else printf("Petya\n");
    }
    return 0;
}

