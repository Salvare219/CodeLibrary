#include<bits/stdc++.h>
using namespace std;

pair<int,int> x[100005];
int a[100005],b[100005];

int main()
{
    int n,s,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",a+i);
    for(i=0;i<n;i++)
        scanf("%d",b+i);
    for(i=0;i<n;i++)
        x[i]=make_pair(a[i],b[i]);
    sort(x,x+n);
    for(s=i=0;i<n;i++)
    {
        s+=x[i].second;
        if(s>=x[i].first)
            break;
    }
    puts(i>=n?"Dire victory":"Redemption");
    return 0;
}
