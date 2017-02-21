#include<bits/stdc++.h>
using namespace std;


const double pi=acos(-1.0);
inline double cal(int a,int b)
{
    double c1=30.0*a+b/3600.0*30.0,c2=b/3600.0*360.0;
    double ph=c2-c1;
    while(ph<0)ph+=360.0;
    return ph;
}
int a,b;
inline void gao(bool f)
{
    double mn=1e20,x;
    int c=0,bb,cc;
    for(int i=0;i<3928;i++)
    {
        if(f)
            c++;
        else
            c--;
        if(c<0)
            b--,c+=3600;
        if(c>=3600)
            b++,c-=3600;
        if(b<=0)
            b+=12;
        if(b>12)
            b-=12;
        x=cal(b,c);
        if(a)
        {
            if(fabs(x-a)<mn)
                mn=fabs(x-a),bb=b,cc=c;
        }
        else
        {
            if(x<mn)
                mn=x,bb=b,cc=c;
            if(360-x<mn)
                mn=360-x,bb=b,cc=c;
        }
    }
    printf("%d:%.2d:%.2d\n",bb,cc/60,cc%60);
}

int main()
{
    int t,ti=1;scanf("%d",&t);
    while(t--)
    {
        char s[20];
        scanf("%d%s%d",&a,s,&b);
        printf("Case %d: ",ti++);
        gao(s[0]=='a');
    }
    return 0;
}
