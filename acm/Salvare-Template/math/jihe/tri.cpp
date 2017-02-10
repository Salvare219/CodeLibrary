//外心
Point Circumcenter(Point a,Point b,Point c)
{  
    double a1 = b.x - a.x, b1 = b.y - a.y, c1 = (a1*a1 + b1*b1)/2;  
    double a2 = c.x - a.x, b2 = c.y - a.y, c2 = (a2*a2 + b2*b2)/2;  
    double d = a1 * b2 - a2 * b1;  
    return Point(a.x + (c1*b2 - c2*b1)/d,a.y + (a1*c2 - a2*c1)/d);  
}

//垂心
Point Orthocenter(Point p0,Point p1,Point p2)
{  
    double a1,b1,a2,b2,c1,c2;  
    a1 = p2.x-p1.x; b1=p2.y-p1.y;c1 = 0;  
    a2 = p2.x-p0.x; b2=p2.y-p0.y;c2 = (p1.x-p0.x)*a2+(p1.y-p0.y)*b2;  
    double d = a1 * b2 - a2 * b1;  
    return Point(p0.x+(c1*b2-c2*b1)/d,p0.y+(a1*c2-a2*c1)/d);  
}

//重心
//到三角形三顶点距离的平方和最小的点
//三角形内到三边距离之积最大的点
Point Barycenter(Point a,Point b,Point c)
{
	return (a+b+c)/3;
}

//内心
Point Incenter(Point p1,Point p2,Point p3)
{
    double a=dis(p2,p3),b=dis(p1,p3),c=dis(p1,p2);
    return Point((a*p1.x+b*p2.x+c*p3.x)/(a+b+c),(a*p1.y+b*p2.y+c*p3.y)/(a+b+c));
}