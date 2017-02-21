#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <cmath>
#include <map>
using namespace std;
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        int L[1005],s=0;
        for(int i=0;i<n;++i)
        {
            scanf("%d",&L[i]);
            s+=L[i];
        }
        int ans=0;
        for(int i=0;i<n;++i) if(n*L[i]>s) ans++;
        printf("%d\n",ans);
    }
    return 0;
}

