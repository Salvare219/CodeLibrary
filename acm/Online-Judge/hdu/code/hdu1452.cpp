#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<iostream>
#include<map>
using namespace std;


int num[]={6,16,8,10,25,7,14,3,23,17,13,17,0,27,7,14,15,17,26,26,20,17,9,22,22,23,0,1};
int main()
{
    int n;
    while(scanf("%d",&n))
    {
        if(n==0) break;
        printf("%d\n",num[(n-1)%28]);
    }
    return 0;
}