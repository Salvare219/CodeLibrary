#include<bits/stdc++.h>
using namespace std;


set<int>H,V;
multiset<int>dh,dv;
int main()
{
    //freopen("1.txt","r",stdin);
    int w,h,n;scanf("%d%d%d",&w,&h,&n);
    char a[5];
    H.insert(0);H.insert(h);
    V.insert(0);V.insert(w);
    dh.insert(h);
    dv.insert(w);
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%s%d",a,&x);
        set<int>::iterator it;
        int s,c;
        if(a[0]=='H')
        {
            it=H.lower_bound(x);
            s=*it;
            c=*(--it);
            dh.erase(dh.find(s-c));
            dh.insert(s-x);
            dh.insert(x-c);
            H.insert(x);
        }
        else
        {
            it=V.lower_bound(x);
            s=*it;
            c=*(--it);
            dv.erase(dv.find(s-c));
            dv.insert(s-x);
            dv.insert(x-c);
            V.insert(x);
        }
        long long aa=*(--dh.end()),bb=*(--dv.end());
        printf("%I64d\n",aa*bb);
    }
    return 0;
}
