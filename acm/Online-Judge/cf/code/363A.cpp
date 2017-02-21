#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


char ans[20][50];
int main()
{
//    freopen("1.txt","r",stdin);
    int n,con=0;
    scanf("%d",&n);
    if(n==0) puts("O-|-OOOO");
    else
    {
        while(n)
        {
            int a=n%10;
            if(a>=5) ans[con][0]='-',ans[con][1]='O',a-=5;
            else ans[con][0]='O',ans[con][1]='-';
            ans[con][2]='|';
            ans[con][3]=ans[con][4]=ans[con][5]=ans[con][6]=ans[con][7]='O';
            ans[con][a+3]='-';n/=10;con++;
        }
        for(int i=0;i<con;i++)
            puts(ans[i]);
    }
    return 0;
}
