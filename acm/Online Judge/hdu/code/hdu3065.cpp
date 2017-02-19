#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;


struct Trie
{
    Trie *fail,*next[28];
    int cont;
    Trie()
    {
        fail=NULL;
        cont=0;
        memset(next,NULL,sizeof(next));
    }
}*que[50005];
char sc[2000005],lib[1005][55];
int ans[1005];
void add_trie(Trie *root,char *a,int k)
{
    Trie *p=root;
    int i=0,j;
    while(a[i])
    {
        j=a[i++]-'A';
        if(p->next[j]==NULL) p->next[j]=new Trie();
        p=p->next[j];
    }
    p->cont=k;
}
void build_ac(Trie *root)
{
    int i,head=0,tail=0;
    Trie *temp,*p;
    root->fail=NULL;
    que[head++]=root;
    while(head!=tail)
    {
        temp=que[tail++];
        p=NULL;
        for(i=0;i<26;i++)
        {
            if(temp->next[i]!=NULL)
            {
                if(temp==root) temp->next[i]->fail=root;
                else
                {
                    p=temp->fail;
                    while(p!=NULL)
                    {
                        if(p->next[i]!=NULL)
                        {
                            temp->next[i]->fail=p->next[i];
                            break;
                        }
                        p=p->fail;
                    }
                    if(p==NULL) temp->next[i]->fail=root;
                }
                que[head++]=temp->next[i];
            }
        }
    }
}
bool query(Trie *root,char *str)
{
    int i=0,j;
    Trie *p=root,*temp;
    bool flag=0;
    while(str[i])
    {
        j=str[i]-'A';
        while(p->next[j]==NULL && p!=root) p=p->fail;
        p=p->next[j];
        p=(p==NULL)?root:p;
        temp=p;
        while(temp!=root)
        {
            ans[temp->cont]++;
            temp=temp->fail;
        }
        i++;
    }
    return flag;
}
int main()
{
    int n,m=-1;
    while(scanf("%d",&n)==1)
    {
        m=-1;
        Trie *root=new Trie();
        for(int i=0;i<n;i++)
        {
            scanf("%s",lib[i]);
            add_trie(root,lib[i],i+1);
        }
        build_ac(root);
        getchar();
        gets(sc);
        memset(ans,0,sizeof(ans));
        for(int i=0;sc[i];i++)
        {
            if(sc[i]<='Z' && sc[i]>='A')
            {
                if(m==-1) m=i;
            }
            else
            {
                if(m==-1) continue;
                char ch=sc[i];
                sc[i]=0;
                query(root,sc+m);
                sc[i]=ch;
                m=-1;
            }
        }
        if(m!=-1) query(root,sc+m);
        for(int i=1;i<=n;i++)
            if(ans[i]) printf("%s: %d\n",lib[i-1],ans[i]);
    }
    return 0;
}





























