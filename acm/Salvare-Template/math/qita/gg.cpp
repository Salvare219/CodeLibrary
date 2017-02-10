//整数拆分积最大 不允许重复
int data[100];
int n=8;
int main()
{	
    int k = 2;
    for(; n >= k; n-=k,k++)
    data[k] = k;
    for(int i = k-1; i >= 2 && n; i--, n--)
    data[i]++;
    data[k-1] += n;
    for(int j = 2; j < k; j++)
        printf("%d ",data[j]);
    putchar(10);
    return 0;
}