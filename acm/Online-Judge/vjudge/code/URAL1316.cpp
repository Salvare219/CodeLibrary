#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

struct bit_tree
{
    int bit[1000050],s;
    inline void updat(int x,int v)
    {
         while(x)bit[x]+=v,x-=x&-x;
    }
    inline int query(int x)
    {
        s=0;
        while(x<1000005)s+=bit[x],x+=x&-x;
        return s;
    }
}b;
inline int In()
{
	int a=0;char c=getchar();
	while(c<'0')c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+c-'0',c=getchar();
	if(c=='.')
    {
        c=getchar();
        a=(a<<3)+(a<<1)+c-'0';
        c=getchar();
        if(c>='0'&&c<='9')return (a<<3)+(a<<1)+c-'0';
        else return (a<<3)+(a<<1);
    }
	else return a*100;
}
inline int Int()
{
	int a=0;char c=getchar();
	while(c<'0')c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+c-'0',c=getchar();
	return a;
}
char s;
inline bool get()
{
    char c=getchar();
    while(c<'A')c=getchar();
    s=c;
    while(c>='A')c=getchar();
    return 1;
}
int main()
{
    long long cnt=0;
    while(get()&&s!='Q')
    {
        int c=In(),d;
        if(s=='B')b.updat(c,1);
        else if(s=='D')b.updat(c,-1);
        else d=Int(),cnt+=min(d,b.query(c));

        //printf("%c %d %d\n",s,c,d);

    }
    printf("%I64d.%02I64d",cnt/100,cnt%100);
    return 0;
}
