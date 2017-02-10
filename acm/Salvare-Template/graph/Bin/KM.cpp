//O(n^3) 保证 nn <= mm 且 必须有完备匹配  建空点 和 空边
//从 1 开始标号
int nn,mm;
bool visx[105],visy[105];
int pre[105],gra[105][105];
int lx[105],ly[105],slack[105];
bool find(int s)
{
    visx[s]=1;
    for(int i=1;i<=mm;i++)
        if(visy[i]==0)
        {
            int f=lx[s]+ly[i]-gra[s][i];
            if(f==0)
            {
                visy[i]=1;
                if(pre[i]==0 || find(pre[i]))
                {
                    pre[i]=s;
                    return 1;
                }
            }
            else slack[i]=min(slack[i],f);
        }
    return 0;
}
int Kuhn_Munkras()
{
    int i,j,d,ans=0;
    memset(ly,0,sizeof(ly));
    memset(pre,0,sizeof(pre));
    for(i=1;i<=nn;i++)
        for(j=1,lx[i]=-0x7fffffff;j<=mm;j++)
            lx[i]=max(lx[i],gra[i][j]);
    for(i=1;i<=nn;i++)
    {
        memset(slack,0x7f,sizeof(slack));
        while(1)
        {
            memset(visx,0,sizeof(visx));
            memset(visy,0,sizeof(visy));
            if(find(i)) break;
            d=0x7fffffff;
            for(j=1;j<=mm;j++)
                if(visy[j]==0) d=min(d,slack[j]);
            for(j=1;j<=nn;j++)
                if(visx[j]) lx[j]-=d;
            for(j=1;j<=mm;j++)
                if(visy[j]) ly[j]+=d;
                else slack[j]-=d;
        }
    }
    for(i=1;i<=mm;i++)
        if(pre[i]) ans+=gra[pre[i]][i];
    return ans;
}