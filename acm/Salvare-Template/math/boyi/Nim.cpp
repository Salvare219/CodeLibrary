//快速 sg[a][b]=mex{sg[x][y]^sg[a][y]^sg[x][b]|x<a,y<b}


int m[4][4]={0,0,0,0,0,1,2,3,0,2,3,1,0,3,1,2};
int nim_multy_pow(int x,int y)
{
    if(x<4) return m[x][y];
    int m=1;
    while((1<<m)<=x) m<<=1;
    m=1<<(m>>1);
    int d=nim_multy_pow(x/m,y/m);
    return (m*(d^nim_multy_pow(x/m,y%m)))^nim_multy_pow(m>>1,d);
}
int nim_multy(int x,int y)
{
    if(x<y) swap(x,y);
    if(x<4) return m[x][y];
    int m=1;
    while((1<<m)<=x) m<<=1;
    m=1<<(m>>1);
    int c=nim_multy(x/m,y/m);
    return m*(c^nim_multy(x/m,y%m)^nim_multy(x%m,y/m))^nim_multy(x%m,y%m)^nim_multy_pow(m>>1,c);
}