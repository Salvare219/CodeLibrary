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


long long da[555];
int main()
{
//    freopen("1.txt","r",stdin);
    long long n;
    da[0]=1;
    for(int i=0;i<40;i++)
        da[i+1]=da[i]*3;
    scanf("%I64d",&n);
    long long con=0;
    for(int i=1;i<40;i++)
        if(n%da[i])
        {
            con=n/da[i];
            break;
        }
    printf("%I64d\n",con+1);
    return 0;
}
