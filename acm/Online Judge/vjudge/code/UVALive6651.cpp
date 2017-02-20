#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int main()
{
    int t,ti=1;scanf("%d",&t);
    while(t--)
    {
        int n;
        long long l,b;
        scanf("%d",&n);
        long long a[3];
        a[0]=a[1]=a[2]=0;
        bool f=1;
        for(int i=0;i<n;i++)
        {
            scanf("%lld%lld",&l,&b);
            if(b%3==0)
            {
                l--;
                if(l!=0)f=0;
                a[0]=(a[0]+(b-1)*l)%2;
            }
            else if(b%3==1)
            {
                l--;
                a[1]+=(b-1)*l;
            }
            else
            {
                a[1]+=(b-1)*((l+1)/2);
                a[2]+=(b-1)*(l/2);
                a[1]-=b-1;
            }
        }
        printf("Case %d: ",ti++);
        if(f)
        {
            if(a[1]>a[2])swap(a[1],a[2]);
            if(a[1]==0)
            {
                if(a[2]<=2)puts("Draw");
                else puts("J");
            }
            else puts("M");
        }
        else if(a[0]%2==0)
        {
            if(a[1]==0&&a[2]==0)puts("J");
            else
            {
                if(a[1]>a[2])swap(a[1],a[2]);
                if(a[1]==0)
                {
                    if(a[2]<=2)puts("Draw");
                    else puts("J");
                }
                else puts("M");
            }
        }
        else
        {
            if(a[1]==a[2])puts("J");
            else if(abs(a[1]-a[2])<=2)puts("Draw");
            else puts("M");
        }
    }
	return 0;
}
