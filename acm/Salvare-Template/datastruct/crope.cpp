#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <ext/rope>

using namespace std;
using namespace __gnu_cxx;

const int maxn=50500;

crope tmp,var[maxn],t;
int n,op,p,c,v,d,curv;
char str[maxn];

int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        curv=0;d=0;
        while(n--)
        {
            scanf("%d",&op);
            if(op==1)
            {
                scanf("%d%s",&p,str);
                p-=d;
                t.insert(p,str);
                var[++curv]=t;
            }
            else if(op==2)
            {
                scanf("%d%d",&p,&c);
                p-=d;c-=d;
                t.erase(p-1,c);
                var[++curv]=t;
            }
            else if(op==3)
            {
                scanf("%d%d%d",&v,&p,&c);
                v-=d;p-=d;c-=d;
                tmp=var[v].substr(p-1,c);
                d+=count(tmp.begin(),tmp.end(),'c');
                cout<<tmp<<endl;
            }
        }
    }
    return 0;
}