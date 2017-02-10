异或  : tf(x1,x2)=(tf(x1)-tf(x2),tf(x1)+tf(x2))
		utf(x1,x2)=(utf((x1+x2)/2),utf((x2-x1)/2))
与    : tf(x1,x2)=(tf(x1)+tf(x2),tf(x1))
		utf(x1,x2)=(utf(x1-x2),utf(x2))
		
		
//与
Ver. 递归
void tf(int a[],int l,int r)
{
    if(l+1==r)return ;
    int mid=(l+r)>>1,len=mid-l;
    tf(a,l,mid);tf(a,mid,r);
    for(int i=0;i<len;i++)
        a[l+i]+=a[mid+i];
}
void utf(int a[],int l,int r)
{
    if(l+1==r)return ;
    int mid=(l+r)>>1,len=mid-l;
    for(int i=0;i<len;i++)
        a[l+i]-=a[mid+i];
    utf(a,l,mid);utf(a,mid,r);
}
//异或
void tf(int a[],int l,int r)
{
    if(l+1==r)return ;
    int mid=(l+r)>>1,len=mid-l;
    tf(a,l,mid);tf(a,mid,r);
    for(int i=0;i<len;i++)
    {
        int x1=a[l+i];
        int x2=a[mid+i];
        a[l+i]=x1-x2;
        a[mid+i]=x1+x2;
    }
}
void utf(int a[],int l,int r)
{
    if(l+1==r)return ;
    int mid=(l+r)>>1,len=mid-l;
    for(int i=0;i<len;i++)
    {
        int x1=a[l+i];
        int x2=a[mid+i];
        a[l+i]=(x1+x2)/2;
        a[mid+i]=(x2-x1)/2;
    }
    utf(a,l,mid);utf(a,mid,r);
}