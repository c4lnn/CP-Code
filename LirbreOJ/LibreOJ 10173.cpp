#include <bits/stdc++.h>
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define FI first
#define SE second
using namespace std;
typedef double DB;
typedef long double LD;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
//head
const int N=105;
int n,m,dp[N][N*10][N*10],tot[N*10],st[N*10];
set<int> s;
void dfs(int pos,int t,int d) {
    s.insert(t);
    tot[t]=d;
    for(int i=pos+3;i<m;i++) dfs(i,t|(1<<i),d+1);
}
bool check(int i,int j,int a,int b) {
    if(j<=0) return true;
    if(a&st[i]||b&st[j]||a&b) return false;
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=0;j<m;j++) {
            char c;
            cin>>c;
            if(c=='H') st[i]|=1<<j;
    }
    dfs(-3,0,0);
    for(int i=1;i<=n;i++)
        for(auto x:s)
            for(auto y:s) {
                if(!check(i,i-1,x,y)) continue;
                for(auto z:s)
                    if(check(i,i-2,x,z)&&check(i-1,i-2,y,z))
                        dp[i][x][y]=max(dp[i][x][y],dp[i-1][y][z]+tot[x]);
            }
    int res=0;
    for(auto x:s)
        for(auto y:s)
            res=max(res,dp[n][x][y]);
    cout<<res<<'\n';
    return 0;
}