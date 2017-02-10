//get_next

//优化(最好不用)
int i=0,j=-1;
fail[0]=-1;
while(ori[i])
{
    while(j!=-1 && ori[i]!=ori[j]) j=fail[j];
    i++;j++;
    if(ori[j]==ori[i]) fail[i]=fail[j];
    else fail[i]=j;
}

//未优化
int i=0,j=-1;
fail[0]=-1;
while(str[i])
{
    while(j!=-1 && str[i]!=str[j]) j=fail[j];
    i++;j++;
    fail[i]=j;
}


//kmp

i=0;j=0;
while(str[i])
{
    while(j!=-1 && str[i]!=ori[j] ) j=fail[j];
    i++;j++;
    if(ori[j]==0) ans++;
}

//EX-kmp  QAQ

char str[200005],ori[200005];
int fail[200005],extend[200005];
void extend_kmp()
{
    int i,j=-1,l,r;
    for(i=1;ori[i];i++,j--)
    {
        if(j<0 || i+fail[i-l]>=r)
        {
            if(j<0) j=0,r=i;
            while(ori[r] && ori[j]==ori[r]) r++,j++;
            fail[i]=j;l=i;
        }
        else fail[i]=fail[i-l];
    }
    nex[0]=i;j=-1;
    for(i=0;str[i];i++,j--)
    {
        if(j<0 || i+fail[i-l]>=r)
        {
            if(j<0) j=0,r=i;
            while(str[r] && ori[j] && ori[j]==str[r]) r++,j++;
            extend[i]=j;l=i;
        }
        else extend[i]=fail[i-l];
    }
}


