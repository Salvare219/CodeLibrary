//期望 O(n)

Point circumcenter(Point a,Point b,Point c)
{
    double a1=b.x-a.x,b1=b.y-a.y,c1 =(a1*a1+b1*b1)/2;
    double a2=c.x-a.x,b2=c.y-a.y,c2 =(a2*a2+b2*b2)/2;
    double d=a1*b2-a2*b1;
    return Point(a.x+(c1*b2-c2*b1)/d,a.y+(a1*c2-a2*c1)/d);
}
void min_circle(Point h[],int n,Point &c,double &r)
{
    int i,j,k;
    r=0.0;c=h[0];
    for(i=1;i<n;i++)
        if(h[i]/c>r)
            for(j=0,c=h[i],r=0.0;j<i;j++)
                if(h[j]/c>r)
                    for(k=0,c=(h[i]+h[j])/2.0,r=h[j]/c;k<j;k++)
                        if(h[k]/c>r)c=circumcenter(h[i],h[j],h[k]),r=h[k]/c;
}
