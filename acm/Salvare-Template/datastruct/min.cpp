//字符串循环 字典序最小 返回开始下标
char str[1000005];
int get_min()
{
   int len=strlen(str),i=0,j=1,k=0,t;
   while(i<len && j<len && k<len)
   {
       t=str[(i+k)%len]-str[(j+k)%len];
       if(t)
       {
           if(t>0) i=i+k+1;
           else j=j+k+1;
           if(i==j) j++;
           k=0;
       }
       else k++;
   }
   return min(i,j);
}