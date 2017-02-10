//O(n*m)
vector<int> gra[505];
int n;
bool vis[505];
int p[505];
bool find(int s)
{
	for(int i=0;i<gra[s].size();i++)
		if(vis[gra[s][i]]==0&&p[gra[s][i]]!=s)
		{
			vis[gra[s][i]]=1;
			if(p[gra[s][i]]==0 || find(p[gra[s][i]]))
			{
				p[gra[s][i]]=s;
				return 1;
			}
		}
	return 0;
}
int max_match()
{
	int ans=0;
	memset(p,0,sizeof(p));
	for(int i=1;i<=n;i++)
	{
		memset(vis,0,sizeof(vis));
		ans+=find(i);
	}
	return ans;
}

//找解
//删除该点 如果最大匹配数不变则不为最小覆盖集的点
vector<int>gra[15050];
int p[15050];
bool vis[15050];
int find(int s,int f)
{
    for(int i=0;i<gra[s].size();i++)
        if(vis[gra[s][i]]==0&&p[gra[s][i]]!=s)
        {
            vis[gra[s][i]]=1;
            if(p[gra[s][i]]==0||find(p[gra[s][i]],f))
            {
                f?p[gra[s][i]]=s:0;
                return 1;
            }
        }
    return 0;
}
void get_solution(int nn,int mm)
{
    for(int i=1;i<=nn;i++)
    {
        memset(vis,0,sizeof(vis));
        ans1+=find(i,1);
    }
    for(int i=1;i<=mm;i++)
        if(p[i])
        {
            memset(vis,0,sizeof(vis));
            if(find(p[i],0)==0)chy[i]=1;
        }
    for(int i=1;i<=nn;i++)
    {
        int f=1;
        for(int j=0;j<gra[i].size();j++)
            if(chy[gra[i][j]])
            {
                f=0;
                break;
            }
        chx[i]=f;
    }
}