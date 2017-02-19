#include<bits/stdc++.h>
using namespace std;


char s[55][55];
int dx[]={1,1,1,0,-1,-1,-1,0};
int dy[]={-1,0,1,1,1,0,-1,-1};
bool check(int x,int y)
{
    for(int i=0;i<8;i++)
    {
        int x1=x+dx[i],y1=y+dy[i];
        int x2=x1+dx[i],y2=y1+dy[i];
        int x3=x-dx[i],y3=y-dy[i];
        if(s[x1][y1]=='x'&&s[x2][y2]=='x')
            return 1;
        if(s[x1][y1]=='x'&&s[x3][y3]=='x')
            return 1;
    }
    return 0;
}
int main()
{
    for(int i=2;i<=5;i++)
        scanf("%s",s[i]+2);
    for(int i=2;i<=5;i++)
        for(int j=2;j<=5;j++)
            if(s[i][j]=='.')
            {
                if(check(i,j))
                {
                    puts("YES");
                    return 0;
                }
            }
    puts("NO");
	return 0;
}
