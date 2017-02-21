#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<algorithm>
#include<cmath>
#include<queue>
#include<stack>
using namespace std;
#define M 300010
#define inf 1<<30
#define ll long long
#define eps 1e-7
#define bas 9
#define mod 1000000000LL

int sum[M];
int bit[21];
int N, n, m;
void add( int i, int x )
{
    while( i <= N ){
        sum[i] += x;
        i += i&-i;
    }
}
int query( int i )
{
    int ans = 0;
    while( i ){
        ans += sum[i];
        i -= i&-i;
    }
    return ans;
}

char op[100010][6];
int a[100010];
int uni[M], cnt;
int lisan[M], num[M], e, ma;
int peo[M], pos[M];

int find( int k )
{
    int ans = 0, pos = 0;
    for( int i = 20; i >= 0; --i ){
        pos += bit[i];
        if( pos > N || ans + sum[pos] >= k ) pos -= bit[i];
        else ans += sum[pos];
    }
    return pos+1;
}

int main()
{
    int T, t = 0;
    bit[0] = 1;
    for( int i = 1; i < 21; ++i ) bit[i] = bit[i-1]<<1;
    scanf( "%d", &T );
    while( T-- ){
        scanf( "%d%d", &n, &m );
        for( int i = 0; i < m; ++i )
            scanf( "%s%d", op[i], &a[i] );
        ma = cnt = 0;
        for( int i = 0; i < m; ++i )
            if(op[i][0]=='T'||op[i][0]=='Q')
                uni[cnt++] = a[i];
            else ma = max( ma, a[i] );
        printf( "Case %d:\n", ++t );
        sort( uni, uni+cnt );
        if( ma > uni[cnt-1] ) uni[cnt++] = ma;
        cnt = unique( uni, uni+cnt ) - uni;
        e = 0;
        if( uni[0] != 1 )
            lisan[e] = 1, num[e++] = uni[0] - 1;
        lisan[e] = uni[0], num[e++] =  1;
        for( int i = 1; i < cnt; ++i ){
            if( uni[i] - uni[i-1] > 1 )
                lisan[e] = uni[i-1]+1, num[e++] = uni[i]-uni[i-1]-1;
            lisan[e] = uni[i], num[e++] = 1;
        }
        N = e+m+3;
        memset( sum, 0, sizeof(sum) );
        int top = m;
        for( int i = 0; i < e; ++i ){
            add( top+i+1, num[i] );
            pos[i] = top+i+1;
            peo[top+i+1] = i;
        }
        for( int i = 0; i < m; ++i ){
            if( op[i][0] == 'T' ){
                int x = lower_bound( lisan, lisan+e, a[i] ) - lisan;
                add( pos[x], -1 );
                add( top, 1 );
                peo[top] = peo[pos[x]];
                pos[x] = top--;
            }
            else if( op[i][0] == 'Q' ){
                int x = lower_bound( lisan, lisan+e, a[i] ) - lisan;
                printf( "%d\n", query( pos[x] ) );
            }
            else{
                int p = find( a[i] );
                int s = query( p );
                int k = peo[p];
                printf( "%d\n", lisan[k]+num[k]-s+a[i]-1 );
            }
        }
    }
}