#include<bits/stdc++.h>
using namespace std;


struct Rec
{
    Rec(){}
    Rec(int _x,int _y,int _x1,int _y1){x=_x;y=_y;x1=_x1;y1=_y1;}
    int x,y,x1,y1;
}A[8],C[8];
int xx[5],yy[5];
int xc[5],yc[5];
pair<long long,long long>cc(int l,int r,int l1,int r1)
{
    if(max(l,l1)>min(r,r1))return make_pair(0,0);
    else return make_pair(max(l,l1),min(r,r1));
}
long long cross(const Rec a,const Rec b)
{
    pair<long long,long long> l=cc(a.x,a.x1,b.x,b.x1),r=cc(a.y,a.y1,b.y,b.y1);
    return (l.second-l.first)*(r.second-r.first);
}
Rec cho(const Rec c[],int i)
{
    Rec z1;
    if(i==0)z1=Rec(c[0].x,c[0].y,c[1].x,c[0].y1);
    else if(i==1)z1=Rec(c[1].x,c[0].y,c[1].x1,c[1].y);
    else if(i==2)z1=Rec(c[1].x1,c[0].y,c[0].x1,c[0].y1);
    else z1=Rec(c[1].x,c[1].y1,c[1].x1,c[0].y1);
    return z1;
}
long long cal(const Rec c[],const Rec d[])
{
    long long ans=0;
    Rec z1,z2;
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
        {
            z1=cho(c,i);
            z2=cho(d,j);
            ans+=cross(z1,z2);
        }
    return ans;
}
int main()
{
    //freopen("1.txt","r",stdin);
    freopen("frames.in","r",stdin);
    freopen("frames.out","w",stdout);
    for(int i=0;i<4;i++)
    {
        int x,y,x1,y1;
        scanf("%d%d%d%d",&x,&y,&x1,&y1);
        A[i].x=min(x,x1);
        A[i].y=min(y,y1);
        A[i].x1=max(x,x1);
        A[i].y1=max(y,y1);
        if(i==0)xx[0]=x,xx[1]=x1,yy[0]=y,yy[1]=y1;
        if(i==1)xx[2]=x,xx[3]=x1,yy[2]=y,yy[3]=y1;
        if(i==2)xc[0]=x,xc[1]=x1,yc[0]=y,yc[1]=y1;
        if(i==3)xc[2]=x,xc[3]=x1,yc[2]=y,yc[3]=y1;
    }
    sort(xx,xx+4);sort(xc,xc+4);
    sort(yy,yy+4);sort(yc,yc+4);
    int a1,a2;
    long long ans=0;
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            for(int k=0;k<4;k++)
                for(int z=0;z<4;z++)
                {
                    int dx=xx[i]-xc[j],dy=yy[k]-yc[z];
                    for(int f=0;f<2;f++)
                    {
                        C[f].x=A[f+2].x+dx;
                        C[f].y=A[f+2].y+dy;
                        C[f].x1=A[f+2].x1+dx;
                        C[f].y1=A[f+2].y1+dy;
                    }
                    long long f=cal(A,C);
                    if(ans<f)
                    {
                        ans=f;
                        a1=dx;
                        a2=dy;
                    }
                }
    printf("%I64d\n%d %d\n",ans,a1,a2);
    return 0;
}
