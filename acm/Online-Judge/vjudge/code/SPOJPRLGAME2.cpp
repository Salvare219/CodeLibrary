
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <ctime>
#include <string>
#include <cstring>

using namespace std;


#define INFINITE 0x3f3f3f3f
#define MAX(a,b)((a)>(b)?(a):(b))
#define MIN(a,b)((a)<(b)?(a):(b))
#define MAXK 110
#define MAXN 10010
#define Mod 1000000007
int main()
{
      int n , p , q , pos = 0 ;
      while (scanf("%d%d%d",&n,&p,&q) != EOF)
      {
            pos++ ;
            printf("Case %d: %.4lf\n",pos,double(q+1)/(p+2));
      }
      return 0 ;
}
