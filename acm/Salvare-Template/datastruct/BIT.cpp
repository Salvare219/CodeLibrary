//更新区间求点  或 更新点求区间   不能有 0 ！！！！
//求出 [ 1 , x ] 所有数的和  在 x 处加入 v
struct bit_tree
{
    int bit[100050],s;
    inline void updat(int x,int v)
    {
        while(x<100005) bit[x]+=v,x+=x&-x;
    }
    inline int query(int x)
    {
        s=0;
        while(x) s+=bit[x],x-=x&-x;
        return s;
    }
    inline int find(int x)
    {
        int cnt=0,ans=0,p=1<<18;
        while(p)
        {
            ans|=p;
            if(ans>100001||cnt+bit[ans]>=x)ans^=p;
            else cnt+=bit[ans];p>>=1;
        }
        return ans+1;
    }
};
