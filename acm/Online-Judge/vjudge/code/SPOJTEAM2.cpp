#include <cstdio>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <ctime>
#include <map>
#include <string>
#include <cstring>

using namespace std;


#define INFINITE 0x3f3f3f3f
#define MAX(a,b)((a)>(b)?(a):(b))
#define MIN(a,b)((a)<(b)?(a):(b))

int A[5] ;

int main()
{
      int a , b , c , d , pos = 0;
      while (scanf("%d%d%d%d",&a,&b,&c,&d)!=EOF)
      {
            pos++ ;
            A[1] = a ; A[2] = b ; A[3] = c ; A[4] = d ;
            sort(A+1,A+5);
            printf("Case %d: %d\n",pos,A[3]+A[4]);
      }
      return 0;
}
