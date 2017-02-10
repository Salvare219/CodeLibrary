// 调用 
//
//dep[1]=1;totw=0;
//dfs(1);
//top[1]=1;
//build(1);



int hs[50050],fa[50050],top[50050];
int dep[50050],cw[50050],totw;
int dfs(int s)
{
    int y,z=0,f=0,t,sum=1;
    for(int i=0;i<gra[s].size();i++)
        if((y=gra[s][i])!=fa[s])
        {
            dep[y]=dep[fa[y]=s]+1;
            t=dfs(y);sum+=t;
            if(t>z)z=t,f=y;
        }
    return hs[s]=f,sum;
}
void build(int s)
{
    int y;
    cw[s]=++totw;
    if(y=hs[s])top[y]=top[s],build(y);
    for(int i=0;i<gra[s].size();i++)
        if((y=gra[s][i])!=fa[s]&&y!=hs[s])
            build(top[y]=y);
}
void updat(int x,int y,int z)
{
    int f1=top[x],f2=top[y];
    while(f1!=f2)
    {
        if(dep[f1]<dep[f2])swap(f1,f2),swap(x,y);
        g.updat(1,1,n,cw[f1],cw[x],z);
        x=fa[f1];f1=top[x];
    }
    if(dep[x]<dep[y])swap(x,y);
    g.updat(1,1,n,cw[y],cw[x],z);  //边的话记得 cw[hs[y]]
}
int query(int s)
{
    return g.query(1,1,n,s);
}
