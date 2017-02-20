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


int m[2][2]={0,0,0,1};
int Nim_Mult_Power(int x,int y){
	if(x<2)
		return m[x][y];
	int a=0;
	for(;;a++)
		if(x>=(1<<(1<<a))&&x<(1<<(1<<(a+1))))
			break;
	int m=1<<(1<<a);
	int p=x/m,s=y/m,t=y%m;
	int d1=Nim_Mult_Power(p,s);
	int d2=Nim_Mult_Power(p,t);
	return (m*(d1^d2))^Nim_Mult_Power(m/2,d1);
}
int Nim_Mult(int x,int y){
	if(x<y)
		return Nim_Mult(y,x);
	if(x<2)
		return m[x][y];
	int a=0;
	for(;;a++)
		if(x>=(1<<(1<<a))&&x<(1<<(1<<(a+1))))
			break;
	int m=1<<(1<<a);
	int p=x/m,q=x%m,s=y/m,t=y%m;
	int c1=Nim_Mult(p,s),c2=Nim_Mult(p,t)^Nim_Mult(q,s),c3=Nim_Mult(q,t);
	return (m*(c1^c2))^c3^Nim_Mult_Power(m/2,c1);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,x,y,sum=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&x,&y);
            sum^=Nim_Mult(x,y);
        }
        if(sum) printf("Have a try, lxhgww.\n");
        else printf("Don't waste your time.\n");
    }
    return 0;
}