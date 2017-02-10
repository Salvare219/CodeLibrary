int get_week(int a,int m,int d,bool flag)
{
    int w,c,y;
    if(flag)
    {
        if(m<3) m+=12,a--;
        c=a/100,y=a%100;
        w=c/4-2*c+y+y/4+13*(m+1)/5+d-1;
    }
    else
    {
        if(m<3) m+=12,a--;
        c=a/100,y=a%100;
        w=y+y/4+c/4-2*c+13*(m+1)/5+d+2;
    }
    return (w%7+7)%7;
}
int main()
{
    int a,m,d;
    scanf("%d%d%d",&a,&m,&d);
    bool flag=0;
    if(1582<a) flag=1;
    else
    {
        if(10<m) flag=1;
        else
        {
            if(4<d) flag=1;
            else flag=0;
        }
    }
    printf("%d\n",get_week(a,m,d,flag));
    return 0;
}