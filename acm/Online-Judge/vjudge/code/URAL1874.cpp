#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;


int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	printf("%lf\n",(double)(a*a+b*b)/4+sqrt(2.0)*(double)a*b/2);
	return 0;
}