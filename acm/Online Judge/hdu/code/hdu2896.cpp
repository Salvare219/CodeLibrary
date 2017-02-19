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
    Trie *fail,*next[130];
    int cont;
    Trie()
    {
        fail=NULL;
        cont=0;
        memset(next,NULL,sizeof(next));
    }
}*que[100005];
char str[10005],lib[205];
void add_trie(Trie *root,char *a,int k)
{
    Trie *p=root;
    int i=0,j;
    while(a[i])
    {
        j=a[i++];
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
        for(i=0;i<128;i++)
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
bool query(Trie *root,bool ans[])
{
    int i=0,j;
    Trie *p=root,*temp;
    bool flag=0;
    while(str[i])
    {
        j=str[i];
        while(p->next[j]==NULL && p!=root) p=p->fail;
        p=p->next[j];
        p=(p==NULL)?root:p;
        temp=p;
        while(temp!=root)
        {
            ans[temp->cont]=1;
            if(temp->cont>0) flag=1;
            temp=temp->fail;
        }
        i++;
    }
    return flag;
}
void del(Trie *p)
{
    for(int i=0;i<128;i++)
        if(p->next[i]!=NULL) del(p->next[i]);
    delete(p);
}
int main()
{
    int n,m,fin=0;
    Trie *root=new Trie();
    scanf("%d",&n);
    getchar();
    for(int i=0;i<n;i++)
    {
        gets(lib);
        add_trie(root,lib,i+1);
    }
    build_ac(root);
    scanf("%d",&m);
    getchar();
    bool ans[505];
    for(int i=0;i<m;i++)
    {
        memset(ans,0,sizeof(ans));
        gets(str);
        if(query(root,ans))
        {
            printf("web %d:",i+1);
            for(int j=1;j<=n;j++)
                if(ans[j]) printf(" %d",j);
            putchar(10);
            fin++;
        }
    }
    del(root);
    printf("total: %d\n",fin);
    return 0;
}