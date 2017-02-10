int n2(int a)
{return a*(a+1)*(2*a+1)/6;}
int n3(int a)
{return a*a*(a+1)*(a+1)/4;}
int n4(int a)
{return a*(a+1)*(2*a+1)*(3*a*a+3*a-1)/30;}

Fn=( √ 5/5)*{[(1+ √ 5)/2]^n - [(1- √ 5)/2]^n}

C[n+1]=2*a*C[n]-(a*a-b)*C[n-1]
C[n]=(a+sqrt(b))^n+(a-sqrt(b))^n

//欧拉常数  0.57721566490153286060651209
//
//PICK公式：S=I+E/2-1  S,面积，I多边形的内坐标点的个数，E多边形的边上坐标点的个数。
//
//
//欧拉公式
//简单多面体的顶点数V、面数F及棱数E间有关系
//V+F-E=2
//
//错排
//Dn=(n-1）[D(n-2）+D(n-1）] 
//Dn=[n!/e+0.5] 
//
//n^k+(n-1)^k+....+2^k+1^k 通项系数
//S(n, 1) = (1 + ... + n) = (1/2) * n2 + (1/2) * n 
//S(n, 2) = (1 + ... + n2) = (1/3) * n3 + (1/2) * n2 + (1/6) * n 
//S(n, 3) = (1 +...+ n3) = (1/4) * n4 + (1/2) * n3) + (1/4) * n2 
//S(n, 4) = (1 +...+ n4) = (1/5) * n5 + (1/2) * n4) + (1/3) * n3 - (1/30) * n 
//
//系数
//1        
//1/2  1/2       
//1/6  1/2  1/3      
//0  1/4  1/2  1/4     
//-1/30  0  1/3  1/2  1/5    
//0  -1/12  0  5/12  1/2  1/6   
//1/42  0  -1/6  0  1/2  1/2  1/7  
 

struct p
{
    long long x,y;
    bool an;
}s[555][555];
long long pp;
int gcd(long long a,long long b)
{
    pp=a%b;
    while(pp)
    {
        a=b;b=pp;
        pp=a%b;
    }
    return b;
}
p f(int a,int b)
{
    if(s[a][b].an) return s[a][b];
    long long y;
    if(b)
	{
		s[a][b]=f(a-1,b-1);
		s[a][b].x*=a;s[a][b].y*=b+1;
	}
    else
    {
        p temp,c;
        temp.x=0;temp.y=1;
        for(int i=1;i<=a;i++)
        {
            c=f(a,i);
			if(temp.x*c.y+c.x*temp.y!=0)
			{
				y=gcd(temp.y*c.y,temp.x*c.y+c.x*temp.y);
				temp.x=(temp.x*c.y+c.x*temp.y)/y;
				temp.y=temp.y*c.y/y;
			}
        }
        s[a][b].x=temp.y-temp.x;
        s[a][b].y=temp.y;
    }
    y=gcd(s[a][b].x,s[a][b].y);
    s[a][b].x=s[a][b].x/y;
    s[a][b].y=s[a][b].y/y;
    s[a][b].an=1;
    if(s[a][b].y<0) s[a][b].y=-s[a][b].y,s[a][b].x=-s[a][b].x;
    return s[a][b];
}