一维:
//求区间和的线段树  支持区间更新
struct seg_tree    // i 从 1 开始标
{
    int num[100005];
    long long laz[400050],dat[400050];
    long long build(int i,int l,int r)
    {
        if(l<r)dat[i]=build(i<<1,l,l+r>>1)+build(i<<1|1,(l+r>>1)+1,r);
        else dat[i]=num[i];
        return dat[i];
    }
    inline void push_up(int i)
    {
        dat[i]=dat[i<<1]+dat[i<<1|1];
    }
    inline void push_down(int i,int l,int r)
    {
        laz[i]+=laz[i>>1];
        dat[i]+=laz[i>>1]*(r-l+1);
    }
    inline long long query(int i,int l,int r,int l1,int r1)
    {
        if(l==l1 && r==r1) return dat[i];
        else
        {
            int mid=l+r>>1;
            if(laz[i])push_down(i<<1,l,mid),push_down(i<<1|1,mid+1,r),laz[i]=0;
            if(l1>mid)return query(i<<1|1,mid+1,r,l1,r1);
            else if(r1<=mid)return query(i<<1,l,mid,l1,r1);
            else return query(i<<1,l,mid,l1,mid)+query(i<<1|1,mid+1,r,mid+1,r1);
        }
    }
    inline void updat(int i,int l,int r,int l1,int r1,long long x)
    {
        if(l==l1 && r==r1) dat[i]+=(r1-l1+1)*x,laz[i]+=x;
        else
        {
            int mid=l+r>>1;
            if(laz[i])push_down(i<<1,l,mid),push_down(i<<1|1,mid+1,r),laz[i]=0;
            if(l1>mid)updat(i<<1|1,mid+1,r,l1,r1,x);
            else if(r1<=mid)updat(i<<1,l,mid,l1,r1,x);
            else updat(i<<1,l,mid,l1,mid,x),updat(i<<1|1,mid+1,r,mid+1,r1,x);
            push_up(i);
        }
    }
};
