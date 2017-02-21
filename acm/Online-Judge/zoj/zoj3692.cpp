#include <cstdio>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

int n,m;
int gs[40005];
int gf[40005];
int rp[40005];
int dp[40005];
multiset<int> s;

void pop_back(deque<int>& u){
    if(u.size()>1) s.erase(s.find(dp[u[u.size()-2]+1]+rp[u.back()]));
    u.pop_back();
}

void pop_front(deque<int>& u){
    if(u.size()>1) s.erase(s.find(dp[u.front()+1]+rp[u[1]]));
    u.pop_front();
}

bool gao(int top){
    s.clear();
    deque<int> u;
    for(int i=0,j=0;i<n;i++){
        while(gs[i+1]-gs[j]>top) j++;
        while(u.size() && u.front()<j) pop_front(u);
        while(u.size() && rp[u.back()]<=rp[i]) pop_back(u);
        u.push_back(i);
        if(u.size()>1) s.insert(dp[u[u.size()-2]+1]+rp[u.back()]);
        dp[i+1]=rp[u.front()]+dp[j];
        if(s.size()) dp[i+1]=min(*s.begin(),dp[i+1]);
    }
    return dp[n]<=m;
}

int main(){
    while(scanf("%d%d",&n,&m)==2){
        for(int i=0;i<n;i++){
            scanf("%d%d",rp+i,gf+i);
            gs[i+1]=gs[i]+gf[i];
        }
        int lo=*max_element(gf,gf+n),hi=gs[n];
        while(lo<hi){
            int x=(lo+hi)/2;
            if(gao(x)) hi=x; else lo=x+1;
        }
        printf("%d\n",lo);
    }
}