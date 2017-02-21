
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

char s[100] ;
map<string,int> A ;
int T ;

int main()
{
      A["I"] = 1 ;
      A["II"] = 2 ;
      A["III"] = 3 ;
      A["IV"] = 4 ;
      A["V"] = 5 ;
      A["VI"] = 6 ;
      A["VII"] = 7 ;
      A["VIII"] = 8 ;
      A["IX"] = 9 ;
      A["X"] = 10 ;
      A["XI"] = 11 ;
      A["XII"] = 12 ;
      int pos=0 ;
      while (scanf("%s",s) != EOF)
      {
            pos++ ;
            printf("Case %d: %d\n",pos,A[s]);
      }
      return 0 ;
}
