#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <cmath>
#include <queue>
#include <map>
using namespace std;
char s[20];
bool cmp(int a, int b)
{
	cout<<1<<' '<<a<<' '<<b<<endl;
   	cout.flush();
	cin>>s;
	return s[0]=='Y';
}
int main()
{
    int a[1010],n;
	while(scanf("%d",&n)==1)
	{
		for(int i=1;i<=n;i++) a[i]=i;
		stable_sort(a+1,a+1+n,cmp);
		cout<<0;
		for(int i=1;i<=n;i++) cout<<' '<<a[i];
		cout<<endl;
	}
	return 0;
}
