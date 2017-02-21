#include<bits/stdc++.h>
using namespace std;

struct node{
    int nt[26],ct,f;
}t[10005];
char a[105];
int tn,cn,s[2][105];

inline void add()
{
    scanf("%s",a);
    int rt=0,i;
    for(i=0;a[i];i++)
    {
        if(!t[rt].nt[a[i]-'a'])
            t[rt].nt[a[i]-'a']=++tn;
        rt=t[rt].nt[a[i]-'a'];
    }
    t[rt].f++;
}
void dfs(int rt)
{
    if(t[rt].f)
        cn++;
    t[rt].ct=cn;
    if(t[rt].f)
        cn+=t[rt].f-1;
    for(int i=0;i<26;i++)
        if(t[rt].nt[i])
            dfs(t[rt].nt[i]);
}
inline void go(int i,int rt)
{
    int s0=s[0][i],s1=s[1][i],c0=t[rt].ct;
    if(t[rt].f)
        s0++;
    while(a[i])
    {
        rt=t[rt].nt[a[i]-'a'];
        if(!rt)
            return;
        i++;
        if(t[rt].f)
            s[1][i]=min(s[1][i],min(s0,s1)+t[rt].ct-c0);
    }
}
inline int sol()
{
    scanf("%s",a);
    memset(s,0x3f,sizeof(s));
    s[0][0]=0;
    int i,rt=0;
    for(i=0;a[i];i++)
    {
        s[0][i+1]=min(s[0][i+1],min(s[0][i],s[1][i])+1);
        if(rt>=0)
        {
            go(i,rt);
            rt=t[rt].nt[a[i]-'a'];
        }
        if(!rt)
            rt=-1;
    }
    return min(s[0][i],s[1][i]);
}

int main()
{
    int n;
    for(scanf("%d",&n);n--;)
        add();
    dfs(0);
    printf("%d\n",sol()+1);
    return 0;
}
