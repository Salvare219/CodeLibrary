#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x1, y1, x2, y2;
    int x3, y3;
    cin>>x1>>y1>>x2>>y2;
    cin>>x3>>y3;
    if (x1>x2)
        swap(x1, x2);
    if (y1>y2)
        swap(y1, y2);
    if ((x1<=x3&&x3<=x2) && (y1<=y3&&y3<=y2))
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    return 0;
}
