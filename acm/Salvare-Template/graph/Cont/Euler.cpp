
void eur(int s,int p)
{
    for(int i=0;i<gra[s].size();i++)
        if(v[gra[s][i].second]==0)
        {
            v[gra[s][i].second]=1;
            eur(gra[s][i].first,gra[s][i].second);
        }
    ans[h++]=p;
}