//SLF LLL优化
SPFA 算法有两个优化算法 SLF 和 LLL ：
SLF ： Small Label First 策略，设要加入的节点是 j ，
队首元素为 i ，若 dist(j)<dist(i) ，则将 j 插入队首，否则插入队尾。
LLL ： Large Label Last 策略，设队首元素为 i ，队列中所有 dist 值的平均值为 x ，
若 dist(i)>x 则将 i 插入到队尾，查找下一元素，直到找到某一 i 使得 dist(i)<=x，
则将i出对进行松弛操作。

//Parent Checking
检查当前结点的父亲是否在队列中
在的话直接抛弃当前节点的更新


//负环
//加 SLF 优化的话 只能用 1
1.维护路径长度大于 n 有负环
2.入队次数大于 n 有负环


// spfa-dfs 专找负环    inq 要事先初始化
vector<pair<int,int> >gra[700];
int now[700];
bool inq[700];
bool spfa_dfs(int s)
{
    int to,w;
    inq[s]=1;
    for(int i=0;i<gra[s].size();i++)
    {
        to=gra[s][i].first;
        w=gra[s][i].second;
        if(now[to]<now[s]+w)
        {
            now[to]=now[s]+w;
            if(inq[to])return 1;
            else if(spfa_dfs(to))return 1;
        }
    }
    inq[s]=0;
    return 0;
}
