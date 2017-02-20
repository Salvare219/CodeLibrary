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


int num[555];
int temp[555];
int main()
{
//    freopen("1.txt","r",stdin);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",num+i);
    int sum=0,no2;
    for(int i=0;i<n;i++)
        for(int j=i;j<n;j++)
        {
            no2=0;
            for(int z=0;z<n;z++)
                temp[z]=num[z];
            for(int z=i;z<=j;z++)
                temp[z]=1-temp[z];
            for(int z=0;z<n;z++)
                no2+=temp[z];
            sum=max(sum,no2);
        }
    printf("%d\n",sum);
    return 0;
}

