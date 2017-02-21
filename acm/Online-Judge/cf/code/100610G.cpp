#include<bits/stdc++.h>
using namespace std;


vector<int>pos[10050];
pair<double,pair<int,int> >ki[200050];
double lis[10050];
vector<double>fin;
pair<double,double>cal(double A,double B,double C,double l,double r)
{
    double f=-B/(2*A);
    if(f<=l)f=l;
    if(f>=r)f=r;
    return make_pair(A*f*f+B*f+C,f);
}
int sgn(double x)
{
    return fabs(x)<1e-4?0:(x>0.0?1:-1);
}
int main()
{
    //freopen("1.txt","r",stdin);
    freopen("gadgets.in","r",stdin);
    freopen("gadgets.out","w",stdout);
    int n,m;scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        pos[y-1].push_back(x);
    }
    int f=0;
    for(int i=0;i<n;i++)
    {
        sort(pos[i].begin(),pos[i].end());
        double las=-10e6;
        for(int j=0;j<pos[i].size();j++)
            ki[f++]=make_pair((las+pos[i][j])*0.5,make_pair(pos[i][j],i)),las=pos[i][j];
        ki[f++]=make_pair((las+10e6)*0.5,make_pair(10e6,i));
    }
    sort(ki,ki+f);
    double A=n,B=0.0,C=0.0,ans=1e20;
    for(int i=0;i<f-1;i++)
    {
        int col=ki[i].second.second;
        double we=ki[i].second.first;
        B+=2.0*lis[col];
        C-=lis[col]*lis[col];
        lis[col]=we;
        B-=2.0*lis[col];
        C+=lis[col]*lis[col];
        if(i>=n-1)
        {
            pair<double,double>hh=cal(A,B,C,ki[i].first,ki[i+1].first);
            double sum=hh.first,z=hh.second;
            if(sgn(ans-sum)>=0)
            {
                if(sgn(ans-sum)>0)fin.clear();
                ans=sum;
                if(fin.size()==0||sgn(z-fin[fin.size()-1])>0)fin.push_back(z);
            }
        }
    }
    printf("%d\n",(int)fin.size());
    for(int i=0;i<fin.size();i++)
        printf("%8f\n",fin[i]);
    return 0;
}
