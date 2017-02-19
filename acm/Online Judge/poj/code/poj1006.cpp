#include<iostream>
using namespace std;
int main()
{
    int a,b,c,d;
    int n(0);
    while(cin>>a>>b>>c>>d)
    {
        n++;
        if(a==-1&&b==-1&&c==-1&&d==-1)break;
        int i;
        i=(5544*a+14421*b+1288*c-d)%(23*28*33);
        if(i<=0)cout<<"Case "<<n<<": the next triple peak occurs in "<<21252-d<<" days.\n";
        else cout<<"Case "<<n<<": the next triple peak occurs in "<<i<<" days.\n";
    }
    return 0;
}
