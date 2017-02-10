n 个点 n-1 条边 n^(n-2)

n 个点 n 条边 

    long long it=1,ans;
    for(int i=3;i<n;i++)
        it*=i;
    ans=it;
    for(int i=1;i<=n-3;i++)
    {
        it=it*n/i;
        ans+=it;
    }
    printf("%I64d\n",ans);

生成树计数
Krichhoof 矩阵的 n-1 阶行列式的值
Krichhoof 矩阵 G 是这样的：
Gii 等于点 i 的度数
当 i 和 j 有边时， Gij = -1  。 否则 Gij 等于 0 。