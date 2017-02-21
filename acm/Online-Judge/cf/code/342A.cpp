#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
using namespace std;


int a[20];
int main()
{
//    freopen("1.txt","r",stdin);
    int n;
    scanf("%d",&n);
    int temp;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&temp);
        a[temp]++;
    }
    if(a[7] || a[5]) printf("-1\n");
    else
    {
        temp=a[6]-a[3];
        if(temp<0) printf("-1\n");
        else
        {
            temp=a[2]-temp;
            if(temp<0) printf("-1\n");
            else
            {
                if(temp!=a[4]) printf("-1\n");
                else
                {
                    if(a[1]==a[6]+a[4])
                    {
                        n/=3;
                        for(int i=0;i<n;i++)
                        {
                            printf("1 ");
                            if(a[3])
                            {
                                printf("3 6\n");
                                a[3]--;a[6]--;
                            }
                            else
                            {
                                if(a[6])
                                {
                                    printf("2 6\n");
                                    a[2]--;a[6]--;
                                }
                                else
                                {
                                    printf("2 4\n");
                                    a[2]--;a[4]--;
                                }
                            }
                        }
                    }
                    else printf("-1\n");
                }
            }
        }
    }
    return 0;
}

