//zkw 和 spfa 的结合 基本一般类型图都比较快

struct edge
{
    int y,c,f,next;
    edge(){}
    edge(int y_,int c_,int f_,int n_){y=y_,c=c_,f=f_,next=n_;}
}e[2008000];
int head[2005];   //初始化 -1
int nn,mm;        //初始化 mm 为0  nn 为点数
int phi[2005],q[2005];
int s_,t_,cost_,tot_;
bool v[2005];
inline bool relable()
{
    int x,to,tail=1,front=0;
    for(int i=1;i<=nn;i++)v[i]=0,phi[i]=0x3fffffff;
    phi[t_]=0;q[0]=t_;
    while(tail!=front)
    {
        x=q[front++];v[x]=0;
        if(front>nn)front=0;
        for(int i=head[x];~i;i=e[i].next)
            if(e[i^1].c&&phi[to=e[i].y]>phi[x]-e[i].f)
            {
                phi[to]=phi[x]-e[i].f;
                if(v[to]==0)
                {
                    v[to]=1;
                    if(phi[to]<phi[q[front]])
                        front==0?front=nn:front--,q[front]=to;
                    else
                        q[tail++]=to,tail>nn?tail=0:0;
                }
            }
    }
    for(int i=1;i<=nn;i++)
        for(int j=head[i];~j;j=e[j].next)
            e[j].f+=phi[e[j].y]-phi[i];
    tot_+=phi[s_];
    return phi[s_]<0x3fffffff;
}
inline int aug(int s,int flow)
{
    if(s==t_)return cost_+=tot_*flow,flow;
    int res=flow,te;v[s]=1;
    for(int i=head[s];~i;i=e[i].next)
        if(!v[e[i].y]&&!e[i].f&&e[i].c)
        {
            res-=(te=aug(e[i].y,min(res,e[i].c)));
            e[i].c-=te;e[i^1].c+=te;
            if(!res)return flow;
        }
    return flow-res;
}
int cost_flow(int s,int t)
{
    cost_=tot_=0;s_=s;t_=t;
    if(!relable())return 0;
    do memset(v,0,sizeof(v));
    while(aug(s,0x3fffffff)||relable());
    return cost_;
}
inline void add(int x,int y,int c,int f)
{
    e[mm]=edge(y,c,f,head[x]);head[x]=mm++;
    e[mm]=edge(x,0,-f,head[y]);head[y]=mm++;
}