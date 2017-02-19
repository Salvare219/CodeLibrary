#include<bits/stdc++.h>
using namespace std;


char s[20][20];
int cnt[500];
char mf[20];
int a[20];
vector<string>ans;
int pos[7][7]={
{1,2,3,4,5},
{2,6,3,1,5},
{3,2,6,4,1},
{4,3,6,5,1},
{5,4,6,2,1},
{6,2,5,4,3}};
bool v[9];
bool ok(char s[],char f[])
{
    sort(s+1,s+5);
    sort(f+1,f+5);
    string x1=s,x2=f;
    return x1==x2;
}
bool check()
{
    memset(v,0,sizeof(v));
    for(int i=0;i<6;i++)
    {
        char f[8];
        for(int j=0;j<5;j++)
            f[j]=mf[pos[i][j]-1];
        f[5]=0;
        for(int j=0;j<6;j++)
            if(v[j]==0&&ok(f,s[j]))
            {
                v[j]=1;
                break;
            }
    }
    int ans=0;
    for(int i=0;i<6;i++)
        ans+=v[i];
    return ans==6;
}
bool ok2(string s1,string s2)
{
    if(s1[0]!=s2[0])return 0;
    for(int i=0;i<4;i++)
    {
        int f=1;
        for(int j=0;j<4;j++)
            if(s1[j+1]!=s2[(i+j)%4+1])
            {
                f=0;
                break;
            }
        if(f)return 1;
    }
    for(int i=0;i<4;i++)
    {
        int f=1;
        for(int j=0;j<4;j++)
            if(s1[j+1]!=s2[(i-j+4)%4+1])
            {
                f=0;
                break;
            }
        if(f)return 1;
    }
    return 0;
}

/*
bool same(string s1,string s2)
{
    string c3[8];
    for(int i=0;i<6;i++)
    {
        char f[8];
        for(int j=0;j<5;j++)
            f[j]=s1[pos[i][j]-1];
        f[5]=0;
        c3[i]=f;
    }
    string c4[8];
    for(int i=0;i<6;i++)
    {
        char f[8];
        for(int j=0;j<5;j++)
            f[j]=s2[pos[i][j]-1];
        f[5]=0;
        c4[i]=f;
    }
    memset(v,0,sizeof(v));
    for(int i=0;i<6;i++)
        for(int j=0;j<6;j++)
            if(v[j]==0&&ok2(c3[i],c4[j]))
            {
                v[j]=1;
                break;
            }
    int ans=0;
    for(int i=0;i<6;i++)
        ans+=v[i];
    return ans==6;
}*/





char A[7], B[7], C[7];

int ps[7];

bool pd() {
    for(int i = 1; i <= 6; i++) if(A[i] != C[i]) return false;
    return true;
}

int shu[4][7], heng[4][7], lie[4][7];

void init() {
    for(int i = 1; i <= 7; i++) shu[0][i] = i, heng[0][i] = i, lie[0][i] = i;

    shu[1][1] = 3; shu[1][2] = 2; shu[1][3] = 6; shu[1][4] = 4; shu[1][5] = 1; shu[1][6] = 5;
    shu[2][1] = 6; shu[2][2] = 2; shu[2][3] = 5; shu[2][4] = 4; shu[2][5] = 3; shu[2][6] = 1;
    shu[3][1] = 5; shu[3][2] = 2; shu[3][3] = 1; shu[3][4] = 4; shu[3][5] = 6; shu[3][6] = 3;

    heng[1][1] = 1; heng[1][2] = 3; heng[1][3] = 4; heng[1][4] = 5; heng[1][5] = 2; heng[1][6] = 6;
    heng[2][1] = 1; heng[2][2] = 4; heng[2][3] = 5; heng[2][4] = 2; heng[2][5] = 3; heng[2][6] = 6;
    heng[3][1] = 1; heng[3][2] = 5; heng[3][3] = 2; heng[3][4] = 3; heng[3][5] = 4; heng[3][6] = 6;

    lie[1][1] = 2; lie[1][2] = 6; lie[1][3] = 3; lie[1][4] = 1; lie[1][5] = 5; lie[1][6] = 4;
    lie[2][1] = 6; lie[2][2] = 4; lie[2][3] = 3; lie[2][4] = 2; lie[2][5] = 5; lie[2][6] = 1;
    lie[3][1] = 4; lie[3][2] = 1; lie[3][3] = 3; lie[3][4] = 6; lie[3][5] = 5; lie[3][6] = 2;
}

bool same() {
    for(int i = 0; i < 4; i++) {
        for(int p = 1; p < 7; p++) ps[p] = shu[i][p];

        for(int j = 0; j < 4; j++) {
            for(int p = 1; p < 7; p++) ps[p] = heng[j][ps[p]];

            for(int k = 0; k < 4; k++) {
                for(int p = 1; p < 7; p++) ps[p] = lie[k][ps[p]];

                for(int p = 1; p < 7; p++) {
                    C[ps[p]] = B[p];
                }   
                if(pd()) return true;
            }
        }
    }
    return false;
}




char jk[55];
int main()
{
    //freopen("pro.in","r",stdin);

    
    freopen("cube.in","r",stdin);
    freopen("cube.out","w",stdout);

    init();
    for(int i=0;i<6;i++)
        cin>>s[i];
    for(int i=0;i<6;i++)jk[i]=s[i][0],a[i]=i;
    do
    {
        for(int i=0;i<6;i++)mf[i]=jk[a[i]];
        mf[6]=0;
        if(check())
        {
            string c=mf;
            if(ans.size()==0)
            {
                ans.push_back(c);
            }
            else
            {
                for(int i = 1; i < 7; i++) A[i] = ans[0][i- 1];
                for(int i = 1; i < 7; i++) B[i] = c[i - 1];

                if(!same() && c != ans[0])
                {
                    ans.push_back(c);
                    break;
                }
            }
        }
    }while(next_permutation(a,a+6));
    if(ans.size()==0)cout<<"Impossible"<<endl;
    else
    {
        for(int i=0;i<ans.size();i++)
            cout<<ans[i]<<endl;
    }
    return 0;
}