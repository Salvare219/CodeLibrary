#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
using namespace std;

#include<tr1/unordered_set>
using namespace tr1;

struct Point
{
    long long x,y;
    Point(double a=0.0,long long b=0.0){x=a;y=b;}
    Point operator+(const Point&a)const{return Point(x+a.x,y+a.y);}
    Point operator-(const Point&a)const{return Point(x-a.x,y-a.y);}
    Point operator*(const double&a)const{return Point(x*a,y*a);}
    Point operator/(const double&a)const{return Point(x/a,y/a);}
    long long operator*(const Point&a)const{return x*a.y-y*a.x;}
    long long operator/(const Point&a)const{return sqrt((a.x-x)*(a.x-x)+(a.y-y)*(a.y-y));}
    long long operator%(const Point&a)const{return x*a.x+y*a.y;}

    bool operator<(const Point&a)const
    {
        return x!=a.x?x<a.x:y<a.y;
    }
    bool operator==(const Point&a)const
    {
        return x==a.x&&y==a.y;
    }
}po[500];
unordered_set<unsigned long long>st;
unsigned long long sd=13131;
unsigned long long wa[500];
int main()
{
    freopen("cottages.in","r",stdin);
    freopen("cottages.out","w",stdout);
    //freopen("1.txt","r",stdin);
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%I64d%I64d",&po[i].x,&po[i].y);

    sort(po,po+n);
    n=unique(po,po+n)-po;

    wa[0]=1;
    unsigned long long tot=1;
    for(int i=1;i<n;i++)
    {
        wa[i]=wa[i-1]*sd;
        tot+=wa[i];
    }
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
        {
            Point dir=po[j]-po[i];
            bool sa=1;
            for(int z=0;z<n;z++)
                if(z!=i&&z!=j)
                {
                    if(dir*(po[z]-po[i])==0&&(po[i]-po[z])%(po[j]-po[z])<0)
                    {
                        sa=0;
                        break;
                    }
                }
            if(sa)
            {
                long long s1=0,s2=0,s3=0,s4=0,sum;
                for(int z=0;z<n;z++)
                    if(i!=z&&j!=z)
                    {
                        long long f1=(po[z]-po[i])*dir;
                        if(f1>0)
                            s1+=wa[z];
                        else if(f1<0)
                            s2+=wa[z];
                        else
                        {
                            if((po[z]-po[i])%dir>0)
                                s3+=wa[z];
                            else
                                s4+=wa[z];
                        }
                    }
                s3+=wa[j];
                s4+=wa[i];

                sum=s1+s4+s3;  //1
                st.insert(sum);
                st.insert(tot-sum);

                sum=s1+s4;     //2
                st.insert(sum);
                st.insert(tot-sum);

                sum=s1+s3;     //3
                st.insert(sum);
                st.insert(tot-sum);

                sum=s1;  //4
                st.insert(sum);
                st.insert(tot-sum);
            }
        }
    st.insert(tot);
    st.insert(0);
    printf("%d\n",(int)st.size()-2);
    return 0;
}
