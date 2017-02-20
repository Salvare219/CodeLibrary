#include<bits/stdc++.h>
#define l push_heap
#define f pop_heap
using namespace std;int a[125005];int main(){int n,k=1,i=0;double m;for(scanf("%d",&n);i<n;i++){scanf("%d",a+k);if(k<=n/2+1)l(a,a+(++k));else if(a[k]<a[0])f(a,a+k),a[k-1]=a[k],l(a,a+k);}n&1?printf("%d.0\n",a[0]):(m=a[0],f(a,a+k),m+=a[0],printf("%.1f\n",m*0.5));}
