#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <cmath>
#include <map>
#include <set>
using namespace std;
int main()
{
    freopen("flat.in","r",stdin);
    freopen("flat.out","w",stdout);
    int n;
    double c;
    while(scanf("%d%lf",&n,&c)==2)
    {
        int AreaAll=0,AreaBedroom=0,AreaBalcony=0;
        for(int i=0;i<n;++i)
        {
            int a;
            char s[20];
            scanf("%d%s",&a,s);
            AreaAll+=a;
            if(s[0]=='b')
            {
                if(s[1]=='e') AreaBedroom+=a;
                else if(s[2]=='l') AreaBalcony+=a;
            }
        }
        printf("%d\n",AreaAll);
        printf("%d\n",AreaBedroom);
        double s=AreaAll*1.0-AreaBalcony*0.5;
        printf("%.10f\n",s*c);
    }
	return 0;
}
