//
//...
int mod[20]={1,1,2,6,4,2,2,4,2,8,4,4,8,4,6,8,8,6,8,2};
char num[10005];
int a[10005];

int main()
{
    int len,t,c,i;
    while(scanf("%s",num)==1)
    {
        t=1;
        len=strlen(num);
        for(i=0;i<len;i++)
            a[i]=num[len-i-1]-'0';
        while(len)
        {
            len-=!a[len-1];
            t=t*mod[a[1]%2*10+a[0]]%10;
            for(c=0,i=len-1;i>-1;i--)
            {
                c=c*10+a[i];
                a[i]=c/5;
                c%=5;
            }
        }
        printf("%d\n",t);
    }
    return 0;
}