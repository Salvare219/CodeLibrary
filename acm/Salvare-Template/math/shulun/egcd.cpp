void e_gcd(int a,int b,int &x,int &y)
{
	if(b==0)x=1,y=0;
	else e_gcd(b,a%b,y,x),y-=a/b*x;
}

