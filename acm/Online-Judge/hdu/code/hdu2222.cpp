#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;


int to[260005][26],fail[500005],cont[500005];
int que[500005],k;
char str[1000005],lib[55];
void add_trie(char a[])
{
    int index,p=0;
    for(int i=0;a[i];i++)
    {
        index=a[i]-'a';
        if(to[p][index]==0)
        {
            memset(to[k],0,sizeof(to[k]));
            fail[k]=cont[k]=0;
            to[p][index]=k++;
        }
        p=to[p][index];
    }
    cont[p]++;
}
void build_ac()
{
    int tail=0,front=0,p;
    for(int i=0;i<26;i++)
        if(to[0][i])
        {
            fail[to[0][i]]=0;
            que[front++]=to[0][i];
        }
    while(tail<front)
    {
        p=que[tail++];
        for(int i=0;i<26;i++)
            if(to[p][i])
            {
                fail[to[p][i]]=to[fail[p]][i];
                que[front++]=to[p][i];
            }
            else to[p][i]=to[fail[p]][i];
    }
}
int query(char a[])
{
    int p=0,ans=0,temp;
    for(int i=0;a[i];i++)
    {
        p=to[p][a[i]-'a'];
        temp=p;
        while(temp && cont[temp]!=-1)
        {
            ans+=cont[temp];
            cont[temp]=-1;
            temp=fail[temp];
        }
    }
    return ans;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        memset(to[0],0,sizeof(to[0]));
        cont[0]=0;k=1;
        for(int i=0;i<n;i++)
        {
            scanf("%s",lib);
            add_trie(lib);
        }
        build_ac();
        scanf("%s",str);
        printf("%d\n",query(str));
    }
    return 0;
}