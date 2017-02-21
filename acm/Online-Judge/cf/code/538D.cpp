#include<bits/stdc++.h>
using namespace std;


char maz[60][60];
char ans[200][200];
bool v[60][60];
int main()
{
    //freopen("1.txt","r",stdin);
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%s",maz[i]);
    ans[n-1][n-1]='o';
    for(int i=-n+1;i<n;i++)
        for(int j=-n+1;j<n;j++)
            if(i==0&&j==0)continue;
            else
            {
                int f=1;
                for(int x=0;x<n&&f;x++)
                    for(int y=0;y<n&&f;y++)
                        if(maz[x][y]=='o')
                        {
                            if(x+i>=0&&x+i<n)
                            {
                                if(y+j>=0&&y+j<n)
                                {
                                    if(maz[x+i][y+j]=='.')
                                    {
                                        f=0;
                                        break;
                                    }
                                }
                            }
                        }
                if(f)
                {
                    for(int x=0;x<n;x++)
                        for(int y=0;y<n;y++)
                            if(maz[x][y]=='o')
                            {
                                if(x+i>=0&&x+i<n)
                                {
                                    if(y+j>=0&&y+j<n)
                                    {
                                        v[x+i][y+j]=1;
                                    }
                                }
                            }
                    ans[n-1+i][n-1+j]='x';
                }
                else
                    ans[n-1+i][n-1+j]='.';
            }
    int ff=1;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(maz[i][j]=='x'&&v[i][j]==0)
                ff=0;
    if(ff)
    {
        puts("YES");
        for(int i=0;i<2*n-1;i++)
            puts(ans[i]);
    }
    else
        puts("NO");
    return 0;
}

